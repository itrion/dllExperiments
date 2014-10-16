#include <stdio.h>

#ifdef __cplusplus
extern "C"{
#endif
	__declspec(dllexport) void printMessage(const char* message){
		printf("%s\n", message);
	}

#ifdef __cplusplus
}
#endif