#pragma once

#include "array.hpp"
#include "vector.hpp"
#include "utility.hpp"

namespace brisk
{
	template <class Iterator, class T>
	constexpr void fill(Iterator first, Iterator last, const T&& value)
	{
		for (; first != last; ++first)
			*first = brisk::move(value);
	}

	template <class Iterator, class Size, class T>
	constexpr Iterator fill_n(Iterator first, Size count, const T&& value)
	{
		for (Size i = 0; i < count; i++)
			*first++ = brisk::move(value);
		
		return first;
	}

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

	template <class Iterator, class T>
	T accumulate(Iterator first, Iterator last, T init)
	{
		for (; first != last; ++first)
			init = brisk::move(init) + *first;
		
		return init;
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

	template <class Container>
	auto begin(Container& c) -> decltype(c.begin())
	{
		return c.begin();
	}

	template <class Container>
	auto end(Container& c) -> decltype(c.end())
	{
		return c.end();
	}

	template <class Container>
	auto cbegin(Container& c) -> decltype(c.cbegin())
	{
		return c.cbegin();
	}

	template <class Container>
	auto cend(Container& c) -> decltype(c.cend())
	{
		return c.cend();
	}

	template <class Container>
	auto rbegin(Container& c) -> decltype(c.rbegin())
	{
		return c.rbegin();
	}

	template <class Container>
	auto rend(Container& c) -> decltype(c.rend())
	{
		return c.rend();
	}

	template <class Container>
	auto crbegin(Container& c) -> decltype(c.crbegin())
	{
		return c.crbegin();
	}

	template <class Container>
	auto crend(Container& c) -> decltype(c.crend())
	{
		return c.crend();
	}
}
