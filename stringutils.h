#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#ifndef _WIN32

#include <ctype.h>
#include <assert.h>
#include <stdio.h>

static inline char *strupr(char *s)
{
	char *p;

	for (p = s; *p; p++)
		*p = toupper(*p);
	return s;
}

static inline char *itoa(int n, char *buffer, int radix)
{
	assert(radix == 10);
	sprintf(buffer, "%d", n);
	return buffer;
}

#endif

#endif
