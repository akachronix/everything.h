#pragma once

#include "array.hpp"
#include "vector.hpp"

namespace brisk
{
	template<typename T>
	vector<T> copy(vector<T>& v)
	{
		vector<T> v2(v.size());
		for (int i = 0; i < v.size(); ++i)
			v2[i] = v[i];

		return v2;
	}

	template<typename T, size_t _Size>
	vector<T> copy(array<T, _Size>& a)
	{
		vector<T> v(a.size());
		for (int i = 0; i < a.size(); ++i)
			v[i] = a[i];
		
		return v;
	}

	template<typename T>
	void copy(vector<T>& v, vector<T>& v2)
	{
		v2.resize(v.size());
		for (int i = 0; i < v.size(); ++i)
			v2[i] = v[i];
	}

	template<typename T, size_t _Size>
	void copy(array<T, _Size>& a, vector<T>& v)
	{
		v.resize(a.size());
		for (int i = 0; i < a.size(); ++i)
			v[i] = a[i];
	}
}