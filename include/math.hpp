#pragma once

#include <cmath>

namespace brisk
{
	const long double pi = 3.14159265358979323846;

	template <class T = long double>
	class trapezoid
	{
	public:
		T side1, side2, height;

		trapezoid() = default;
		trapezoid(T _side1, T _side2, T _height);

		T area();
		T operator()();
	};

	template <class T = long double>
	class rectangle
	{
	public:
		T length, width;

		rectangle() = default;
		rectangle(T _length, T _width);

		T area();
		T operator()();
	};

	template <class T = long double>
	class triangle
	{
	public:
		T base, height;

		triangle() = default;
		triangle(T _base, T _height);

		T area();
		T operator()();
	};

	template <class T = long double>
	class rhombus
	{
	public:
		T side;

		rhombus() = default;
		rhombus(T _side);

		T area();
		T operator()();
	};

	template <class T = long double>
	class hexagon
	{
	public:
		T side;

		hexagon() = default;
		hexagon(T _side);

		T area();
		T operator()();
	};

	template <class T = long double>
	class circle
	{
	public:
		T radius;

		circle() = default;
		circle(T _radius);

		T area();
		T operator()();
	};

	template <class T = long double>
	class square
	{
	public:
		T side;

		square() = default;
		square(T _side);

		T area();
		T operator()();
	};

	template <class T = long double>
	class rectangular_prism
	{
	public:
		T length, width, height;

		rectangular_prism() = default;
		rectangular_prism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template <class T = long double>
	class triangular_prism
	{
	public:
		T length, width, height;

		triangular_prism() = default;
		triangular_prism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template <class T = long double>
	class cone
	{
	public:
		T radius, height;

		cone() = default;
		cone(T _radius, T _height);

		T area();
		T operator()();
	};

	template <class T = long double>
	class cube
	{
	public:
		T face;

		cube() = default;
		cube(T _face);

		T area();
		T operator()();
	};

	template <class T>
	trapezoid<T>::trapezoid(T _side1, T _side2, T _height)
		: side1(_side1), side2(_side2), height(_height)
	{

	}

	template <class T>
	T trapezoid<T>::area()
	{
		return (side1 + side2) / 2 * height;
	}

	template <class T>
	T trapezoid<T>::operator()()
	{
		return area();
	}

	template <class T>
	rectangle<T>::rectangle(T _length, T _width)
		: length(_length), width(_width)
	{
	
	}

	template <class T>
	T rectangle<T>::area()
	{
		return length * width;
	}

	template <class T>
	T rectangle<T>::operator()()
	{
		return area();
	}

	template <class T>
	triangle<T>::triangle(T _base, T _height)
		: base(_base), height(_height)
	{

	}

	template <class T>
	T triangle<T>::area()
	{
		return (base * height) / 2;
	}

	template <class T>
	T triangle<T>::operator()()
	{
		return area();
	}

	template <class T>
	rhombus<T>::rhombus(T _side)
		: side(_side)
	{

	}

	template <class T>
	T rhombus<T>::area()
	{
		return side / 2;
	}

	template <class T>
	T rhombus<T>::operator()()
	{
		return area();
	}

	template <class T>
	hexagon<T>::hexagon(T _side)
		: side(_side)
	{

	}

	template <class T>
	T hexagon<T>::area()
	{
		return 3 * sqrt(3) / 2 * (side * side);
	}

	template <class T>
	T hexagon<T>::operator()()
	{
		return area();
	}

	template <class T>
	circle<T>::circle(T _radius)
		: radius(_radius)
	{

	}

	template <class T>
	T circle<T>::area()
	{
		return (radius * radius) * pi;
	}

	template <class T>
	T circle<T>::operator()()
	{
		return area();
	}

	template <class T>
	square<T>::square(T _side)
		: side(_side)
	{

	}

	template <class T>
	T square<T>::area()
	{
		return side * side;
	}

	template <class T>
	T square<T>::operator()()
	{
		return area();
	}

	template <class T>
	rectangular_prism<T>::rectangular_prism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template <class T>
	T rectangular_prism<T>::area()
	{
		return length * width * height;
	}

	template <class T>
	T rectangular_prism<T>::operator()()
	{
		return area();
	}

	template <class T>
	triangular_prism<T>::triangular_prism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template <class T>
	T triangular_prism<T>::area()
	{
		return (length * width * height) / 2;
	}

	template <class T>
	T triangular_prism<T>::operator()()
	{
		return area();
	}

	template <class T>
	cone<T>::cone(T _radius, T _height)
		: radius(_radius), height(_height)
	{

	}

	template <class T>
	T cone<T>::area()
	{
		return pi * (radius * radius) * (height / 3);
	}

	template <class T>
	T cone<T>::operator()()
	{
		return area();
	}

	template <class T>
	cube<T>::cube(T _face)
		: face(_face)
	{

	}

	template <class T>
	T cube<T>::area()
	{
		return face * face * face;
	}

	template <class T>
	T cube<T>::operator()()
	{
		return area();
	}
}
