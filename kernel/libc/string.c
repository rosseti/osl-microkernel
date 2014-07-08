/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#include <libc/string.h>

void *memcpy(void *ptr, void *src, size_t len)
{
    char *sp = (char *) src;
    char *dp = (char *) ptr;

    for(; len > 0; len--)
		*dp++ = *sp++;

    return ptr;
}

void *memset(void *ptr, int p, size_t len)
{
	char *tmp = (char *) ptr;

	for (; len > 0; len--)
		*tmp++ = p;

	return ptr;
}

char *strcpy(char *dp, const char *sp)
{
	char *tmp = dp;

	while (*sp != '\0')
	{
		*dp = *sp;

		dp++;
		sp++;
	}

	return tmp;
}

char *strlcpy(char *dp, const char *sp, size_t len)
{
	char *tmp = dp;

	while (len-- > 0)
	{
		*dp = *sp;

		dp++;
		sp++;
	}

	return tmp;
}

char *strcat(char *src, const char *append)
{
	char *save = src;

	for (; *src; ++src);

	while ((*src++ = *append++));

	return save;
}

int strlen(char *src)
{
	int i = 0;

	while (*src++) i++;

	return i;
}
