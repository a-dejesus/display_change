7/14/2024
    - fixed info ouput for EnumDisplayDevices, EnumDisplaySettingsEx
        - screenshot in /status/7-14-2024
    - added status directory to keep track of progress, backlog, proof screenshots
    - seems like prompting admin is not needed but I want to keep the code for future reference, removed directory and added to .gitignore and removed compile task from makefile

Next Task
    - experiment with changedisplaysettings, add single click functionallity
    - add doxygen comments

7/16/2024
    - added class structure to make display changing portable for other projects
    - added doxygen comments
    
7/18/2024
    - added state machine, function to return status for display 3
    - the display numbers can be rearranged, going to base decisions off of what is turned on, identify monitors by screen resolution width since they all differ 