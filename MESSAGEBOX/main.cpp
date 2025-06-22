#include <windows.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "rus");
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    std::string a = "fdsfsdfdsf";
    HWND window = FindWindowA("OpusApp", "3д (2)  -  защищенный просмотр - Word");
    if (FindWindowA("OpusApp", "3д (2)  -  защищенный просмотр - Word")) {
        SetWindowTextA(window, "AAAAA");
    }
    if (!FindWindowA("OpusApp", "2д (2)  -  защищенный просмотр - Word")) {
        std::cout << "Значение не найдено" << std::endl;
    }
    int ab = MessageBoxA(window, "FEDYKA", "NARKOMAN", MB_OK);
    for (int i = 0; i < 100; i++) {
        if (ab == IDOK) {
            MessageBoxA(window, "FEDYKA", "NARKOMAN", MB_OK);
        }
    }

   
    

    return 0;
}
