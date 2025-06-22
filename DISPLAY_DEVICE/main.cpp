#include <windows.h>
#include <iostream>

int main()
{
    for (int i = 0;; i++)
    {
        DISPLAY_DEVICE dd = { sizeof(dd), 0 };
        BOOL f = EnumDisplayDevices(NULL, i, &dd, EDD_GET_DEVICE_INTERFACE_NAME);
        if (!f)
            break;

        std::wcout << dd.DeviceString << L"\r\n";
    }
    return 0;
}
