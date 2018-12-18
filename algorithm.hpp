#pragma once

#include "array.hpp"
#include "vector.hpp"

namespace brisk
{
	template <class Iterator, class Function, class... Args>
	Function for_each(Iterator first, Iterator last, Function f, Args... args)
	{
		for (; first != last; ++first)
			f(*first, args...);
		
		return f;
	}

	template <class Iterator, class Function> 
	Function for_each(Iterator first, Iterator last, Function f)
	{
		for (; first != last; ++first)
			f(*first);
		
		return f;
	}

	template <class T>
	vector<T> copy(vector<T>& v)
	{
		vector<T> v2(v.size());
		for (size_t i = 0; i < v.size(); ++i)
			v2[i] = v[i];

		return v2;
	}

	template <class T, size_t _Size>
	vector<T> copy(array<T, _Size>& a)
	{
		vector<T> v(a.size());
		for (size_t i = 0; i < a.size(); ++i)
			v[i] = a[i];
		
		return v;
	}

	template <class T>
	void copy(vector<T>& v, vector<T>& v2)
	{
		v2.resize(v.size());
		for (size_t i = 0; i < v.size(); ++i)
			v2[i] = v[i];
	}

	template <class T, size_t _Size>
	void copy(array<T, _Size>& a, vector<T>& v)
	{
		v.resize(a.size());
		for (size_t i = 0; i < a.size(); ++i)
			v[i] = a[i];
	}

	template <class T>
	inline const T& min(const T& x, const T& y) noexcept
	{
		return (x < y) ? x : y;
	}

	template <class T>
	inline const T& max(const T& x, const T& y) noexcept
	{
		return (x > y) ? x : y;
	}
}
