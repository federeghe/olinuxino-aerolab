#ifndef GUI_SETTINGSTAB_H
#define GUI_SETTINGSTAB_H

#include <QTabWidget>

/*! This abstract class represents a tab in the settings dialog.
 *
 */
class SettingsTab : public QWidget {

public:
    
    SettingsTab() : QWidget(0)   // We do not know what my parent is, 
                                 // so call super costructor with 0 
    {}
    
    // Very important, we need to let delete children of this class,
    // so declare the virtual destructor
    virtual ~SettingsTab(){}

    /*! This method is called when the user press "save" button */
    virtual void save_settings()          = 0;  

    /*! This method is called when the user press "reset" button 
     *  or when the dialog is open, NOT ONLY on first time */
    virtual void restore_settings()       = 0;  

    /*! This method returns the name for the tab */
    virtual const char* get_name() const  = 0; 

};

#endif