#pragma once

template<class _T>
class Calculator
{
public:
	Calculator();
	~Calculator();

	Calculator(_T _x, _T _y);

	_T add();
	_T subtract();
	_T multiply();
	_T divide();
	_T power();

	_T getX();
	_T getY();

	void setX(_T _x);
	void setY(_T _y);

	void set(_T _x, _T _y);

private:
	_T m_x;
	_T m_y;
};

template<class _T>
Calculator<_T>::Calculator()
	: m_x(0), m_y(0)
{

}

template<class _T>
Calculator<_T>::~Calculator()
{

}

template<class _T>
Calculator<_T>::Calculator(_T _x, _T _y)
	: m_x(_x), m_y(_y)
{
	
}

template<class _T>
_T Calculator<_T>::add()
{
	return m_x + m_y;
}

template<class _T>
_T Calculator<_T>::subtract()
{
	return m_x - m_y;
}

template<class _T>
_T Calculator<_T>::multiply()
{
	return m_x * m_y;
}

template<class _T>
_T Calculator<_T>::divide()
{
	return m_x / m_y;
}

template<class _T>
_T Calculator<_T>::power()
{
	double answer = m_x;

	for (int i = 1; i < m_y; i++)
	{
		answer *= m_x;
	}

	return answer;
}

template<class _T>
_T Calculator<_T>::getX()
{
	return m_x;
}

template<class _T>
_T Calculator<_T>::getY()
{
	return m_y;
}

template<class _T>
void Calculator<_T>::setX(_T _x)
{
	m_x = _x;
}

template<class _T>
void Calculator<_T>::setY(_T _y)
{
	m_y = _y;
}

template<class _T>
void Calculator<_T>::set(_T _x, _T _y)
{
	m_x = _x;
	m_y = _y;
}