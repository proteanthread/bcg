import os
import glob

def main():
    base_dir = r"C:\Users\rtdos\GitHub\bcg"
    src_dir = os.path.join(base_dir, "src")
    bas_files = glob.glob(os.path.join(base_dir, "*.bas"))
    
    basenames = [os.path.splitext(os.path.basename(f))[0] for f in bas_files]
    
    # 1. Linux GCC Makefile
    with open(os.path.join(base_dir, "Makefile"), "w") as f:
        f.write("CC = gcc\n")
        f.write("CFLAGS = -std=c89 -pedantic -Wall -I.\n")
        f.write("LDFLAGS = -lm\n")
        f.write("SRCDIR = src\n")
        f.write("BINDIR = bin_linux\n\n")
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
        f.write("CFLAGS = /nologo /W3 /MD /D_CRT_SECURE_NO_WARNINGS /TC\n")
        f.write("SRCDIR = src\n")
        f.write("BINDIR = bin_msvc\n\n")
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
        f.write("CFLAGS = -q -za99 -bt=dos -l=dos\n") # -za99 for C99 or standard C, Watcom C89 is default usually but -za99 is safer for some syntax. Watcom handles C89 natively well. Let's use standard flags
        f.write("CFLAGS = -q -w4 -bt=dos -l=dos\n")
        f.write("SRCDIR = src\n")
        f.write("BINDIR = bin_dos\n\n")
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

    # 4. build_linux.sh
    with open(os.path.join(base_dir, "build_linux.sh"), "w", newline='\n') as f:
        f.write("#!/bin/bash\n")
        f.write("echo \"Building with GCC for Linux...\"\n")
        f.write("make -f Makefile\n")

    # 5. build_windows.bat
    with open(os.path.join(base_dir, "build_windows.bat"), "w") as f:
        f.write("@echo off\n")
        f.write("echo Building with MSVC for Windows 11...\n")
        f.write("nmake /f Makefile.msvc\n")

    # 6. build_freedos.bat
    with open(os.path.join(base_dir, "build_freedos.bat"), "w") as f:
        f.write("@echo off\n")
        f.write("echo Building with Open Watcom for FreeDOS...\n")
        f.write("wmake -f Makefile.watcom\n")

if __name__ == "__main__":
    main()
