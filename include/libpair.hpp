#pragma once

#include <utility>

namespace libpair
{
	template<class _T, class _T2> 
	class Pair
	{
	public:
		Pair(_T _first, _T2 _second, const char* _name);
		Pair(_T _first, _T2 _second);
		
		~Pair();

		const char* name();

		_T first();
		_T2 second();

		void setFirst(_T _first);
		void setSecond(_T2 _second);

		void set(_T _first, _T2 _second);

		void log();

		// returns RAW pair, meant to be used with auto
		std::pair<_T, _T2> copy();

	private:
		//std::pair<_T, _T2> m_pair;
		_T m_first;
		_T2 m_second;
		const char* m_name;
	};

	template<class _T, class _T2>
	Pair<_T, _T2>::Pair(_T _first, _T2 _second, const char* _name)
		: m_first(_first), m_second(_second), m_name(_name)
	{
		// constructor
	}

	template<class _T, class _T2>
	Pair<_T, _T2>::Pair(_T _first, _T2 _second)
		: m_first(_first), m_second(_second), m_name("Pair")
	{
		// constructor
	}

	template<class _T, class _T2>
	Pair<_T, _T2>::~Pair()
	{
		// default deconstructor
	}

	template<class _T, class _T2>
	const char* Pair<_T, _T2>::name() 
	{
		return m_name;
	}

	template<class _T, class _T2>
	_T Pair<_T, _T2>::first() 
	{
		return m_first;
	}

	template<class _T, class _T2>
	_T2 Pair<_T, _T2>::second() 
	{
		return m_second;
	}

	template<class _T, class _T2>
	void Pair<_T, _T2>::setFirst(_T _first)
	{
		m_first = _first;
	}

	template<class _T, class _T2>
	void Pair<_T, _T2>::setSecond(_T2 _second)
	{
		m_second = _second;
	}

	template<class _T, class _T2>
	void Pair<_T, _T2>::set(_T _first, _T2 _second)
	{
		m_first = _first;
		m_second = _second;
	}

	template<class _T, class _T2>
	void Pair<_T, _T2>::log() 
	{
		std::cout << m_name << ".first: " << m_first << '\n' << m_name << ".second: " << m_second << '\n';
	}

	template<class _T, class _T2>
	std::pair<_T, _T2> Pair<_T, _T2>::copy() 
	{
		return std::make_pair(m_first, m_second);
	}
}