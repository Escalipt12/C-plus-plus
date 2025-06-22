
#include <Windows.h>
#include <iostream>



void main(){
	std::string Fedya = "dyrak";
	HWND window = FindWindowA("Notepad" , "Текстовый документ (2).txt — Блокнот");
	if (window) {
		std::cout << "fedya" << std::endl;
		SetWindowTextA(window, "FEDKA");
	}
	if (FindWindowA("Notepad", "FEDKA")) {
		std::cout << "fff" << std::endl;
	}

}
