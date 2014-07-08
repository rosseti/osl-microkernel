
# @author Andrei Rosseti <mdxico@gmail.com>

all:
	cd bootstrap; make; cd ../kernel/; make; cd ..;
	dd if=build/boot.bin of=build/osl-microkernel.img bs=512 count=1
	dd if=build/kernel.sys of=build/osl-microkernel.img bs=512 seek=1
	@echo -------------------------------------------------
	@echo "OSL compilation complete!"
	@echo "Look at the build/ folder for osl-microkernel.img :-)"
	@echo "Just do it!"
	@echo -------------------------------------------------

clean:
	cd bootstrap; make clean; cd ../kernel/; make clean; cd ..;
	rm -rf *.o
	rm -rf build/*.bin
	rm -rf build/*.sys
	rm -f *~