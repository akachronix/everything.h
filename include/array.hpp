#pragma once

#include <iterator>
#include <stdexcept>

namespace brisk
{
	template<typename Type, size_t Size>
	class array
	{
	private:
		Type m_array[Size];
	
	public:
		using size_type = size_t;
		using value_type = Type;
		using pointer = Type*;
		using const_pointer = const Type*;
		using reference = Type&;
		using const_reference = const Type&;

		using iterator = Type*;
		using const_iterator = const Type*;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		// using difference_type = ptrdiff_t;

		array(array&)  = delete;
		array(array&&) = delete;

		array()  = default;
		~array() = default;

		reference operator[](const size_type index) noexcept
		{
			return m_array[index];
		}

		const_reference operator[](const size_type index) const noexcept
		{
			return m_array[index];
		}

		reference at(const size_type index)
		{
			if (index > (Size - 1))
				throw std::out_of_range("index is out of range");
			
			return m_array[index];
		}

		const_reference at(const size_type index) const
		{
			if (index > (Size - 1))
				throw std::out_of_range("index is out of range");
			
			return m_array[index];
		}

		reference front() noexcept
		{
			return m_array[0];
		}

		const_reference front() const noexcept
		{
			return m_array[0];
		}

		reference back() noexcept
		{
			return m_array[Size - 1];
		}

		const_reference back() const noexcept
		{
			return m_array[Size - 1];
		}

		pointer data() noexcept
		{
			return m_array;
		}

		constexpr size_type size() const noexcept
		{
			return Size;
		}

		bool empty() const noexcept
		{
			return (Size == 0) ? true : false;
		}

		iterator begin() noexcept
		{
			return &m_array[0];
		}

		iterator end() noexcept
		{
			return &m_array[Size];
		}
		
		const_iterator cbegin() const noexcept
		{
			return &m_array[0];
		}

		const_iterator cend() const noexcept
		{
			return &m_array[Size];
		}

		reverse_iterator rbegin() noexcept
		{
			return reverse_iterator(&m_array[Size]);
		}

		reverse_iterator rend() noexcept
		{
			return reverse_iterator(&m_array[0]);
		}

		const_reverse_iterator crbegin() const noexcept
		{
			return reverse_iterator(&m_array[Size]);
		}

		const_reverse_iterator crend() const noexcept
		{
			return reverse_iterator(&m_array[0]);
		}
	};
}