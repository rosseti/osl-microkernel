;
; Operating System Layer - http://www.rosseti.eti.br/
; Copyright 2009 rosseti.eti.br   - All rights reserved
;
; @ authors Andrei Rosseti <mdxico@gmail.com>
;           Demis Rosseti <demisrosseti@gmail.com>

[BITS 16]
[ORG 0x7c00]

init:
    mov si, welcome_msg
    call print_string

    mov [drive], dl             ; pegamos o nr da unidade
    call reset_disk

get_key:
    mov ah, 0x00
    int 0x16
    ret

reset_disk:
    mov ah, 0h                  ; 0h rotina de reset da bios
    mov dl, [drive]             ; nr do drive que ira ser resetado
    int 13h
    jc reset_disk               ; cf = 0 pula para read_disk

read_disk:
    call success

    mov ax, 0
    mov es, ax                 	; atualiza o extra segment
    mov ax, 0x500             	; endereco onde vamos carregar o kernel
    mov bx, ax

    mov ah, 02h                 ; 02h rotina de leitura da bios
    mov al, 6                   ; nr de setores para ler
    mov ch, 0                   ; nr do cilindro
    mov cl, 2                   ; nr do setor
    mov dh, 0                   ; nr da cabeca
    mov dl, [drive]             ; nr do drive
    int 13h
    jc read_disk

running:
    call success

    call get_key

    xor ax, ax              	; Apaga o registrador AX
    mov ds, ax              	; Modifica o registrador DS para 0
    lgdt [gdt_desc]				; carrega gdtr

    ; seta modo protegido
    mov eax,	cr0
    or eax,		1
    mov cr0,	eax				; pmode bit set

    ; estamos em modo protegido
    jmp 08h:pmode

; Cada etapa de sucesso, mostra um ponto em tela
success:
    mov ah, 0x0e
    mov al, '.'
    int 10h
    ret

print_string:
    mov ah, 0x0e
    .next_ptr
      lodsb
      cmp al, 0
      jz .done
      int 0x10
      jmp .next_ptr
    .done
      ret

[bits 32]
pmode:
	mov ax, 10h
	mov ds, ax
	mov ss, ax
	mov esp, 090000h

	jmp 08h:0x500

; Global Descriptor Table
gdt:

gdt_null:
		dd 0
		dd 0

gdt_kernel_code:
	dw 0FFFFh               ; Limit 0xFFFF
	dw 0                    ; Base 0:15
	db 0                    ; Base 16:23
	db 09Ah                 ; Ring 0
	db 0CFh                 ; Page-granular
	db 0                    ; Base 24:31

gdt_kernel_data:
	dw 0FFFFh               ; Limit 0xFFFF
	dw 0                    ; Base 0:15
	db 0                    ; Base 16:23
	db 092h                 ; Ring 0s
	db 0CFh                 ; Page-granular
	db 0                    ; Base 24:32

gdt_interrupts:
	dw 0FFFFh
	dw 01000h
	db 0
	db 10011110b
	db 11001111b
	db 0

gdt_end:

gdt_desc:
	dw gdt_end - gdt - 1
	dd gdt

drive       db 0
welcome_msg db "welcome to the osl-microkernel operating system real mode .", 0

times 510-($-$$) db 0
dw 0xaa55