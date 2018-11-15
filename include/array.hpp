#pragma once

#include <iterator>
#include <stdexcept>

namespace brisk
{
	template<typename T, size_t _Size>
	class array
	{
	private:
		T* m_array;

	public:
		array();
		array(const std::initializer_list<T> list);
		~array();

		array(array&) = delete;
		array(array&&) = delete;

		T& operator[](const size_t index) noexcept;
		const T& operator[](const size_t index) const noexcept;

		T& at(const size_t index);
		const T& at(const size_t index) const;

		T* data() noexcept;

		size_t size() const noexcept;
		bool empty() const noexcept;

		T* begin() noexcept;
		T* end() noexcept;
		
		const T* cbegin() const noexcept;
		const T* cend() const noexcept;

		std::reverse_iterator<T*> rbegin() noexcept;
		std::reverse_iterator<T*> rend() noexcept;

		std::reverse_iterator<const T*> crbegin() const noexcept;
		std::reverse_iterator<const T*> crend() const noexcept;
	};

	template<typename T, size_t _Size>
	array<T, _Size>::array()
	{
		m_array = new T[_Size];
	}

	template<typename T, size_t _Size>
	array<T, _Size>::~array()
	{
		delete[] m_array;
	}

	template<typename T, size_t _Size>
	T& array<T, _Size>::operator[](const size_t index) noexcept
	{
		return m_array[index];
	}

	template<typename T, size_t _Size>
	const T& array<T, _Size>::operator[](const size_t index) const noexcept
	{
		return m_array[index];
	}

	template<typename T, size_t _Size>
	T& array<T, _Size>::at(const size_t index)
	{
		if (index > (_Size - 1))
			throw std::out_of_range("T& array<T, _Size>::at(const size_t index)\n");
		
		return m_array[index];
	}

	template<typename T, size_t _Size>
	const T& array<T, _Size>::at(const size_t index) const
	{
		if (index > (_Size - 1))
			throw std::out_of_range("const T& array<T, _Size>::at(const size_t index) const\n");
		
		return m_array[index];
	}

	template<typename T, size_t _Size>
	T* array<T, _Size>::data() noexcept
	{
		return m_array;
	}

	template<typename T, size_t _Size>
	size_t array<T, _Size>::size() const noexcept
	{
		return _Size;
	}

	template<typename T, size_t _Size>
	bool array<T, _Size>::empty() const noexcept
	{
		return (_Size == 0) ? true : false;
	}

	template<typename T, size_t _Size>
	T* array<T, _Size>::begin() noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "T* array<T, _Size>::begin() noexcept\n";
	#endif

		return &m_array[0];
	}

	template<typename T, size_t _Size>
	T* array<T, _Size>::end() noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "T* array<T, _Size>::end() noexcept\n";
	#endif

		return &m_array[_Size];
	}

	template<typename T, size_t _Size>
	const T* array<T, _Size>::cbegin() const noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "const T* array<T, _Size>::cbegin() const noexcept\n";
	#endif

		return &m_array[0];
	}

	template<typename T, size_t _Size>
	const T* array<T, _Size>::cend() const noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "const T* array<T, _Size>::cend() const noexcept\n";
	#endif

		return &m_array[_Size];
	}

	template<typename T, size_t _Size>
	std::reverse_iterator<T*> array<T, _Size>::rbegin() noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "std::reverse_iterator<T*> array<T, _Size>::rbegin() noexcept\n";
	#endif

		return std::reverse_iterator<T*>(&m_array[_Size]);
	}

	template<typename T, size_t _Size>
	std::reverse_iterator<T*> array<T, _Size>::rend() noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "std::reverse_iterator<T*> array<T, _Size>::rend() noexcept\n";
	#endif

		return std::reverse_iterator<T*>(&m_array[0]);
	}

	template<typename T, size_t _Size>
	std::reverse_iterator<const T*> array<T, _Size>::crbegin() const noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "std::reverse_iterator<const T*> array<T, _Size>::crbegin() const noexcept\n";
	#endif

		return std::reverse_iterator<const T*>(&m_array[_Size]);
	}

	template<typename T, size_t _Size>
	std::reverse_iterator<const T*> array<T, _Size>::crend() const noexcept
	{
	#if defined(EVERYTHING_DEBUG) || defined(array_DEBUG)
		std::cout << "std::reverse_iterator<const T*> array<T, _Size>::crend() const noexcept\n";
	#endif

		return std::reverse_iterator<const T*>(&m_array[0]);
	}
}