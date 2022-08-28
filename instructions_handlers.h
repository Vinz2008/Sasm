#include <stdio.h>

void move_handler(char line[], FILE* fptr, int IsDebugMode);
void compare_handler(char line[], FILE* fptr, int IsDebugMode);
void code_section_handler(FILE* fptr);
void variable_section_handler(FILE* fptr);
void function_declaration_handler(char line[], FILE* fptr, int IsDebugMode);