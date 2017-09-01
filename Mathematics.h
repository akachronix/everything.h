#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#define add		 (a, b)	(a + b)
#define subtract (a, b)	(a - b)
#define multiply (a, b)	(a * b)
#define divide   (a, b) (a / b)

typedef struct{float length, width, area;}			rectangle_t;
typedef struct{float height, side1, side2, area;}	trapezoid_t;
typedef struct{float base, height, area;}			triangle_t;
typedef struct{float radius, area;} 				circle_t;
typedef struct{float side, area;}					square_t;

long double factorial(long double limit);
long double power(long double base, long double exponent);

rectangle_t newRectangle(float initlength, float initwidth);
trapezoid_t newTrapezoid(float initheight, float initside1, float initside2);
triangle_t	newTriangle(float initbase, float initheight);
circle_t	newCircle(float initradius);
square_t	newSquare(float initside);

#endif