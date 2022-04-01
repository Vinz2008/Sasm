#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "detect_file_extension.h"
char* detect_file_extension(char filename[30]) {
	int i;
	int i2;
	int pointPos;
	char* extension;
	char temp[10];
	for (i=0;i<strlen(filename);i++){
	if (filename[i] == '.'){
	pointPos = i;
	}
	}
	//printf("pointPos : %i\n", pointPos);
	memset(temp,0,sizeof(temp));
	extension = "\0";
	i2 = 0;
	for (i=pointPos;i<strlen(filename); i++){
	temp[i2] = filename[i];
	//printf("extension in loop : %c\n", filename[i]);
	i2++;
	}
	extension = temp;
	//printf("extension : %s\n", extension);
	return extension;
}
/*
int main(){
	const char* test = detect_file_extension("hello.docx");
	printf("%s\n", test);
}
*/
