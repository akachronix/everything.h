#pragma once

#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <new>

template<typename T>
class Vector
{
private:
	unsigned int m_size;
	T* m_array;

public:
	Vector();
	Vector(unsigned int size);
	Vector(std::initializer_list<T> list);

	Vector(const Vector& v2);

	~Vector();

	// element access functions
	T& operator[](const unsigned int index) noexcept;
	T& at(const unsigned int index);
	T* data() noexcept;
	T& front() noexcept;
	T& back() noexcept;

	// size functions
	unsigned int size() const noexcept;
	unsigned int bytes() const noexcept;
	bool empty() const noexcept;

	// iterator functions
	T* begin() noexcept;
	T* end() noexcept;
	T* cbegin() const noexcept;
	T* cend() const noexcept;
	std::reverse_iterator<T*> rbegin() noexcept;
	std::reverse_iterator<T*> rend() noexcept;
	std::reverse_iterator<const T*> crbegin() const noexcept;
	std::reverse_iterator<const T*> crend() const noexcept;

	// element modifying functions
	template<class... Args> void emplace_back(Args&&... args);
	void push_back(T new_element);
	void pop_back();
};

template<typename T>
Vector<T>::Vector()
	: m_size(0), m_array(nullptr)
{

}

template<typename T>
Vector<T>::Vector(unsigned int size)
	: m_size(size)
{
	m_array = new T[size];
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
	: Vector(list.size())
{
	int i = 0;

	for (auto& element : list)
	{
		m_array[i] = element;
		++i;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& v2)
{
	m_size = v2.m_size;
	m_array = new T[v2.m_size];

	for (unsigned int i = 0; i < v2.m_size; ++i)
		m_array[i] = v2.m_array[i];
}

template<typename T>
Vector<T>::~Vector()
{
	if (m_array != nullptr)
		delete[] m_array;
}

template<typename T>
T& Vector<T>::operator[](const unsigned int index) noexcept
{
	return m_array[index];
}

template<typename T>
T& Vector<T>::at(const unsigned int index)
{
	if (index >= m_size)
		throw std::out_of_range("vector::at(const unsigned int)");

	return m_array[index];
}

template<typename T>
T* Vector<T>::data() noexcept
{
	return m_array;
}

template<typename T>
T& Vector<T>::front() noexcept
{
	return m_array[0];
}

template<typename T>
T& Vector<T>::back() noexcept
{
	return m_array[m_size];
}

template<typename T>
unsigned int Vector<T>::size() const noexcept
{
	return m_size;
}

template<typename T>
unsigned int Vector<T>::bytes() const noexcept
{
	return m_size * sizeof(T);
}

template<typename T>
bool Vector<T>::empty() const noexcept
{
	if (m_array == nullptr | m_size == 0)
		return true;

	return false;
}

template<typename T>
T* Vector<T>::begin() noexcept
{
	return &m_array[0];
}

template<typename T>
T* Vector<T>::end() noexcept
{
	return &m_array[m_size];
}

template<typename T>
T* Vector<T>::cbegin() const noexcept
{
	return &m_array[0];
}

template<typename T>
T* Vector<T>::cend() const noexcept
{
	return &m_array[m_size];
}

template<typename T>
std::reverse_iterator<T*> Vector<T>::rbegin() noexcept
{
	return std::reverse_iterator<T*>(&m_array[m_size]);
}

template<typename T>
std::reverse_iterator<T*> Vector<T>::rend() noexcept
{
	return std::reverse_iterator<T*>(&m_array[0]);
}

template<typename T>
std::reverse_iterator<const T*> Vector<T>::crbegin() const noexcept
{
	return std::reverse_iterator<const T*>(&m_array[m_size]);
}

template<typename T>
std::reverse_iterator<const T*> Vector<T>::crend() const noexcept
{
	return std::reverse_iterator<const T*>(&m_array[0]);
}

template<typename T>
template<class... Args>
void Vector<T>::emplace_back(Args&&... args)
{
	T* buffer = new T[m_size + 1];

	for (unsigned int i = 0; i < m_size; ++i)
		buffer[i] = m_array[i];
	buffer[m_size] = std::move(T(std::forward<Args>(args)...));

	delete[] m_array;

	m_array = new T[m_size + 1];

	for (unsigned int i = 0; i < m_size + 1; ++i)
		m_array[i] = buffer[i];

	delete[] buffer;

	m_size += 1;
}

template<typename T>
void Vector<T>::push_back(T new_element)
{
	T* buffer = new T[m_size + 1];

	for (unsigned int i = 0; i < m_size; ++i)
		buffer[i] = m_array[i];
	buffer[m_size] = new_element;

	delete[] m_array;

	for (unsigned int i = 0; i < m_size + 1; ++i)
		m_array[i] = buffer[i];

	delete[] buffer;

	m_size += 1;
}

template<typename T>
void Vector<T>::pop_back()
{
	T* buffer = new T[m_size - 1];

	for (unsigned int i = 0; i < (m_size - 1); ++i)
		buffer[i] = m_array[i];

	delete[] m_array;

	for (unsigned int i = 0; i < (m_size - 1); ++i)
		m_array[i] = buffer[i];

	delete[] buffer;

	m_size -= 1;
}