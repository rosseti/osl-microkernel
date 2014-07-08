/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <ioports.h>

void outb(unsigned short port, unsigned char value)
{
	__asm__ __volatile__ ("outb %1, %0" : : "d" (port), "a" (value));
}

unsigned char inb(unsigned short port)
{
	unsigned char r;

	__asm__ __volatile__("inb %1, %0" : "=a" (r) : "d" (port));

	return r;
}
