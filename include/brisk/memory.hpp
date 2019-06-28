#pragma once

#include <type_traits>

namespace brisk
{
	using nullptr_t = decltype(nullptr);
	
	template <class Type>
	class unique_ptr
	{
	public:
		typedef Type* pointer;
		typedef Type element_type;
	
	public:
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

		unique_ptr& operator=(nullptr_t) noexcept
		{
			if (ptr != nullptr)
			{
				delete ptr;
				ptr = nullptr;
			}

			return *this;
		}

		typename std::add_lvalue_reference<element_type>::type operator*() const
		{
			return *ptr;
		}

		pointer operator->() noexcept
		{
			return ptr;
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
}
