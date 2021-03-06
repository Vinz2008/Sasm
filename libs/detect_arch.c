#include "detect_arch.h"
#include <stdio.h>
#ifdef __x86_64__
#define ARCH "x86_64"
#define ARCHNUMBER 1
#elif __amd64__
#define ARCH "amd64"
#define ARCHNUMBER 2
#elif __arm__
#define ARCH "arm"
#define ARCHNUMBER 3
#elif __aarch64__
#define ARCH "aarch64"
#define ARCHNUMBER 4
#elif __i386__
#define ARCH "i386"
#define ARCHNUMBER 5
#elif __ia64__
#define ARCH "ia64"
#define ARCHNUMBER 6
#elif __powerpc__
#define ARCH "powerpc"
#define ARCHNUMBER 7
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
