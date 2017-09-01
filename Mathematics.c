#include "Mathematics.h"

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