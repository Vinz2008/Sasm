#include "instructions_handlers.h"
#include <stdio.h>
#include <string.h>
#include "arch/i386/instructions_handlers_i386.h"


void code_section_handler(FILE* fptr){
    code_section_handler_i386(fptr);
}

void variable_section_handler(FILE* fptr){
    variable_section_handler_i386(fptr);
}

void function_declaration_handler(char line[], FILE* fptr, int IsDebugMode){
    function_declaration_handler_i386(line, fptr, IsDebugMode);
}


void move_handler(char line[], FILE* fptr, int IsDebugMode){
    move_handler_i386(line, fptr, IsDebugMode);
}

void compare_handler(char line[], FILE* fptr, int IsDebugMode){
    compare_handler_i386(line, fptr, IsDebugMode);
}