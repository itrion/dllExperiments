#!/bin/bash
echo 
echo "################################################"
echo
rm *.exe
rm *.dll

g++ -shared SimpleLibrary.cpp -o libsimplelibrary.dll

gcc LibraryLoader.cpp -o main

./main