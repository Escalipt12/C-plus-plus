#include <windows.h>
#include <iostream>
#include <string>



void main() {
	std::string Fedya = "FFFF";
	for (int i = 0; i <= Fedya.size(); i++) {
		std::cout << i << std::endl;
	}
	std::cin >> Fedya;
	printf("Nuber: %s" , Fedya);
}
