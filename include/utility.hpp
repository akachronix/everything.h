#pragma once

#include <type_traits>

namespace brisk
{
	template <class T>
	constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	template <class T>
	constexpr T&& forward(typename std::remove_reference<T>::type&& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	template <class T>
	constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept
	{
		return static_cast<typename std::remove_reference<T>::type&&>(t);
	}

	template <class T, class T2>
	struct pair
	{
		T first;
		T2 second;

		pair() = default;

		pair(T&& x, T2&& y)
			: first(forward<T>(x)), second(forward<T2>(y))
		{
			
		}
	};

	template <class T, class T2>
	pair<T, T2> make_pair(T x, T2 y)
	{
		return pair<T, T2>(x, y);
	}

	template <class T, class T2>
	constexpr pair<T, T2> make_pair(T&& x, T2&& y)
	{
		return pair<T, T2>(forward<T>(x), forward<T2>(y));
	}
}