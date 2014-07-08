
# @author Andrei Rosseti <mdxico@gmail.com>

ASM=nasm -f bin

all:
	$(ASM) boot.asm -o ../build/boot.bin
	@echo -- Boot strap compile [ok]

clean:
	rm -rf *.o
	rm -rf ../build/*.bin
	rm -f *~
	rm -f $(PROGRAM)