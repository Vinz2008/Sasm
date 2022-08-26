#include <stdint.h>

typedef uint16_t _register;

struct Registers {
	_register eax;
	_register ebx;
	_register ecx;
	_register edx;
};


typedef struct _Stackentry {
	void* data;
	int type;
} StackEntry;

struct Stack {
	StackEntry* stackList;
};

void emulate(char* inputFile, char* outputFile, int IsDebugMode);