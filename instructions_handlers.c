#include "instructions_handlers.h"
#include <stdio.h>
#include <string.h>
#include "emulator.h"
#include "arch/i386/instructions_handlers_i386.h"


void code_section_handler(FILE* fptr, int isEmulating){
    if (isEmulating == 0){
    code_section_handler_i386(fptr);
    }
}

void variable_section_handler(FILE* fptr, int isEmulating){
    if (isEmulating == 0){
    variable_section_handler_i386(fptr);
    }
}

void function_declaration_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating){
    function_declaration_handler_i386(line, fptr, IsDebugMode);
}


void move_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating){
    if (isEmulating == 1){
        move_handler_emulator(line, IsDebugMode);
    } else {
        move_handler_i386(line, fptr, IsDebugMode);
    }
}

void compare_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating){
    compare_handler_i386(line, fptr, IsDebugMode);
}

void add_handler(char line[], FILE* fptr, int IsDebugMode, int isEmulating){
    printf("ADD\n");
    if (isEmulating == 1){
        add_handler_emulator(line, IsDebugMode);
    } else {
        add_handler_i386(line, fptr, IsDebugMode);
    }
}