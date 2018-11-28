#pragma once

#include <cmath>
#include <utility>

namespace brisk
{
	const long double pi = 3.14159265358979323846;

	template<typename T>
	inline T min(const T x, const T y) noexcept
	{
		return (x < y) ? x : y;
	}

	template<typename T>
	inline T max(const T&& x, const T&& y) noexcept
	{
		return (x > y) ? x : y;
	}

	template<typename T = long double>
	class shape
	{
	public:
		virtual T area() =0;
		virtual T operator()() =0;
	};

	template<typename T = long double>
	class trapezoid : public shape<T>
	{
	public:
		T side1, side2, height;

		trapezoid() = default;
		trapezoid(T _side1, T _side2, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class rectangle : public shape<T>
	{
	public:
		T length, width;

		rectangle() = default;
		rectangle(T _length, T _width);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class triangle : public shape<T>
	{
	public:
		T base, height;

		triangle() = default;
		triangle(T _base, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class rhombus : public shape<T>
	{
	public:
		T side;

		rhombus() = default;
		rhombus(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class hexagon : public shape<T>
	{
	public:
		T side;

		hexagon() = default;
		hexagon(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class circle : public shape<T>
	{
	public:
		T radius;

		circle() = default;
		circle(T _radius);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class square : public shape<T>
	{
	public:
		T side;

		square() = default;
		square(T _side);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class rectangular_prism : public shape<T>
	{
	public:
		T length, width, height;

		rectangular_prism() = default;
		rectangular_prism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class triangular_prism : public shape<T>
	{
	public:
		T length, width, height;

		triangular_prism() = default;
		triangular_prism(T _length, T _width, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class cone : public shape<T>
	{
	public:
		T radius, height;

		cone() = default;
		cone(T _radius, T _height);

		T area();
		T operator()();
	};

	template<typename T = long double>
	class cube : public shape<T>
	{
	public:
		T face;

		cube() = default;
		cube(T _face);

		T area();
		T operator()();
	};

	template<typename T>
	trapezoid<T>::trapezoid(T _side1, T _side2, T _height)
		: side1(_side1), side2(_side2), height(_height)
	{

	}

	template<typename T>
	T trapezoid<T>::area()
	{
		return (side1 + side2) / 2 * height;
	}

	template<typename T>
	T trapezoid<T>::operator()()
	{
		return area();
	}

	template<typename T>
	rectangle<T>::rectangle(T _length, T _width)
		: length(_length), width(_width)
	{
	
	}

	template<typename T>
	T rectangle<T>::area()
	{
		return length * width;
	}

	template<typename T>
	T rectangle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	triangle<T>::triangle(T _base, T _height)
		: base(_base), height(_height)
	{

	}

	template<typename T>
	T triangle<T>::area()
	{
		return (base * height) / 2;
	}

	template<typename T>
	T triangle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	rhombus<T>::rhombus(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T rhombus<T>::area()
	{
		return side / 2;
	}

	template<typename T>
	T rhombus<T>::operator()()
	{
		return area();
	}

	template<typename T>
	hexagon<T>::hexagon(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T hexagon<T>::area()
	{
		return 3 * sqrt(3) / 2 * (side * side);
	}

	template<typename T>
	T hexagon<T>::operator()()
	{
		return area();
	}

	template<typename T>
	circle<T>::circle(T _radius)
		: radius(_radius)
	{

	}

	template<typename T>
	T circle<T>::area()
	{
		return (radius * radius) * pi;
	}

	template<typename T>
	T circle<T>::operator()()
	{
		return area();
	}

	template<typename T>
	square<T>::square(T _side)
		: side(_side)
	{

	}

	template<typename T>
	T square<T>::area()
	{
		return side * side;
	}

	template<typename T>
	T square<T>::operator()()
	{
		return area();
	}

	template<typename T>
	rectangular_prism<T>::rectangular_prism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template<typename T>
	T rectangular_prism<T>::area()
	{
		return length * width * height;
	}

	template<typename T>
	T rectangular_prism<T>::operator()()
	{
		return area();
	}

	template<typename T>
	triangular_prism<T>::triangular_prism(T _length, T _width, T _height)
		: length(_length), width(_width), height(_height)
	{

	}

	template<typename T>
	T triangular_prism<T>::area()
	{
		return (length * width * height) / 2;
	}

	template<typename T>
	T triangular_prism<T>::operator()()
	{
		return area();
	}

	template<typename T>
	cone<T>::cone(T _radius, T _height)
		: radius(_radius), height(_height)
	{

	}

	template<typename T>
	T cone<T>::area()
	{
		return pi * (radius * radius) * (height / 3);
	}

	template<typename T>
	T cone<T>::operator()()
	{
		return area();
	}

	template<typename T>
	cube<T>::cube(T _face)
		: face(_face)
	{

	}

	template<typename T>
	T cube<T>::area()
	{
		return face * face * face;
	}

	template<typename T>
	T cube<T>::operator()()
	{
		return area();
	}
}
