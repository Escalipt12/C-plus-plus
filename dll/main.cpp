#include <windows.h>
#include <cstdio>
#include <iostream>

/*

DWORD temp;
Переменная для хранения результата чтения — 32-битное беззнаковое целое число (тип DWORD = unsigned long).

SIZE_T read;
Используется для хранения количества реально прочитанных байтов функцией ReadProcessMemory.

uintptr_t address = 0x00000049CADAFB84;
Указание 64-битного адреса памяти (что важно при работе с x64 процессами). Тип uintptr_t гарантирует корректный размер под указатель на текущей архитектуре (x64 здесь).


🔹 Чтение памяти другого процесса:

ReadProcessMemory(process, reinterpret_cast<LPVOID>(address), &temp, sizeof(temp), &read);
process — дескриптор открытого процесса, полученный ранее через OpenProcess().

reinterpret_cast<LPVOID>(address) — преобразование адреса к типу указателя на void.

&temp — указатель на переменную, куда будет записано значение.

sizeof(temp) — размер читаемых данных (4 байта).

&read — переменная, в которую записывается количество реально прочитанных байтов.

📌 Если всё прошло успешно, то temp содержит значение из памяти по адресу 0x49CADAFB84.

wchar_t buffer[64]; — создаётся буфер для строки (Unicode).

swprintf_s(...) — безопасный способ форматирования строки, аналог sprintf, но с проверками на переполнение.

Формат L"Зн
ачение: %u" указывает на подстановку беззнакового целого (temp) в Unicode-строку.


🔹 Что делает swprintf_s?
Это такая функция, которая помогает собрать строку из кусочков — например, если ты хочешь написать:

«У меня есть 5 конфет»

...но число 5 — это переменная, а не заранее написанный текст.


строка[100] — это как пустая коробка, в которую мы хотим положить текст.

L"У меня есть %d конфет" — это шаблон, в котором %d — это место для числа.

конфеты — это переменная, которую мы подставим вместо %d.

swprintf_s — это "умный маркер", который автоматически подставляет число на нужное место в строке.




*/


static void DLLL() {
	HWND window = FindWindowA("ConsoleWindowClass", 0);
	if (window) {
		MessageBoxA(window, "injected", "", MB_OK | MB_ICONMASK);
		DWORD pid = {};
		GetWindowThreadProcessId(window, &pid);

		if (pid != 0) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
			DWORD temp;
			SIZE_T read;
			uintptr_t address = 0x00000049CADAFB84;
			ReadProcessMemory(process, reinterpret_cast<LPVOID>(address), &temp, sizeof(temp), &read);
			wchar_t buffer[64];
			swprintf_s(buffer, L"Значение: %u", temp);
			MessageBoxW(NULL, buffer, L"Результат", MB_OK);
		}

	}
}

bool __stdcall DllMain(void* Module, unsigned long reason, void* reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(DLLL), 0, 0, 0);
		break;
	}
	return true;
}
