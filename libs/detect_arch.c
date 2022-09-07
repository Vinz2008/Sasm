#include "detect_arch.h"
#include <stdio.h>
#ifdef __x86_64__
#define ARCH ARCH_X86_64
#elif __amd64__
#define ARCH ARCH_AMD64
#elif __arm__
#define ARCH ARCH_ARM
#elif __aarch64__
#define ARCH ARCH_AARCH64
#elif __i386__
#define ARCH ARCH_I386
#elif __ia64__
#define ARCH ARCH_IA64
#elif __powerpc__
#define ARCH ARCH_POWERPC
#else
#define ARCH ARCH_UNKNOWN
#endif
int detect_arch() {
	return ARCH;
}
/*
int main() {
	detect_arch();
	return 0;
}
*/
