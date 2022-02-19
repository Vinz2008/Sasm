#include "detect_arch.h"
#include <stdio.h>
#ifdef __arm__
#define ARCH "arm"
#define ARCHNUMBER 1
#elif __aarch64__
#define ARCH "aarch64"
#define ARCHNUMBER 2
#elif __i386__
#define ARCH "i386"
#define ARCHNUMBER 3
#elif __ia64__
#define ARCH "ia64"
#define ARCHNUMBER 4
#elif __x86_64__
#define ARCH "x86_64"
#define ARCHNUMBER 5
#else
#define ARCH "unknown"
#define ARCHNUMBER 0
#endif
int detect_arch() {
	printf("%s\n",ARCH);
	return ARCHNUMBER;
}
/*
int main() {
	detect_arch();
	return 0;
}

*/