/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <video.h>
#include <libc/stdio.h>
#include <gdt.h>

extern char start;

void k_main()
{
	screen_init();

	gdt_install();

	printfln("osl-microkernel started at 0x%x...", &start);
}
