#include "libmath.hpp"

#include <cmath>

namespace libmath
{
	double add(double x, double y)
	{
		return x + y;
	}

	double subtract(double x, double y)
	{
		return x - y;
	}

	double multiply(double x, double y)
	{
		return x * y;
	}

	double divide(double x, double y)
	{
		return x / y;
	}

	double power(double base, double exponent)
	{
		double answer = base;

		for(int i = 1; i < exponent; i++)
		{
			answer *= base;
		}

		return answer;
	}

	// 2D Shapes
	trapezoid_t Trapezoid(double side1, double side2, double height)
	{
		trapezoid_t obj = {side1, side2, height, (side1 + side2) / 2 * height};
		return obj;
	}

	rectangle_t Rectangle(double length, double width)
	{
		rectangle_t obj = {length, width, length * width};
		return obj;
	}

	triangle_t Triangle(double base, double height)
	{
		triangle_t obj = {base, height, (base * height) / 2};
		return obj;
	}

	rhombus_t Rhombus(double side)
	{
		rhombus_t obj = {side, 0.5 * side};
		return obj;
	}

	hexagon_t Hexagon(double side)
	{
		hexagon_t obj = {side, 3 * sqrt(3) / 2 * power(side, 2)};
		return obj;
	}

	circle_t Circle(double radius)
	{
		circle_t obj = {radius, (radius * radius) * pi};
		return obj;
	}

	square_t Square(double side)
	{
		square_t obj = {side, side * side};
		return obj;
	}

	// 3D Shapes
	rectangular_prism_t Rectangular_Prism(double length, double width, double height)
	{
		rectangular_prism_t obj = {length, width, height, length * width * height};
		return obj;
	}

	triangular_prism_t Triangular_Prism(double length, double width, double height)
	{
		triangular_prism_t obj = {length, width, height, 0.5 * length * width * height};
		return obj;
	}

	cone_t Cone(double radius, double height)
	{
		cone_t obj = {radius, height, pi * (radius * radius) * (height / 3)};
		return obj;
	}

	cube_t Cube(double face)
	{
		cube_t obj = {face, face * face * face};
		return obj;
	}
}
