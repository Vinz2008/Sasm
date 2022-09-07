#include <stdio.h>

void move_handler_i386(char line[], FILE* fptr, int IsDebugMode);
void compare_handler_i386(char line[], FILE* fptr, int IsDebugMode);
void code_section_handler_i386(FILE* fptr);
void variable_section_handler_i386(FILE* fptr);
void function_declaration_handler_i386(char line[], FILE* fptr, int IsDebugMode);