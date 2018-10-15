#pragma once

template<class _T>
class SmartPtr
{
public:
	SmartPtr(_T* _ptr);
	~SmartPtr();

	_T* get();

private:
	_T* m_ptr;
};

template<class _T>
SmartPtr<_T>::SmartPtr(_T* _ptr)
	: m_ptr(_ptr)
{

}

template<class _T>
SmartPtr<_T>::~SmartPtr()
{
	delete m_ptr;
}

template<class _T>
_T* SmartPtr<_T>::get()
{
	return m_ptr;
}