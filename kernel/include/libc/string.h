/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <libc/stddef.h>

void *memcpy(void *ptr, void *src, size_t len);
void *memset(void *ptr, int p, size_t len);
char *strcpy(char *dp, const char *sp);
char *strlcpy(char *dp, const char *sp, size_t len);
char *strcat (char *src, const char *append);
int   strlen (char *src);

