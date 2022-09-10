#include <stdio.h>

void move_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating);
void compare_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating);
void code_section_handler(FILE* fptr, int isEmulating);
void variable_section_handler(FILE* fptr, int isEmulating);
void function_declaration_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating);