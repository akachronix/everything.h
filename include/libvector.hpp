#pragma once

#include <initializer_list>
#include <iterator>
#include <utility>
#include <new>

#include <exception>

class OutOfRange : public std::exception
{
private:
	const char* m_msg;
	const unsigned int m_index;
	const unsigned int m_size;

public:
	OutOfRange(const char* msg, const unsigned int index, const unsigned int size)
		: m_msg(msg), m_index(index), m_size(size)
	{
		
	}

	const char* what() const throw()
	{
		return "OutOfRange";
	}

	const char* msg() const noexcept
	{
		return m_msg;
	}

	const unsigned int index() const noexcept
	{
		return m_index;
	}

	const unsigned int size() const noexcept
	{
		return m_size;
	}
};

class BadAlloc : public std::exception
{
private:
	const char* m_msg;
	const unsigned int m_size;

public:
	BadAlloc(const char* msg, const unsigned int size)
		: m_msg(msg), m_size(size)
	{

	}

	const char* what() const throw()
	{
		return "BadAlloc";
	}

	const char* msg() const noexcept
	{
		return m_msg;
	}

	const unsigned int size() const noexcept
	{
		return m_size;
	}
};

template<typename T>
class Vector
{
private:
	unsigned int m_size;
	T* m_array;

public:
	Vector()
		: m_size(0), m_array(nullptr)
	{

	}

	Vector(unsigned int size)
		: m_size(size)
	{
		m_array = new(std::nothrow) T[size];

		if (m_array == nullptr)
			throw BadAlloc("Error while allocating memory.", size);
	}
	
	Vector(std::initializer_list<T> list)
		: Vector(list.size())
	{
		int i = 0;

		for (auto& element : list)
		{
			m_array[i] = element;
			++i;
		}
	}

	Vector(const Vector& v2)
	{
		m_size = v2.m_size;
		m_array = new(std::nothrow) T[v2.m_size];

		if (m_array == nullptr)
			throw BadAlloc("Error while copying memory.", v2.m_size);

		for (unsigned int i = 0; i < v2.m_size; ++i)
			m_array[i] = v2.m_array[i];
	}

	~Vector()
	{
		if (m_array != nullptr)
			delete[] m_array;
	}

	T& operator[](const unsigned int index) noexcept
	{
		return m_array[index];
	}
	
	T& at(const unsigned int index)
	{
		if (index >= m_size)
			throw OutOfRange("Index is out of range.", index, m_size);
		
		return m_array[index];
	}

	T* data() noexcept
	{
		return m_array;
	}

	T& front() noexcept
	{
		return m_array[0];
	}

	T& back() noexcept
	{
		return m_array[m_size];
	}

	unsigned int size() const noexcept
	{
		return m_size;
	}

	unsigned int bytes() const noexcept
	{
		return m_size * sizeof(T);
	}

	bool empty() const noexcept
	{
		if (m_array == nullptr | m_size == 0)
			return true;
		
		return false;
	}

	T* begin() noexcept
	{
		return &m_array[0];
	}

	T* end() noexcept
	{
		return &m_array[m_size];
	}

	T* cbegin() const noexcept
	{
		return &m_array[0];
	}

	T* cend() const noexcept
	{
		return &m_array[m_size];
	}

	std::reverse_iterator<T*> rbegin() noexcept
	{
		return std::reverse_iterator<T*>(&m_array[m_size]);
	}

	std::reverse_iterator<T*> rend() noexcept
	{
		return std::reverse_iterator<T*>(&m_array[0]);
	}

	std::reverse_iterator<const T*> crbegin() const noexcept
	{
		return std::reverse_iterator<const T*>(&m_array[m_size]);
	}

	std::reverse_iterator<const T*> crend() const noexcept
	{
		return std::reverse_iterator<const T*>(&m_array[0]);
	}

	void push_back(T new_element)
	{
		T* buffer = new(std::nothrow) T[m_size + 1];

		if (buffer == nullptr)
			throw BadAlloc("Error allocating memory for buffer.", m_size + 1);
		
		for (unsigned int i = 0; i < m_size; ++i)
			buffer[i] = m_array[i];
		buffer[m_size] = new_element;

		delete[] m_array;

		m_array = new(std::nothrow) T[m_size + 1];
		
		if (m_array == nullptr)
			throw BadAlloc("Error allocating memory for new array.", m_size + 1);

		for (unsigned int i = 0; i < m_size + 1; ++i)
			m_array[i] = buffer[i];

		delete[] buffer;

		m_size += 1;
	}

	template<class... Args>
	void emplace_back(Args&&... args)
	{
		T* buffer = new(std::nothrow) T[m_size + 1];

		if (buffer == nullptr)
			throw BadAlloc("Error allocating memory for buffer.", m_size + 1);
		
		for (unsigned int i = 0; i < m_size; ++i)
			buffer[i] = m_array[i];
		buffer[m_size] = std::move( T(std::forward<Args>(args)...) );

		delete[] m_array;

		m_array = new(std::nothrow) T[m_size + 1];
		
		if (m_array == nullptr)
			throw BadAlloc("Error allocating memory for new array.", m_size + 1);

		for (unsigned int i = 0; i < m_size + 1; ++i)
			m_array[i] = buffer[i];

		delete[] buffer;

		m_size += 1;
	}

	void pop_back()
	{
		T* buffer = new(std::nothrow) T[m_size - 1];

		if (buffer == nullptr)
			throw BadAlloc("Error allocating memory for buffer.", m_size - 1);

		for (unsigned int i = 0; i < (m_size - 1); ++i)
			buffer[i] = m_array[i];
		
		delete[] m_array;

		m_array = new(std::nothrow) T[m_size - 1];
		
		if (m_array == nullptr)
			throw BadAlloc("Error allocating memory for new array.", m_size - 1);

		for (unsigned int i = 0; i < (m_size - 1); ++i)
			m_array[i] = buffer[i];
		
		delete[] buffer;

		m_size -= 1;
	}
};