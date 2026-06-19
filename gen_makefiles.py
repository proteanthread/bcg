import os
import glob

def main():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    src_dir = os.path.join(base_dir, "SOURCE")
    games_dir = os.path.join(base_dir, "GAMES")
    bas_files = glob.glob(os.path.join(games_dir, "*.bas"))
    
    basenames = sorted([os.path.splitext(os.path.basename(f))[0] for f in bas_files])
    
    # 1. Linux GCC Makefile
    with open(os.path.join(base_dir, "Makefile"), "w") as f:
        f.write("CC = gcc\n")
        f.write("CFLAGS = -std=c17 -pedantic -Wall -Wno-unused-label -I.\n")
        f.write("LDFLAGS = -lm\n")
        f.write("SRCDIR = SOURCE\n")
        f.write("BINDIR = BINARY\n\n")
        f.write("TARGETS = " + " ".join([f"$(BINDIR)/{b}" for b in basenames]) + "\n\n")
        f.write("all: $(BINDIR) $(TARGETS)\n\n")
        f.write("$(BINDIR):\n")
        f.write("\tmkdir -p $(BINDIR)\n\n")
        for b in basenames:
            f.write(f"$(BINDIR)/{b}: $(SRCDIR)/{b}.c\n")
            f.write(f"\t$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)\n\n")
        f.write("clean:\n")
        f.write("\trm -rf $(BINDIR)\n")

    # 2. Windows MSVC Makefile.msvc
    with open(os.path.join(base_dir, "Makefile.msvc"), "w") as f:
        f.write("CC = cl\n")
        f.write("CFLAGS = /nologo /W3 /MD /D_CRT_SECURE_NO_WARNINGS /TC /std:c17 /wd4102\n")
        f.write("SRCDIR = SOURCE\n")
        f.write("BINDIR = BINARY\n\n")
        f.write("TARGETS = " + " ".join([f"$(BINDIR)\\{b}.exe" for b in basenames]) + "\n\n")
        f.write("all: $(BINDIR) $(TARGETS)\n\n")
        f.write("$(BINDIR):\n")
        f.write("\tif not exist $(BINDIR) mkdir $(BINDIR)\n\n")
        for b in basenames:
            f.write(f"$(BINDIR)\\{b}.exe: $(SRCDIR)\\{b}.c\n")
            f.write(f"\t$(CC) $(CFLAGS) /Fo$(BINDIR)\\ /Fe$@ $(SRCDIR)\\{b}.c\n\n")
        f.write("clean:\n")
        f.write("\tif exist $(BINDIR) rmdir /S /Q $(BINDIR)\n")

    # 3. FreeDOS Watcom Makefile.watcom
    with open(os.path.join(base_dir, "Makefile.watcom"), "w") as f:
        f.write("CC = wcl\n")
        f.write("CFLAGS = -q -w4 -ml -zt=100 -bt=dos -l=dos\n")
        f.write("SRCDIR = C89\n")
        f.write("BINDIR = FD\n\n")
        f.write("TARGETS = " + " ".join([f"$(BINDIR)\\{b}.exe" for b in basenames]) + "\n\n")
        f.write("all: $(BINDIR) $(TARGETS)\n\n")
        f.write("$(BINDIR):\n")
        f.write("\t-mkdir $(BINDIR)\n\n")
        for b in basenames:
            f.write(f"$(BINDIR)\\{b}.exe: $(SRCDIR)\\{b}.c\n")
            f.write(f"\t$(CC) $(CFLAGS) -fe=$@ $(SRCDIR)\\{b}.c\n\n")
        f.write("clean:\n")
        f.write("\t-del $(BINDIR)\\*.exe\n")
        f.write("\t-del $(BINDIR)\\*.obj\n")

    # 4. build_lx.sh
    with open(os.path.join(base_dir, "build_lx.sh"), "w", newline='\n') as f:
        f.write("#!/bin/bash\n")
        f.write("echo \"Building with GCC for Linux...\"\n")
        f.write("make -f Makefile\n")

    # 5. build_win.bat
    with open(os.path.join(base_dir, "build_win.bat"), "w") as f:
        f.write("@echo off\n")
        f.write("echo Building with MSVC for Windows 11...\n")
        f.write("nmake /f Makefile.msvc\n")

    # 6. build_fd.bat
    with open(os.path.join(base_dir, "build_fd.bat"), "w") as f:
        f.write("@echo off\n")
        f.write("echo Building with Open Watcom for FreeDOS...\n")
        f.write("set WATCOM=C:\\WATCOM\n")
        f.write("set PATH=%WATCOM%\\binnt;%WATCOM%\\binw;%PATH%\n")
        f.write("set INCLUDE=%WATCOM%\\h\n")
        f.write("wmake -f Makefile.watcom\n")

if __name__ == "__main__":
    main()
