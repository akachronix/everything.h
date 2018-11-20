#pragma once

#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <cstring>

namespace brisk
{
	template<typename T>
	class vector
	{
	private:
		unsigned long long m_elements;
		unsigned long long m_size;
		T* m_array;

	public:
		vector();
		explicit vector(const unsigned long long size);
		vector(const std::initializer_list<T> list);
		vector(T* const begin, T* const end);
		vector(const vector& v2);

		~vector();

		vector<T>& operator=(const vector& v2);

		T& operator[](const unsigned long long index) noexcept;
		const T& operator[](const unsigned long long index) const noexcept;

		T& at(const unsigned long long index);
		const T& at(const unsigned long long index) const;

		T& front() noexcept;
		const T& front() const noexcept;

		T& back() noexcept;
		const T& back() const noexcept;

		T* data() noexcept;
		const T* data() const noexcept;

		template<class... Args>
		void emplace_back(Args&&... args);
		
		void push_back(const std::initializer_list<T>&& list);
		void push_back(const T& value);
		void push_back(const T&& value);
		void pop_back();

		unsigned long long capacity() const noexcept;
		unsigned long long capacity_bytes() const noexcept;

		unsigned long long size() const noexcept;
		unsigned long long size_bytes() const noexcept;

		bool empty() const noexcept;

		void resize(unsigned long long size);
		void reserve(unsigned long long size);
		void shrink_to_fit();

		T* begin() noexcept;
		T* end() noexcept;

		const T* cbegin() const noexcept;
		const T* cend() const noexcept;

		std::reverse_iterator<T*> rbegin() noexcept;
		std::reverse_iterator<T*> rend() noexcept;

		std::reverse_iterator<const T*> crbegin() const noexcept;
		std::reverse_iterator<const T*> crend() const noexcept;
	};

	// Default constructor (sets m_elements to 0, and m_size = 4)
	template<typename T>
	vector<T>::vector()
		: m_elements(0), m_size(4)
	{
		m_array = new T[m_size];
	}

	// Constructor that allocates vector based on size argument
	template<typename T>
	vector<T>::vector(const unsigned long long size)
		: m_elements(size), m_size(size << 2)
	{
		m_array = new T[m_size];
	}

	// Constructor that allocates and fills vector from std::initalizer_list
	template<typename T>
	vector<T>::vector(const std::initializer_list<T> list)
		: m_elements(list.size()), m_size(list.size() * 2)
	{
		m_array = new T[m_size];

		unsigned int i = 0;
		for (auto it : list)
		{
			m_array[i] = it;
			++i;
		}
	}

	// Constructor that constructs an object with elements from an iterator
	template<typename T>
	vector<T>::vector(T* const begin, T* const end)
		: m_elements(0), m_size(0)
	{
		for (T* it = begin; it != end; ++it)
			++m_elements;

		m_size = m_elements << 2;
		m_array = new T[m_size];

		for (unsigned long long i = 0; i < m_elements; ++i)
			m_array[i] = *(begin + i);
	}

