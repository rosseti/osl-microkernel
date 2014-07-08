/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <gdt.h>
#include <libc/stdio.h>

void gdt_set_gate(int num, unsigned long base, unsigned long limit,
	unsigned char access, unsigned char gran)
{
    gdt[num].base_low = (base & 0xFFFF);
    gdt[num].base_middle = (base >> 16) & 0xFF;

    gdt[num].base_high = (base >> 24) & 0xFF;

    gdt[num].limit_low = (limit & 0xFFFF);
    gdt[num].granularity = ((limit >> 16) & 0x0F);

    gdt[num].granularity |= (gran & 0xF0);
    gdt[num].access = access;
}

void gdt_install()
{
    /* init the gdt pointer and limit */
    gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
    gp.base = (unsigned int) &gdt;

    /* first entry: null descriptor */
    gdt_set_gate(0, 0, 0, 0, 0);

    /**
     * second and third entry: code segment.
     * base address: 0
     * limit	   : 4 GBytes -> 4.294.967.295
     * access	   : code segment descriptor
     * granularity : 4KByte
     */
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);

    gdt_flush();

    printfln("gdt_install: ok ...");
}
