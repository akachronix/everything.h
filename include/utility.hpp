#pragma once

#include <type_traits>

namespace brisk
{
	template<typename T>
	constexpr T&& forward(typename std::remove_reference<T>::type& t) noexcept
	{
		return static_cast<T&&>(t);
	}

	template<typename T>
	constexpr T&& forward(typename std::remove_reference<T>::type&& t)
	{
		return static_cast<T&&>(t);
	}

	template<typename T, typename T2>
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

	template<typename T, typename T2>
	pair<T, T2> make_pair(T&& x, T2&& y)
	{
		return pair<T, T2>(forward<T>(x), forward<T2>(y));
	}
}