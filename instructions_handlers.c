#include "instructions_handlers.h"
#include <stdio.h>
#include <string.h>


void code_section_handler(FILE* fptr){
    printf("SECTION CODE\n");
    fprintf(fptr, "section .text\n");
}

void variable_section_handler(FILE* fptr){
    fprintf(fptr, "section .bss\n");
}

void function_declaration_handler(char line[], FILE* fptr, int IsDebugMode){
    char functionName[10];
    memset(functionName, 0, sizeof(functionName));
    for (int i = 0; i < strlen(line) - 1; i++){
        functionName[i] = line[i];
    }
    if (IsDebugMode == 1) {
        printf("function %s detected\n", functionName);
    }
    fprintf(fptr, "%s", line);
}


void move_handler(char line[], FILE* fptr, int IsDebugMode){
    int pos;
    int loopStartFrom = 0;
    int loopEndTo = 0;
    int i;
    fprintf(fptr, "\tmov ");
    for (pos = 5; pos < strlen(line); pos++){
    if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
    }
    if (line[pos] == '<'){
    if (line[pos + 1] == '='){
    if (line[pos + 2] == ' '){
        loopStartFrom = pos + 3;
    } else {
        loopStartFrom = pos + 2;
    }
    if (line[pos - 1] == ' '){
        loopEndTo = pos - 2;
    } else {
        loopEndTo = pos - 1;
    }
    }
    }
    }
    for (i = 5; i <= loopEndTo; i++) {
	    fprintf(fptr, "%c", line[i]);
        if (IsDebugMode == 1) {
        printf("i: %i\n", i);
        }
    }
	fprintf(fptr, ",");
    for (i = loopStartFrom; i < strlen(line); i++) {
	    fprintf(fptr, "%c", line[i]);
    }
}

void compare_handler(char line[], FILE* fptr, int IsDebugMode){
    int i;
    int loopStartFrom = 0;
    int loopEndTo = 0;
    fprintf(fptr, "\tcmp ");
    int pos;
    for (pos = 8; pos < strlen(line); pos++){
    if (IsDebugMode == 1) {
        printf("line[pos] : %c\n", line[pos]);
    }
    if (line[pos] == '<') {
    if (IsDebugMode == 1) {
    printf("< detected\n");
    }
    if (line[pos + 1] == '='){
    if (IsDebugMode == 1) {
    printf("= detected\n");
    printf("<= detected\n");
    }
    if (line[pos + 2] == ' '){
    loopStartFrom = pos + 3;
    } else {
    loopStartFrom = pos + 2;
    }
    if (line[pos - 1] == ' '){
    loopEndTo = pos - 2;
    } else {
    loopEndTo = pos - 1;
    }         
    }
    }
    }
    for (i = 8; i <= loopEndTo; i++) {
	fprintf(fptr, "%c", line[i]);
    if (IsDebugMode == 1) {
    printf("i: %i\n", i);
    }
    }
	fprintf(fptr, ",");
    for (i = loopStartFrom; i < strlen(line); i++){
	    fprintf(fptr, "%c", line[i]);
    }
}