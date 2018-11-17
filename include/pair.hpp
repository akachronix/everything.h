#pragma once

namespace brisk
{
	template<typename T, typename T2>
	struct pair
	{
		T first;
		T2 second;

		pair() = default;
		explicit pair(T _first, T2 _second);
	};

	template<typename T, typename T2>
	pair<T, T2>::pair(T _first, T2 _second)
		: first(_first), second(_second)
	{

	}
}