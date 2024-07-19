/*!
 * \file DisplaySettings.cpp
 * \brief Contains DisplaySettings Class, program main function
 * \details Detailed description of the file.
 */
#include <iostream>
#include <bitset>

#include <windows.h>    

//! How many displays connected.
#define DEVICETOTAL 3
#define TVID "PCI\\VEN_10DE&DEV_2482&SUBSYS_37853842&REV_A1"

/*!
 * \class DisplaySettings
 * \brief Interface to abstract Microsoft Display API
 * \details Call constructor to use functions
 */
class StateMachine
{
    public:
        /*!
        * \enum DisplayState
        * \brief How many Display states program has
        * \details STATE_0 will be default - dual monitors on, STATE_1 is TV on only
        */
        enum DisplayState
        {
            STATE_0,
            STATE_1,
        };

        // Function to handle the state transitions
        void ChangeState(DisplayState& currentState)
        {
            switch (currentState)
            {
                case STATE_0: //! dual monitors on
                    currentState = STATE_1;
                    std::cout << "Transitioning from STATE0 to STATE1" << std::endl;
                    // function that changes the state
                    break;
                case STATE_1: //! TV on
                    currentState = STATE_0; 
                    std::cout << "Transitioning from STATE0 to STATE1"  << std::endl;
                    // function that changes the state
                    break;
                default:
                    std::cout << "Unknown state!" << std::endl;
                    break;
            }
        }

        DisplayState GetState()
        {
            return State;
        }

        void AssignState(DisplayState var)
        {
            State = var;
        }

    private:
        DisplayState State;
};

/*!
 * \class DisplaySettings
 * \brief Interface to abstract Microsoft Display API
 * \details Call constructor to use functions
 */
class DisplaySettings
{
    public:

        /*!
        * \brief Constructor for DisplaySettings, initializes DISPLAY_DEVICE displayDevice DEVMODE devMode.
        * \note Sets size of structures and clears devMode per Microsoft API.
        */
        DisplaySettings()
        {
        displayDevice.cb = sizeof(DISPLAY_DEVICE);
        memset(&devMode, 0, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        }

        /*!
        * \brief Prints information and settings of available displays.
        */
        void PrintAllDisplayInfo()
        {
            for(DWORD deviceIndex = 0; deviceIndex < DEVICETOTAL; deviceIndex++)
            {
                if(EnumDisplayDevices(NULL, deviceIndex, &displayDevice, 0)) 
                {
                    std::cout << "\nEnumDisplayDevices:                               " << std::endl;
                    std::cout << "Device Name                                       " << displayDevice.DeviceName << std::endl;
                    std::cout << "Device String                                     " << displayDevice.DeviceString << std::endl;
                    std::cout << "State Flags                                       " << std::bitset<8>(displayDevice.StateFlags) << std::endl;
                    std::cout << "DeviceID                                          " << displayDevice.DeviceID << std::endl;
                    std::cout << "DeviceKey                                         " << displayDevice.DeviceKey << std::endl;

                    if(EnumDisplaySettingsEx(displayDevice.DeviceName, ENUM_CURRENT_SETTINGS, &devMode, 0))
                    {
                        std::cout << "\nEnumDisplaySettingsEx:                            " << std::endl;
                        std::cout << "Color resolution, in bits per pixel               " << devMode.dmBitsPerPel << std::endl;
                        std::cout << "Width, in pixels, of the visible device surface   " << devMode.dmPelsWidth << std::endl;
                        std::cout << "Height, in pixels, of the visible device surface  " << devMode.dmPelsHeight << std::endl;
                        std::cout << "Display mode.                                     " << devMode.dmDisplayFlags << std::endl;
                        std::cout << "Frequency, in hertz (cycles per second)           " << devMode.dmDisplayFrequency << std::endl;
                        std::cout << "Positional coordinates of the display device      " << devMode.dmPosition.x << devMode.dmPosition.y << std::endl;
                        std::cout << "Rotation, 0 degrees 0, 90 degrees 1, etc          " << devMode.dmDisplayOrientation << std::endl;
                    }
                    else
                    {
                        std::cerr << "Failed to return display settings." << std::endl;
                    }
                }
                else
                {
                    std::cerr << "Failed to identify display info." << std::endl;
                }
            }
        }

        /*!
        * \brief finds what display the TV is on, Returns status of Display3
        */
        int GetTvStatus()
        {
            for(DWORD Index = 0; Index < DEVICETOTAL; Index++)
            {
                if(EnumDisplayDevices(NULL, Index, &displayDevice, 0)) 
                {
                    std::cout << "\nTvStatus:" << std::endl;
                    std::cout << "Device Name                                       " << displayDevice.DeviceName << std::endl;
                    std::cout << "State Flags                                       " << std::bitset<8>(displayDevice.StateFlags) << std::endl;
                    std::cout << "DeviceID                                          " << displayDevice.DeviceID << std::endl;
                    std::cout << "TVID                                              " << TVID << std::endl;

                    std::string devId(displayDevice.DeviceID);
                    if (devId == TVID)
                    {
                        std::cout << "Tv found!                                         " << TVID << std::endl;
                        return 1;
                    }
                    else
                    {
                        std::cerr << "Could not find TV, killing program" << std::endl;
                        return -1;
                    }
                }
                else
                {
                    std::cerr << "Failed to identify display info." << std::endl;
                    return -1;
                }
                
            }
            return 0;
        }

    /*!
    * \brief DISPLAY_DEVICE holds info about the display, DEVMODE holds settings for displays
    */
    private:
        DISPLAY_DEVICE displayDevice;
        DEVMODE devMode;
};

/*!
 * \brief main function, have states that determine which displays are on, that way the states can be added/erased to while not compromising ease of use
 * \note function will read what state it's in and change to next state
 */
int main()
{
    // StateMachine St;
    DisplaySettings displays;
    displays.PrintAllDisplayInfo();

    int out = displays.GetTvStatus();
    std::cout << "Out                                               " << out << std::endl;
    if(displays.GetTvStatus())
    {
        
    }
    // get state from winapi, assign it, change it 
    
    return 0;
}
