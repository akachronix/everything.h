#pragma once

#include <type_traits>

namespace brisk
{
	template <class Type>
	class unique_ptr
	{
	public:
		using pointer = Type*;

		unique_ptr(const unique_ptr&) = delete;

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

		typename std::add_lvalue_reference<Type>::type operator*() const
		{
			return *ptr;
		}

		pointer get() const noexcept
		{
			return ptr;
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