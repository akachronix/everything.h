#ifndef EVERYTHING_H
#define EVERYTHING_H

#ifdef EVERYTHING_INLINE
#define add(a, b)(a + b)
#define subtract(a, b)(a - b)
#define multiply(a, b)(a * b)
#define divide(a, b)(a / b)

typedef struct{float length, width, area;} rectangle_t;
typedef struct{float height, side1, side2, area;} trapezoid_t;
typedef struct{float base, height, area;} triangle_t;
typedef struct{float radius, area;} circle_t;
typedef struct{float side, area;} square_t;

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

long double factorial(long double limit) {
	long double answer = 1;
	for(int i = 1; i < limit; i++) answer *= i + 1;
	return answer;
}

long double power(long double base, long double exponent) {
	long double a = base;
	for(int i = 1; i < exponent; i++) a *=  base;
	return a;
}

rectangle_t newRectangle(float initlength, float initwidth) {
	rectangle_t obj = {initlength, initwidth, initlength * initwidth};
	return obj;
}

trapezoid_t newTrapezoid(float initheight, float initside1, float initside2) {
	trapezoid_t obj = {initheight, initside1, initside2, (initside1 + initside2) / 2 * initheight};
	return obj;
}

triangle_t newTriangle(float initbase, float initheight) {
	triangle_t obj = {initbase, initheight, (initbase * initheight) / 2};
	return obj;
}

circle_t newCircle(float initradius) {
	circle_t obj = {initradius, power(initradius, 2) * 3.141592653};
	return obj;
}

square_t newSquare(float initside) {
	square_t obj = {initside, initside * initside};
	return obj;
}

#else
#include "Mathematics.h"
#include "Input.h"
#endif // EVERYTHING_INLINE

#endif // EVERYTHING_H
