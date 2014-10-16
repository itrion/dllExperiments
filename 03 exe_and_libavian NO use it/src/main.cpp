#include <stdio.h>

#ifdef BOOT_LIBRARY

// since we aren't linking against libstdc++, we must implement this
// ourselves:
extern "C" void __cxa_pure_virtual(void) {}


#endif // BOOT_LIBRARY

int main(int argc, char const *argv[])
{
	printf("experiment 3 executable file linked to libavian objs, no use of the avian methods");
}