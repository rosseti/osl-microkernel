;
; @ Author Andrei Rosseti <mdxico@gmail.com>
; Oh God! Thank you for give me protected mode :-)
;
[bits 32]

[extern k_main]
[extern gp]

[global start]
[global gdt_flush]

start:
  call k_main
  cli
  hlt

gdt_flush:
	lgdt [gp]
	mov ax, 10h
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 08h:gdt_flush2

gdt_flush2:
	ret