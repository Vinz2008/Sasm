#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

int FileExtensionCmp(char* filename, char* extension) {
	int i;
	int i2;
	int pointPos = -1;
	char* filenameExtension;
	char temp[10];
	for (i=0;i<strlen(filename);i++){
	if (filename[i] == '.'){
	pointPos = i;
	}
	}
	memset(temp,0,sizeof(temp));
	filenameExtension = "\0";
	i2 = 0;
	for (i=pointPos + 1;i<strlen(filename); i++){
	temp[i2] = filename[i];
	i2++;
	}
	memcpy(filenameExtension, temp, strlen(filenameExtension));
	filenameExtension = temp;
	if (strcmp(extension, filenameExtension) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

char* removeFileExtension(char* filename){
    int i;
	int i2;
	int pointPos = -1;
	char* temp = malloc(30 * sizeof(char));
	for (i=0;i<strlen(filename);i++){
	if (filename[i] == '.'){
	pointPos = i;
	}
	}
	memset(temp,0,sizeof(temp));
	for (i2 = 0; i2 < pointPos; i2++){
        temp[i2] = filename[i2];
    }
    return temp;
}

char* replaceFileExtension(char* filename, char* extension){
    int i;
	int i2;
    int i4 = 0;
	int pointPos;
	char* temp = malloc(30 * sizeof(char));
	for (i=0;i<strlen(filename);i++){
	if (filename[i] == '.'){
	pointPos = i;
	}
	}
	memset(temp,0,sizeof(temp));
	for (i2 = 0; i2 < pointPos; i2++){
        temp[i2] = filename[i2];
    }
    temp[i2++] = '.';
    for (int i3 = i2; i3 < i2 + strlen(extension); i3++){
        temp[i3] = extension[i4]; 
        i4++;
    }
    return temp;
    
}

