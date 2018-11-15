#pragma once

#include <cmath>

namespace brisk
{
	const long double pi = 3.14159265358979323846;

	template<typename T = long double>
	class Trapezoid
	{
	public:
		T side1, side2, height;

		Trapezoid() = default;
		Trapezoid(T _side1, T _side2, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Rectangle
	{
	public:
		T length, width;

		Rectangle() = default;
		Rectangle(T _length, T _width);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Triangle
	{
	public:
		T base, height;

		Triangle() = default;
		Triangle(T _base, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Rhombus
	{
	public:
		T side;

		Rhombus() = default;
		Rhombus(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Hexagon
	{
	public:
		T side;

		Hexagon() = default;
		Hexagon(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Circle
	{
	public:
		T radius;

		Circle() = default;
		Circle(T _radius);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Square
	{
	public:
		T side;

		Square() = default;
		Square(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class RectangularPrism
	{
	public:
		T length, width, height;

		RectangularPrism() = default;
		RectangularPrism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class TriangularPrism
	{
	public:
		T length, width, height;

		TriangularPrism() = default;
		TriangularPrism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Cone
	{
	public:
		T radius, height;

		Cone() = default;
		Cone(T _radius, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class Cube
	{
	public:
		T face;

		Cube() = default;
		Cube(T _face);

		T area();
		T operator()();
	};

	template<typename T>
	Trapezoid<T>::Trapezoid(T _side1, T _side2, T _height)
		: side1(_side1), side2(_side2), height(_height)
	{

	}

	template<typename T>
	T Trapezoid<T>::area()
	{
		return (side1 + side2) / 2 * height;
	}

	template<typename T>
	T Trapezoid<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Rectangle<T>::Rectangle(T _length, T _width)
		: length(_length), width(_width)
	{
	#if defined(EVERYTHING_DEBUG) || defined(MATH_DEBUG)
		std::cout << "Rectangle(T _length, T _width)\n";
	#endif
	}

	template<typename T>
	T Rectangle<T>::area()
	{
		return length * width;
	}

	template<typename T>
	T Rectangle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Triangle<T>::Triangle(T _base, T _height)
		: base(_base), height(_height)
	{

	}

	template<typename T>
	T Triangle<T>::area()
	{
		return (base * height) / 2;
	}

	template<typename T>
	T Triangle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Rhombus<T>::Rhombus(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T Rhombus<T>::area()
	{
		return side / 2;
	}

	template<typename T>
	T Rhombus<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Hexagon<T>::Hexagon(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T Hexagon<T>::area()
	{
		return 3 * sqrt(3) / 2 * (side * side);
	}

	template<typename T>
	T Hexagon<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Circle<T>::Circle(T _radius)
		: radius(_radius)
	{

	}

	template<typename T>
	T Circle<T>::area()
	{
		return (radius * radius) * pi;
	}

	template<typename T>
	T Circle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Square<T>::Square(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T Square<T>::area()
	{
		return side * side;
	}

	template<typename T>
	T Square<T>::operator()()
	{
		return area();
	}

	template<typename T>
	RectangularPrism<T>::RectangularPrism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template<typename T>
	T RectangularPrism<T>::area()
	{
		return length * width * height;
	}

	template<typename T>
	T RectangularPrism<T>::operator()()
	{
		return area();
	}

	template<typename T>
	TriangularPrism<T>::TriangularPrism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template<typename T>
	T TriangularPrism<T>::area()
	{
		return (length * width * height) / 2;
	}

	template<typename T>
	T TriangularPrism<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Cone<T>::Cone(T _radius, T _height)
		: radius(_radius), height(_height)
	{

	}

	template<typename T>
	T Cone<T>::area()
	{
		return pi * (radius * radius) * (height / 3);
	}

	template<typename T>
	T Cone<T>::operator()()
	{
		return area();
	}

	template<typename T>
	Cube<T>::Cube(T _face)
		: face(_face)
	{

	}

	template<typename T>
	T Cube<T>::area()
	{
		return face * face * face;
	}

	template<typename T>
	T Cube<T>::operator()()
	{
		return area();
	}
}