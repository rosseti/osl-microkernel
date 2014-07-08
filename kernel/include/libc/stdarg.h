/**
 * Operating System Layer - http://www.rosseti.eti.br/
 * Copyright 2009 rosseti.eti.br   - All rights reserved
 *
 * @author Andrei Rosseti <mdxico@gmail.com>
 */

#ifndef	__STDARG
#define __STDARG

typedef int* va_list;

#define va_start(v1, last)		\
		v1 = (va_list) (&last + 1);

#define va_arg(v1, type)		\
		*(type *) ((v1)++)

#define va_end(v1)				\
		v1 = NULL

#endif