	// Copy constructor (copies all elements and allocates new array for other object)
	template<typename T>
	vector<T>::vector(const vector& v2)
		: m_elements(v2.m_elements), m_size(v2.m_size)
	{
		m_array = new T[m_size];
		std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(T));
	}

	// Destructor (frees the array)
	template<typename T>
	vector<T>::~vector()
	{
		if (m_array != nullptr)
			delete[] m_array;
	}

	// Assignment operator (copies object's content)
	template<typename T>
	vector<T>& vector<T>::operator=(const vector& v2)
	{
		m_elements = v2.m_elements;
		m_size = v2.m_size;

		m_array = new T[m_size];
		std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(T));
	}

	// operator[], returns a T& to an element at an index
	template<typename T>
	T& vector<T>::operator[](const unsigned long long index) noexcept
	{
		return m_array[index];
	}

	// Same as above, but works with const objects
	template<typename T>
	const T& vector<T>::operator[](const unsigned long long index) const noexcept
	{
		return m_array[index];
	}

	// Same as operator[], but has bounds-checking
	template<typename T>
	T& vector<T>::at(const unsigned long long index)
	{
		if (index > m_size)
			throw std::out_of_range("T& vector<T>::at(unsigned long long index)");

		return m_array[index];
	}

	// Same as above, but works with const objects
	template<typename T>
	const T& vector<T>::at(const unsigned long long index) const
	{
		if (index > m_size)
			throw std::out_of_range("const T& vector<T>::at(const unsigned long long index)");
	}

	// Returns a reference to the first element
	template<typename T>
	T& vector<T>::front() noexcept
	{
		return m_array[0];
	}

	template<typename T>
	const T& vector<T>::front() const noexcept
	{
		return m_array[0];
	}

	// Returns a reference to the last element
	template<typename T>
	T& vector<T>::back() noexcept
	{
		return m_array[m_elements - 1];
	}

	template<typename T>
	const T& vector<T>::back() const noexcept
	{
		return m_array[m_elements - 1];
	}

	// Returns a pointer to the array used for storage
	template<typename T>
	T* vector<T>::data() noexcept
	{
		return m_array;
	}

	template<typename T>
	const T* vector<T>::data() const noexcept
	{
		return m_array;
	}

	// Constructs object in-place with arguments
	template<typename T>
	template<class... Args>
	void vector<T>::emplace_back(Args&&... args)
	{
		if (m_elements == m_size)
		{
			m_size <<= 2;
			
			T* buffer = new T[m_size];
			std::memcpy(buffer, m_array, m_elements * sizeof(T));

			delete[] m_array;
			m_array = buffer;
		}

		m_array[m_elements] = std::move( T ( std::forward<Args>(args)... ) );
		++m_elements;
	}

	// Pushes back elements via std::initializer_list<>
	template<typename T>
	void vector<T>::push_back(const std::initializer_list<T>&& list)
	{
		for (auto& it : list)
		{
			if (m_elements == m_size)
			{
				m_size <<= 2;

				T* buffer = new T[m_size];
				std::memcpy(buffer, m_array, m_elements * sizeof(T));

				delete[] m_array;
				m_array = buffer;
			}

			m_array[m_elements] = it;
			++m_elements;
		}
	}

	// Pushes back a new element with value provided
	template<typename T>
	void vector<T>::push_back(const T& value)
	{
		if (m_elements == m_size)
		{
			m_size <<= 2;

			T* buffer = new T[m_size];
			std::memcpy(buffer, m_array, m_elements * sizeof(T));

			delete[] m_array;
			m_array = buffer;
		}

		m_array[m_elements] = value;
		++m_elements;
	}

	// Overload of push_back(const T&) that optimizes if the value is movable
	template<typename T>
	void vector<T>::push_back(const T&& value)
	{
		if (m_elements == m_size)
		{
			m_size <<= 2;

			T* buffer = new T[m_size];
			std::memcpy(buffer, m_array, m_elements * sizeof(T));

			delete[] m_array;
			m_array = buffer;
		}

		m_array[m_elements] = std::move(value);
		++m_elements;
	}

	// Pops (deletes) last element in storage
	template<typename T>
	void vector<T>::pop_back()
	{
		--m_elements;
		m_array[m_elements].~T();
	}

	// Returns the allocated size of the array
	template<typename T>
	unsigned long long vector<T>::capacity() const noexcept
	{
		return m_size;
	}

	// Returns the allocated size of the array, in bytes
	template<typename T>
	unsigned long long vector<T>::capacity_bytes() const noexcept
	{
		return m_size * sizeof(T);
	}

	// Returns the number of elements in the array
	template<typename T>
	unsigned long long vector<T>::size() const noexcept
	{
		return m_elements;
	}

	// Returns the number of elements in the array, in bytes
	template<typename T>
	unsigned long long vector<T>::size_bytes() const noexcept
	{
		return m_elements * sizeof(T);
	}

	// Returns true if array is empty
	template<typename T>
	bool vector<T>::empty() const noexcept
	{
		return m_elements == 0 ? true : false;
	}

	// Resizes the amount of allocated storage, elements are destroyed past size
	template<typename T>
	void vector<T>::resize(unsigned long long size)
	{
		if (size > m_size)
		{
			m_size = size;

			T* buffer = new T[m_size];
			std::memcpy(buffer, m_array, m_elements * sizeof(T));

			delete[] m_array;
			m_array = buffer;
		}

		m_elements = size;
	}

	// Changes the amount of reserved storage for the array
	template<typename T>
	void vector<T>::reserve(unsigned long long size)
	{
		if (size > m_size)
		{
			m_size = size;

			T* buffer = new T[m_size];
			std::memcpy(buffer, m_array, m_elements * sizeof(T));

			delete[] m_array;
			m_array = buffer;
		}
	}

	// Shrinks the amount of allocated storage to perfectly fit the elements
	template<typename T>
	void vector<T>::shrink_to_fit()
	{
		m_size = m_elements;

		T* buffer = new T[m_size];
		std::memcpy(buffer, m_array, m_elements * sizeof(T));

		delete[] m_array;
		m_array = buffer;
	}

	// Iterator that returns a pointer to the beginning of the array
	template<typename T>
	T* vector<T>::begin() noexcept
	{
		return &m_array[0];
	}

	// Iterator that returns a pointer to the end of the array
	template<typename T>
	T* vector<T>::end() noexcept
	{
		return &m_array[m_elements];
	}

	// Constant iterator that returns a pointer to the beginning of the array
	template<typename T>
	const T* vector<T>::cbegin() const noexcept
	{
		return &m_array[0];
	}

	// Constant iterator that returns a pointer to the end of the array
	template<typename T>
	const T* vector<T>::cend() const noexcept
	{
		return &m_array[m_elements];
	}

	// Iterator that returns a std::reverse_iterator<T*> to the "beginning" of the array
	template<typename T>
	std::reverse_iterator<T*> vector<T>::rbegin() noexcept
	{
		return std::reverse_iterator<T*>(&m_array[m_elements]);
	}

	// Iterator that returns a std::reverse_iterator<T*> to the "end" of the array
	template<typename T>
	std::reverse_iterator<T*> vector<T>::rend() noexcept
	{
		return std::reverse_iterator<T*>(&m_array[0]);
	}

	// Constant iterator that returns a std::reverse_iterator<T*> to the "beginning" of the array
	template<typename T>
	std::reverse_iterator<const T*> vector<T>::crbegin() const noexcept
	{
		return std::reverse_iterator<const T*>(&m_array[m_elements]);
	}

	// Constant iterator that returns a std::reverse_iterator<T*> to the "end" of the array
	template<typename T>
	std::reverse_iterator<const T*> vector<T>::crend() const noexcept
	{
		return std::reverse_iterator<const T*>(&m_array[0]);
	}
}