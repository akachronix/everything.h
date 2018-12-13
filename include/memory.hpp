#pragma once

#include <type_traits>

namespace brisk
{
	template <class Type>
	class unique_ptr
	{
	public:
		using pointer = Type*;
		using element_type = Type;

		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		constexpr unique_ptr() noexcept
		{
			ptr = nullptr;
		}

		constexpr unique_ptr(nullptr_t) noexcept : unique_ptr()
		{

		}

		explicit unique_ptr(pointer p) noexcept
		{
			ptr = p;
		}

		~unique_ptr()
		{
			if (ptr != nullptr)
				delete ptr;
		}

		typename std::add_lvalue_reference<element_type>::type operator*() const
		{
			return *ptr;
		}

		pointer operator->() const noexcept
		{
			if (ptr != nullptr)
			{
				return *ptr;
			}
		}

		pointer get() const noexcept
		{
			return ptr;
		}

		explicit operator bool() const noexcept
		{
			return (ptr == nullptr) ? false : true;
		}


		pointer release() noexcept
		{
			pointer temp = ptr;
			ptr = nullptr;

			return temp;
		}

		void reset(pointer p = pointer()) noexcept
		{
			if (ptr != nullptr)
				delete ptr;
			
			ptr = p;
		}
	
	private:
		pointer ptr;
	};

	class address_range
	{
	public:
		address_range() = default;

		address_range(unsigned long long begin, unsigned long long end)
			: m_begin(begin), m_end(end)
		{

		}

		void* begin() const
		{
			return reinterpret_cast<void*>(m_begin);
		}

		void* end() const
		{
			return reinterpret_cast<void*>(m_end);
		}

		unsigned long long bytes() const noexcept
		{
			return reinterpret_cast<unsigned long long>(m_end - m_begin);
		}

	private:
		unsigned long long m_begin;
		unsigned long long m_end;
	};
}
