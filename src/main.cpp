/**
 * @file   main.cpp
 * @brief  prints display information for all devices
 */

#include <iostream>
#include <windows.h>

#define DEVICETOTAL 2

bool GetDisplayInfo() // prints info for each device
{
    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(DISPLAY_DEVICE);

    DEVMODE devMode;
    memset(&devMode, 0, sizeof(devMode));
    devMode.dmSize = sizeof(devMode);
    
    for(DWORD deviceIndex = 0; deviceIndex < DEVICETOTAL; deviceIndex++)
    {
        if(EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0)) 
        {
            EnumDisplayDevices(displayDevice.DeviceName, deviceIndex, &displayDevice, 0);
            std::cout << "Device Name" << displayDevice.DeviceName << std::endl;
            std::cout << "Device String" << displayDevice.DeviceString << std::endl;
            std::cout << "State Flags" << displayDevice.StateFlags << std::endl;
            std::cout << "DeviceID" << displayDevice.DeviceID << std::endl;
            std::cout << "DeviceKey" << displayDevice.DeviceKey << std::endl;

            if(EnumDisplaySettingsEx(displayDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode, 0))
            {
                std::cout << "Color resolution, in bits per pixel" << devMode.dmBitsPerPel << std::endl;
                std::cout << "Width, in pixels, of the visible device surface" << devMode.dmPelsWidth << std::endl;
                std::cout << "Height, in pixels, of the visible device surface." << devMode.dmPelsHeight << std::endl;
                std::cout << "Display mode." << devMode.dmDisplayFlags << std::endl;
                std::cout << "Frequency, in hertz (cycles per second)" << devMode.dmDisplayFrequency << std::endl;
                std::cout << "Positional coordinates of the display device" << devMode.dmPosition.x << devMode.dmPosition.y << std::endl;
                std::cout << "Rotation, 0 degrees 0, 90 degrees 1, etc." << devMode.dmDisplayOrientation << std::endl;
                
            }
            else
            {
                std::cerr << "Failed to return display info." << std::endl;
            }
        } 
        else
        {
            std::cerr << "Failed to enumerate display devices." << std::endl;
        }
    }
    return false;
}

int main()
{
    bool tvOn = false;
    tvOn = GetDisplayInfo();

    // with the info from device 3, determine if TV is on or monitors are on
    // for my own peace of mind, lets just change monitors 2 and 3 
    if (tvOn)
    {
        // change to 2 monitors
        // turn off monitor 3
        // turn on display 2
    }
    else
    {
        // change to TV
        // Turn off monitor 2
        // Turn on monitor 3 one with biggest pixel size
    }
    return 0;
}
