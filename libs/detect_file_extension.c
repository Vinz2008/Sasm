#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "detect_file_extension.h"
int FileExtensionCmp(char* filename, char* extension) {
	int i;
	int i2;
	int pointPos;
	char* filenameExtension;
	char temp[10];
	for (i=0;i<strlen(filename);i++){
	if (filename[i] == '.'){
	pointPos = i;
	}
	}
	//printf("pointPos : %i\n", pointPos);
	memset(temp,0,sizeof(temp));
	filenameExtension = "\0";
	i2 = 0;
	for (i=pointPos + 1;i<strlen(filename); i++){
	temp[i2] = filename[i];
	//printf("extension in loop : %c\n", filename[i]);
	i2++;
	}
	memcpy(filenameExtension, temp, strlen(filenameExtension));
	filenameExtension = temp;
	//printf("filenameExtension : %s\n", filenameExtension);
	//printf("%i\n", strcmp(extension, filenameExtension));
	if (strcmp(extension, filenameExtension) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

/*int main(){
	int test = FileExtensionCmp("hello.txt", "txt");
	printf("%i\n", test);  
}*/

