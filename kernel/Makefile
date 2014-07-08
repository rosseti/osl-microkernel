
# @author Andrei Rosseti <mdxico@gmail.com>

ASM=nasm -f aout
CC=gcc
LD=ld

PROGRAM = kernel.sys

CFLAGS=-g -O2 -Wall -W -fno-builtin -nostdlib -Iinclude/
LFLAGS=--oformat binary -Ttext 0x500 -e k_main

SRCS =  gdt.c \
		main.c \
		ioports.c \
		video.c \
		libc/string.c \
		libc/stdio.c

OBJS =  gdt.o \
		main.o \
		ioports.o \
		video.o \
		libc/string.o \
		libc/stdio.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(PROGRAM)
	@echo Kernel compile [ok]

clean:
	rm -rf *.o
	rm -rf */*.o
	rm -rf *.bin
	rm -f *~
	rm -f $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(ASM) start.asm -o start.o
	$(LD) $(LFLAGS) -o ../build/$@ start.o $(OBJS)
