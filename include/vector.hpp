#pragma once

#include <cstring>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <initializer_list>

template<typename T>
class Vector
{
private:
	unsigned long long m_elements;
	unsigned long long m_size;
	T* m_array;

	inline void realloc();

public:
	// Default constructor (sets m_elements to 0, and m_size = 4)
	Vector();

	// Constructor that allocates vector based on size argument
	Vector(unsigned long long size);

	// Constructor that allocates and fills vector from std::initalizer_list
	Vector(std::initializer_list<T> list);
	
	// Copy constructor (copies all elements and allocates new array for other object)
	Vector(const Vector& v2);

	// Destructor (frees the array)
	~Vector();

	// Assignment operator (copies object's content)
	Vector<T>& operator=(const Vector& v2);

	// operator[], returns a T& to an element at an index
	T& operator[](const unsigned long long index) noexcept;
	const T& operator[](const unsigned long long index) const noexcept;

	// same as operator[], but has bounds-checking
	T& at(const unsigned long long index);
	const T& at(const unsigned long long index) const;

	// Returns a reference to the first element
	T& front() noexcept;
	const T& front() const noexcept;

	// Returns a reference to the last element
	T& back() noexcept;
	const T& back() const noexcept;

	// Returns a pointer to the array used for storage
	T* data() noexcept;
	const T* data() const noexcept;

	// Constructs object in-place with arguments
	template<class... Args> void emplace_back(Args&&... args);

	// Pushes back a new element with value provided
	void push_back(const T& value);

	// Overload of push_back(const T&) that optimizes if the value is movable
	void push_back(const T&& value);

	// Pops (deletes) last element in storage
	void pop_back();

	// Returns the allocated size of the array
	unsigned long long capacity() const noexcept;

	// Returns the allocated size of the array, in bytes
	unsigned long long capacity_bytes() const noexcept;

	// Returns the number of elements in the array
	unsigned long long size() const noexcept;

	// Returns the number of elements in the array, in bytes
	unsigned long long size_bytes() const noexcept;

	// Returns true if array is empty
	bool empty() const noexcept;

	// Resizes the amount of allocated storage, elements are destroyed past size
	void resize(unsigned long long size);

	// Changes the amount of reserved storage for the array
	void reserve(unsigned long long size);

	// Shrinks the amount of allocated storage to perfectly fit the elements
	void shrink_to_fit();

	// Iterator that returns a pointer to the beginning of the array
	T* begin() noexcept;

	// Iterator that returns a pointer to the end of the array
	T* end() noexcept;

	// Constant iterator that returns a pointer to the beginning of the array
	const T* cbegin() const noexcept;

	// Constant iterator that returns a pointer to the end of the array
	const T* cend() const noexcept;

	// Iterator that returns a std::reverse_iterator<T*> to the "beginning" of the array
	std::reverse_iterator<T*> rbegin() noexcept;

	// Iterator that returns a std::reverse_iterator<T*> to the "end" of the array
	std::reverse_iterator<T*> rend() noexcept;

	// Constant iterator that returns a std::reverse_iterator<T*> to the "beginning" of the array
	std::reverse_iterator<const T*> crbegin() const noexcept;

	// Constant iterator that returns a std::reverse_iterator<T*> to the "end" of the array
	std::reverse_iterator<const T*> crend() const noexcept;
};

template<typename T>
inline void Vector<T>::realloc()
{
	T* buffer = new T[m_size];
	std::memcpy(buffer, m_array, m_elements * sizeof(T));
	delete[] m_array;
	
	m_array = buffer;
}

template<typename T>
Vector<T>::Vector()
	: m_elements(0), m_size(4)
{
	realloc();
}

template<typename T>
Vector<T>::Vector(unsigned long long size)
	: m_elements(size), m_size(size << 2)
{
	m_array = new T[m_size];
	for (unsigned long long i = 0; i < size; ++i)
		m_array[i] = T();
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
	: m_elements(list.size()), m_size(list.size() * 2)
{
	realloc();

	unsigned int i = 0;
	for (auto it : list)
	{
		m_array[i] = it;
		++i;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& v2)
	: m_elements(v2.m_elements), m_size(v2.m_size)
{
	m_array = new T[m_size];
	std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(T));
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& v2)
{
	m_elements = v2.m_elements;
	m_size = v2.m_size;

	m_array = new T[m_size];
	std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(T));
}

