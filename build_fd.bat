@echo off
echo Building with Open Watcom for FreeDOS...
set WATCOM=C:\WATCOM
set PATH=%WATCOM%\binnt;%WATCOM%\binw;%PATH%
set INCLUDE=%WATCOM%\h
wmake -f Makefile.watcom
