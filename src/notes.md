MICROSOFT API 
    https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-enumdisplaydevicesa
    make DISPLAY_DEVICE variable , initialize cb to size of DISPLAY_DEVICE, choose which deviceIndex to inquire

DISPLAY DEVICE STRUCT 
    CHAR  DeviceName[32];
    CHAR  DeviceString[128];
    DWORD StateFlags;
    CHAR  DeviceID[128];
    CHAR  DeviceKey[128];

DEVMODE DEVICE STRUCT 
    https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-devmodea
    Fields of intrest for this project 

        dmBitsPerPel
        dmPelsWidth
        dmPelsHeight
        dmDisplayFlags
        dmDisplayFrequency
        dmPosition
        dmDisplayOrientation

Make the project work without setting the amount of displays 
    To detect how many monitors a system has, you can call EnumDisplayDevices in a loop until it fails, then use the last value to succeed to avoid having to do it manually 

Change Display Settings Function
    https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-changedisplaysettingsexa