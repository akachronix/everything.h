#include "Input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double inputDbl(const char* question) {
	printf("%s", question);
	double input = 0.0;
	scanf("%f", &input);
	printf("\n");
	return input;
}

char* inputStr(const char* question) {
	printf("%s", question);
	char* buffer = (char*)malloc(sizeof(char) * 1024);
	if(buffer == NULL) {
		return NULL;
	} else {
		scanf("%s", buffer);
		char* input = (char*)malloc(sizeof(char) * strlen(buffer));
		if(buffer == NULL) {
			return NULL;
		} else {
			strncpy(input, buffer, strlen(buffer) + 1);
			free(buffer);
			buffer = NULL;
			return input;
		}
	}
	
	return NULL;
}

float inputFlt(const char* question) {
	printf("%s", question);
	float input = 0.0;
	scanf("%f", &input);
	printf("\n");
	return input;
}

long inputLng(const char* question) {
	printf("%s", question);
	long input = 0;
	scanf("%l", &input);
	printf("\n");
	return input;
}

int inputInt(const char* question) {
	printf("%s", question);
	int input = 0;
	scanf("%i", &input);
	printf("\n");
	return input;
}