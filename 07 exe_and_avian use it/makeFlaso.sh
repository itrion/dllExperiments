# copy the avian headers
#   avian-0.7.1/include
#   avian-0.7.1/src/avian

# to the the include directory of the cygwin
#   C:\cygwin\usr\i686-w64-mingw32\sys-root\mingw\include

# 1 generate the obj for the main class
i686-w64-mingw32-g++ -I"src" -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/win32" -I"../win32/include" -D_JNI_IMPLEMENTATION_ -DBOOT_LIBRARY -c src/main.cpp -o main.o

# 2 Link the main.o to the avian code and generates the DLL
i686-w64-mingw32-g++ -Llib -L"../win32/lib" -lmingwthrd -lm -lz -lws2_32 -ljvm -lavian -mwindows -mconsole -o main.exe  main.o