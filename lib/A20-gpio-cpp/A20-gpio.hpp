#ifndef A20_GPIO_HPP
#define A20_GPIO_HPP

#include <vector>
#include <stdexcept>
#include <string>

#if __cplusplus > 199711L
	#include <cstdint>
#else
	#ifndef uint16_t
		typedef unsigned short uint16_t;
	#endif
#endif


namespace A20 {

	typedef enum {
		NONE      =0,
		PULL_UP   =1,
		PULL_DOWN =2
	} pull_resistor_t;

	class GPIO;
	
	class GPIO_exception : public std::runtime_error {
		public:
			GPIO_exception(std::string s) : runtime_error(std::string("GPIO exception: ")+s) {};
	};

	
	class GPIO_common {
		public:
			virtual uint16_t get_type() const = 0;	// 0 - input, 1 - output, 2 - per
			virtual uint16_t get_port() const = 0;
	};
	
	class GPIO_input : GPIO_common {
		friend class GPIO;
		public:
			uint16_t get_type() const { return 0; }
			uint16_t get_port() const { return port; }
			bool get() const;
		private:
			GPIO_input(uint16_t port, pull_resistor_t pull_resistor);
			uint16_t port;
	};
	
	class GPIO_output : GPIO_common {
		friend class GPIO;
		public:
			uint16_t get_type() const { return 1; }
			uint16_t get_port() const { return port; }
			void set(bool) const;
		private:
			GPIO_output(uint16_t port);
			~GPIO_output();
			uint16_t port;
	};
	
	class GPIO_periphery : GPIO_common {
	    friend class GPIO;
		public:
			uint16_t get_type() const { return 2; }
			uint16_t get_port() const { return port; }
		private:
			GPIO_periphery(uint16_t port);
			~GPIO_periphery();
			uint16_t port;
	};


	class GPIO {
		public:
			static void 	   init();
			static GPIO_input  *get_input(uint16_t port, pull_resistor_t pull_resistor=NONE) throw(GPIO_exception);
			static GPIO_output *get_output(uint16_t port) throw(GPIO_exception);
			static void        set_periphery_mode(uint16_t port) throw(GPIO_exception);
			static void        free(uint16_t port) throw(GPIO_exception);
		private:
			GPIO();		// You cannot instantiate this object
	
			static std::vector<GPIO_common*> registered;
	
	};



}

#endif