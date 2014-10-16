#include <windows.h>
#include <stdio.h>

typedef void (*printMessageFunction)(const char* message);

int main(int argc, char const *argv[]){
	HMODULE libHandle = LoadLibrary("libsimplelibrary.dll");
	if(libHandle == NULL){
		printf("impossible to load library\n");
		exit(1);
	}
	printf("%d\n", libHandle);
	printMessageFunction myPrint = (printMessageFunction) GetProcAddress(libHandle, "printMessage");
	myPrint("Hello library");
}