template<typename T>
Vector<T>::~Vector()
{
	if (m_array != nullptr)
		delete[] m_array;
}

#if 0
template<>
Vector<std::string>::~Vector()
{
}
#endif

template<typename T>
T& Vector<T>::operator[](const unsigned long long index) noexcept
{
	return m_array[index];
}

template<typename T>
const T& Vector<T>::operator[](const unsigned long long index) const noexcept
{
	return m_array[index];
}

template<typename T>
T& Vector<T>::at(const unsigned long long index)
{
	if (index > m_size)
		throw std::out_of_range("T& Vector<T>::at(unsigned long long index)");

	return m_array[index];
}

template<typename T>
const T& Vector<T>::at(const unsigned long long index) const
{
	if (index > m_size)
		throw std::out_of_range("const T& Vector<T>::at(const unsigned long long index)");
}

template<typename T>
T& Vector<T>::front() noexcept
{
	return m_array[0];
}

template<typename T>
const T& Vector<T>::front() const noexcept
{
	return m_array[0];
}

template<typename T>
T& Vector<T>::back() noexcept
{
	return m_array[m_elements - 1];
}

template<typename T>
const T& Vector<T>::back() const noexcept
{
	return m_array[m_elements - 1];
}

template<typename T>
T* Vector<T>::data() noexcept
{
	return m_array;
}

template<typename T>
const T* Vector<T>::data() const noexcept
{
	return m_array;
}

template<typename T>
template<class... Args>
void Vector<T>::emplace_back(Args&&... args)
{
	if (m_elements == m_size)
	{
		m_size <<= 2;
		realloc();
	}

	m_array[m_elements] = std::move( T (std::forward<Args>(args)...) );
	++m_elements;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
	if (m_elements == m_size)
	{
		m_size <<= 2;
		realloc();
	}

	m_array[m_elements] = value;
	++m_elements;
}

template<typename T>
void Vector<T>::push_back(const T&& value)
{
	if (m_elements == m_size)
	{
		m_size <<= 2;
		realloc();
	}

	m_array[m_elements] = std::move(value);
	++m_elements;
}

template<typename T>
void Vector<T>::pop_back()
{
	--m_elements;
	m_array[m_elements].~T();
}

template<typename T>
unsigned long long Vector<T>::capacity() const noexcept
{
	return m_size;
}

template<typename T>
unsigned long long Vector<T>::capacity_bytes() const noexcept
{
	return m_size * sizeof(T);
}

template<typename T>
unsigned long long Vector<T>::size() const noexcept
{
	return m_elements;
}

template<typename T>
unsigned long long Vector<T>::size_bytes() const noexcept
{
	return m_elements * sizeof(T);
}

template<typename T>
bool Vector<T>::empty() const noexcept
{
	if (m_elements == 0)
		return true;

	return false;
}

template<typename T>
void Vector<T>::resize(unsigned long long size)
{
	if (size > m_size)
	{
		m_size = size;
		realloc();
	}

	m_elements = size;
}

template<typename T>
void Vector<T>::reserve(unsigned long long size)
{
	if (size > m_size)
	{
		m_size = size;
		realloc();
	}
}

template<typename T>
void Vector<T>::shrink_to_fit()
{
	m_size = m_elements;
	realloc();
}

template<typename T>
T* Vector<T>::begin() noexcept
{
	return &m_array[0];
}

template<typename T>
T* Vector<T>::end() noexcept
{
	return &m_array[m_elements];
}

template<typename T>
const T* Vector<T>::cbegin() const noexcept
{
	return &m_array[0];
}

template<typename T>
const T* Vector<T>::cend() const noexcept
{
	return &m_array[m_elements];
}

template<typename T>
std::reverse_iterator<T*> Vector<T>::rbegin() noexcept
{
	return std::reverse_iterator<T*>(&m_array[m_elements]);
}

template<typename T>
std::reverse_iterator<T*> Vector<T>::rend() noexcept
{
	return std::reverse_iterator<T*>(&m_array[0]);
}

template<typename T>
std::reverse_iterator<const T*> Vector<T>::crbegin() const noexcept
{
	return std::reverse_iterator<const T*>(&m_array[m_elements]);
}

template<typename T>
std::reverse_iterator<const T*> Vector<T>::crend() const noexcept
{
	return std::reverse_iterator<const T*>(&m_array[0]);
}