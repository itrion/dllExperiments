#ifndef DLL_INDEPENDENT
#define DLL_INDEPENDENT 

#ifdef BOOT_LIBRARY
extern "C" void __cxa_pure_virtual(void);
#endif // BOOT_LIBRARY

extern "C" __declspec( dllexport ) int getNumber();
extern "C" __declspec( dllexport ) int printfFromJava();
#endif