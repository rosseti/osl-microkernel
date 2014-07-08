/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <video.h>
#include <libc/stddef.h>
#include <libc/stdarg.h>
#include <libc/string.h>

#define		PR_LJ	0x01
#define		PR_CA	0x02
#define		PR_SG	0x04
#define		PR_32	0x08
#define		PR_16	0x10
#define		PR_WS	0x20
#define		PR_LZ	0x40
#define		PR_FP	0x80

#define		PR_BUFLEN	16

typedef int ( * fn_ptr ) ( unsigned char c, void **callback);

void printfln(char* fmt, ...);
void printf(const char *fmt, ...);
