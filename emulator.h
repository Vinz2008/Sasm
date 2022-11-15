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

void init_emulator(char* inputFile, char* outputFile, int IsDebugMode);
void move_handler_emulator(char line[], int IsDebugMode);
void add_handler_emulator(char line[], int IsDebugMode);