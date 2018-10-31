#pragma once

#include <cmath>

const long double pi = 3.14159265358979323846;

inline long double add(const long double x, const long double y) { return x + y; }
inline long double subtract(const long double x, const long double y) { return x - y; }
inline long double multiply(const long double x, const long double y) { return x * y; }
inline long double divide(const long double x, const long double y) { return x / y; }

inline long double power(const long double base, const long double exponent)
{
	long double answer = base;
	for (int i = 1; i < exponent; i++)
		answer *= base;

	return answer;
}

// 2D shapes
typedef struct {long double side1, side2, height, area;} trapezoid_t;
typedef struct {long double length, width, area;} rectangle_t;
typedef struct {long double base, height, area;} triangle_t;
typedef struct {long double side, area;} rhombus_t;
typedef struct {long double side, area;} hexagon_t;
typedef struct {long double radius, area;} circle_t;
typedef struct {long double side, area;} square_t;

// 3D shapes
typedef struct {long double length, width, height, area;} rectangular_prism_t;
typedef struct {long double length, width, height, area;} triangular_prism_t;
typedef struct {long double radius, height, area;} cone_t;
typedef struct {long double face, area;} cube_t;

trapezoid_t Trapezoid(long double side1, long double side2, long double height)
{
	trapezoid_t obj = {side1, side2, height, (side1 + side2) / 2 * height};
	return obj;
}

rectangle_t Rectangle(long double length, long double width)
{
	rectangle_t obj = {length, width, length * width};
	return obj;
}

triangle_t Triangle(long double base, long double height)
{
	triangle_t obj = {base, height, (base * height) / 2};
	return obj;
}

rhombus_t Rhombus(long double side)
{
	rhombus_t obj = {side, 0.5 * side};
	return obj;
}

hexagon_t Hexagon(long double side)
{
	hexagon_t obj = {side, 3 * sqrt(3) / 2 * power(side, 2)};
	return obj;
}

circle_t Circle(long double radius)
{
	circle_t obj = {radius, (radius * radius) * pi};
	return obj;
}

square_t Square(long double side)
{
	square_t obj = {side, side * side};
	return obj;
}

rectangular_prism_t Rectangular_Prism(long double length, long double width, long double height)
{
	rectangular_prism_t obj = {length, width, height, length * width * height};
	return obj;
}

triangular_prism_t Triangular_Prism(long double length, long double width, long double height)
{
	triangular_prism_t obj = {length, width, height, 0.5 * length * width * height};
	return obj;
}

cone_t Cone(long double radius, long double height)
{
	cone_t obj = {radius, height, pi * (radius * radius) * (height / 3)};
	return obj;
}

cube_t Cube(long double face)
{
	cube_t obj = {face, face * face * face};
	return obj;
}
