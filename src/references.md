EnumDisplayDevices Function 
    https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-enumdisplaydevicesa
    make DISPLAY_DEVICE variable , initialize cb to size of DISPLAY_DEVICE, choose which deviceIndex to inquire

DISPLAY DEVICE STRUCT 
    https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-display_devicea
    CHAR  DeviceName[32];
    CHAR  DeviceString[128];
    DWORD StateFlags;
    CHAR  DeviceID[128];
    CHAR  DeviceKey[128];

DEVMODE DEVICE STRUCT 
    https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-devmodea 
        dmBitsPerPel
        dmPelsWidth
        dmPelsHeight
        dmDisplayFlags
        dmDisplayFrequency
        dmPosition
        dmDisplayOrientation

EnumDisplaySettingsEx
    https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-enumdisplaysettingsexa

Change Display Settings Function
    https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-changedisplaysettingsexa
    Function parameters
    LONG ChangeDisplaySettingsExA(
    [in] LPCSTR   lpszDeviceName,
    [in] DEVMODEA *lpDevMode,
        HWND     hwnd,
    [in] DWORD    dwflags,
    [in] LPVOID   lParam
    );