#pragma once

#include <cmath>

namespace brisk
{
	const long double pi = 3.14159265358979323846;

	template <class T = long double>
	struct trapezoid
	{
		T side1, side2, height;

		trapezoid() = default;

		trapezoid(T _side1, T _side2, T _height)
			: side1(_side1), side2(_side2), height(_height)
		{

		}

		T area()
		{
			return (side1 + side2) / 2 * height;
		}
	};

	template <class T = long double>
	struct rectangle
	{
		T length, width;

		rectangle() = default;

		rectangle(T _length, T _width)
			: length(_length), width(_width)
		{

		}

		T area()
		{
			return length * width;
		}
	};

	template <class T = long double>
	struct triangle
	{
		T base, height;

		triangle() = default;

		triangle(T _base, T _height)
			: base(_base), height(_height)
		{

		}

		T area()
		{
			return (base * height) / 2;
		}
	};

	template <class T = long double>
	struct rhombus
	{
		T side;

		rhombus() = default;

		rhombus(T _side)
			: side(_side)
		{

		}

		T area()
		{
			return side / 2;
		}
	};

	template <class T = long double>
	struct hexagon
	{
		T side;

		hexagon() = default;

		hexagon(T _side)
			: side(_side)
		{

		}

		T area()
		{
			return 3 * sqrt(3) / 2 * (side * side);
		}
	};

	template <class T = long double>
	struct circle
	{
		T radius;

		circle() = default;

		circle(T _radius)
			: radius(_radius)
		{

		}

		T area()
		{
			return pi * radius * radius;
		}
	};

	template <class T = long double>
	struct square
	{
		T side;

		square() = default;

		square(T _side)
			: side(_side)
		{

		}

		T area()
		{
			return side * side;
		}
	};

	template <class T = long double>
	struct rectangular_prism
	{
		T length, width, height;

		rectangular_prism() = default;

		rectangular_prism(T _length, T _width, T _height)
			: length(_length), width(_width), height(_height)
		{

		}

		T area()
		{
			return length * width * height;
		}
	};

	template <class T = long double>
	struct triangular_prism
	{
		T length, width, height;

		triangular_prism() = default;

		triangular_prism(T _length, T _width, T _height)
			: length(_length), width(_width), height(_height)
		{

		}

		T area()
		{
			return (length * width * height) / 2;
		}
	};

	template <class T = long double>
	struct cone
	{
		T radius, height;

		cone() = default;

		cone(T _radius, T _height)
			: radius(_radius), height(_height)
		{

		}

		T area()
		{
			return pi * (radius * radius) * (height / 3);
		}
	};

	template <class T = long double>
	struct cube
	{
		T face;

		cube() = default;

		cube(T _face)
			: face(_face)
		{

		}

		T area()
		{
			return face * face * face;
		}
	};
}
