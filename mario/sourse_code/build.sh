#!/bin/bash
rm -f log
rm -f mario.exe
x86_64-w64-mingw32-g++ -finput-charset=utf-8 -fexec-charset=windows-1251 main.cpp -o mario.exe -luser32
/mnt/c/Windows/System32/cmd.exe /c "start mario.exe"