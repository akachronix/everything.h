#pragma once

#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <cstring>
#include <cstddef>

#include "utility.hpp"

namespace brisk
{
	template <class Type>
	class vector
	{
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
		using difference_type = ptrdiff_t;

	public:
		vector()
			: m_elements(0), m_size(4)
		{
			m_array = new Type[m_size];
		}

		explicit vector(const size_type size)
			: m_elements(size), m_size(size << 2)
		{
			m_array = new Type[m_size];
		}
		
		vector(const std::initializer_list<Type> list)
			: m_elements(list.size()), m_size(list.size() * 2)
		{
			m_array = new Type[m_size];

			size_type i = 0;
			for (auto it = list.begin(); it != list.end(); ++it)
			{
				m_array[i] = *(it);
				++i;
			}
		}
		
		vector(iterator const begin, iterator const end)
			: m_elements(0), m_size(0)
		{
			for (iterator it = begin; it != end; ++it)
				++m_elements;
			
			m_size = m_elements << 2;
			m_array = new Type[m_size];

			for (size_type i = 0; i < m_elements; ++i)
				m_array[i] = *(begin + i);
		}

		vector(const vector& v2)
			: m_elements(v2.m_elements), m_size(v2.m_size)
		{
			m_array = new Type[m_size];
			std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(Type));
		}

		vector(vector&& v2)
		{
			m_elements = brisk::move(v2.m_elements);
			m_size = brisk::move(v2.m_size);
			m_array = v2.m_array;
			
			v2.m_elements = 0;
			v2.m_size = 0;
			v2.m_array = nullptr;
		}

		~vector()
		{
			if (m_array != nullptr)
				delete[] m_array;
		}

		vector<Type>& operator=(const vector& v2)
		{
			m_elements = v2.m_elements;
			m_size = v2.m_size;
			
			m_array = new Type[m_size];
			std::memcpy(m_array, v2.m_array, v2.m_elements * sizeof(Type));
		}

		vector<Type>& operator=(vector&& v2)
		{
			m_elements = brisk::move(v2.m_elements);
			m_size = brisk::move(v2.m_size);
			m_array = v2.m_array;

			v2.m_elements = 0;
			v2.m_size = 0;
			v2.m_array = nullptr;
		}

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
			if (index > (m_elements - 1) || m_elements == 0)
				throw std::out_of_range("index out of range");
			
			return m_array[index];
		}

		const_reference at(const size_type index) const
		{
			if (index > (m_elements - 1) || m_elements == 0)
				throw std::out_of_range("index out of range");
			
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
			return m_array[m_elements - 1];
		}

		const_reference back() const noexcept
		{
			return m_array[m_elements - 1];
		}

		pointer data() noexcept
		{
			return m_array;
		}

		const_pointer data() const noexcept
		{
			return m_array;
		}

		template <class... Args>
		void emplace_back(Args&&... args)
		{
			if (m_elements == m_size)
			{
				size_type old_m_size = m_size;
				m_size <<= 2;

				Type* buffer = new Type[m_size];
				for (size_type i = 0; i < old_m_size; ++i)
					buffer[i] = brisk::move(m_array[i]);

				delete[] m_array;
				m_array = buffer;
			}

			m_array[m_elements] = brisk::move(Type(std::forward<Args>(args)...));
			++m_elements;
		}
		
		void push_back(const std::initializer_list<Type>&& list)
		{
			for (auto& it = list.begin(); it != list.end(); ++it)
			{
				if (m_elements == m_size)
				{
					m_size <<= 2;

					Type* buffer = new Type[m_size];
					std::memcpy(buffer, m_array, m_elements * sizeof(Type));

					delete[] m_array;
					m_array = buffer;
				}

				m_array[m_elements] = *(it);
				++m_elements;
			}
		}

		void push_back(const Type& value)
		{
			if (m_elements == m_size)
			{
				size_type old_m_size = m_size;
				m_size <<= 2;

				Type* buffer = new Type[m_size];
				for (size_type i = 0; i < old_m_size; ++i)
					buffer[i] = brisk::move(m_array[i]);

				delete[] m_array;
				m_array = buffer;
			}

			m_array[m_elements] = value;
			++m_elements;
		}

		void push_back(const Type&& value)
		{
			if (m_elements == m_size)
			{
				size_type old_m_size = m_size;
				m_size <<= 2;
				
				Type* buffer = new Type[m_size];
				for (size_type i = 0; i < old_m_size; ++i)
					buffer[i] = brisk::move(m_array[i]);

				delete[] m_array;
				m_array = buffer;
			}

			m_array[m_elements] = std::move(value);
			++m_elements;
		}

		void pop_back()
		{
			--m_elements;
			m_array[m_elements].~Type();
		}

		size_type capacity() const noexcept
		{
			return m_size;
		}

		size_type size() const noexcept
		{
			return m_elements;
		}

		[[nodiscard]] bool empty() const noexcept
		{
			return (m_elements == 0) ? true : false;
		}

		explicit operator bool() const noexcept
		{
			return (m_elements == 0) ? false : true;
		}

		void resize(const size_type size)
		{		
			if (size > m_size)
			{
				size_type old_m_size = m_size;
				m_size = size;

				Type* buffer = new Type[m_size];
				for (size_type i = 0; i < old_m_size; ++i)
					buffer[i] = brisk::move(m_array[i]);

				delete[] m_array;
				m_array = buffer;
			}

			m_elements = size;
		}

		void reserve(const size_type size)
		{
			if (size > m_size)
			{
				size_type old_m_size = m_size;
				m_size = size;
				
				Type* buffer = new Type[m_size];
				for (size_type i = 0; i < old_m_size; ++i)
					buffer[i] = brisk::move(m_array[i]);

				delete[] m_array;
				m_array = buffer;
			}
		}

		void shrink_to_fit()
		{
			m_size = m_elements;

			Type* buffer = new Type[m_size];
			for (size_type i = 0; i < m_size; ++i)
				buffer[i] = brisk::move(m_array[i]);

			delete[] m_array;
			m_array = buffer;
		}

		void fill(const value_type& value)
		{
			for (size_type i = 0; i < m_elements; ++i)
				m_array[i] = value;
		}

		bool operator==(const vector<Type>& rhs) const
		{
			if (m_elements != rhs.m_elements)
				return false;
			
			for (size_type i = 0; i < m_elements; ++i)
				if (m_array[i] != rhs.m_array[i])
					return false;
			
			return true;
		}

		bool operator!=(const vector<Type>& rhs) const
		{
			if (m_elements != rhs.m_elements)
				return true;
			
			for (size_type i = 0; i < m_elements; ++i)
				if (m_array[i] != rhs.m_array[i])
					return true;
			
			return false;
		}

		iterator begin() noexcept
		{
			return &m_array[0];
		}

		iterator end() noexcept
		{
			return &m_array[m_elements];
		}
		
		const_iterator cbegin() const noexcept
		{
			return &m_array[0];
		}
		
		const_iterator cend() const noexcept
		{
			return &m_array[m_elements];
		}

		reverse_iterator rbegin() noexcept
		{
			return reverse_iterator(&m_array[m_elements]);
		}

		reverse_iterator rend() noexcept
		{
			return reverse_iterator(&m_array[0]);
		}

		const_reverse_iterator crbegin() const noexcept
		{
			return reverse_iterator(&m_array[m_elements]);
		}

		const_reverse_iterator crend() const noexcept
		{
			return reverse_iterator(&m_array[0]);
		}

	private:
		size_type m_elements;
		size_type m_size;
		value_type* m_array;
	};
}
