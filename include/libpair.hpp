#pragma once

template<class _T, class _T2> 
class Pair
{
public:
	Pair(_T x, _T2 y, const char* _name);
	Pair(_T x, _T2 y);
	
	~Pair();

	const char* name();

	_T first();
	_T2 second();

	void log();

	// returns RAW pair, meant to be used with auto
	std::pair<_T, _T2> copy();

private:
	std::pair<_T, _T2> m_pair;
	const char* m_name;
};

template<class _T, class _T2>
Pair<_T, _T2>::Pair(_T x, _T2 y, const char* _name)
	: m_pair(std::make_pair(x, y)), m_name(_name) 
{
	// constructor
}

template<class _T, class _T2>
Pair<_T, _T2>::Pair(_T x, _T2 y)
	: m_pair(std::make_pair(x, y)), m_name("Pair") 
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
	return m_pair.first;
}

template<class _T, class _T2>
_T2 Pair<_T, _T2>::second() 
{
	return m_pair.second;
}

template<class _T, class _T2>
void Pair<_T, _T2>::log() 
{
	std::cout << m_name << ".first: " << m_pair.first << '\n' << m_name << ".second: " << m_pair.second << '\n';
}

template<class _T, class _T2>
std::pair<_T, _T2> Pair<_T, _T2>::copy() 
{
	return std::make_pair(this->first(), this->second());
}