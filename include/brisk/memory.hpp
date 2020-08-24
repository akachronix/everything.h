#pragma once

#include <type_traits>

namespace brisk
{
	using nullptr_t = decltype(nullptr);
	
	template <class Type>
	class unique_ptr
	{
	public:
		typedef Type pointer;
		typedef typename std::remove_pointer<Type>::type element_type;

	public:
		constexpr unique_ptr() noexcept
		{
			ptr = nullptr;
		}

		constexpr unique_ptr(nullptr_t) noexcept
		{
			ptr = nullptr;
		}

		explicit unique_ptr(pointer p) noexcept
		{
			ptr = p;
		}

		~unique_ptr()
		{
			delete ptr;
		}

		pointer release() noexcept
		{
			pointer temp = ptr;
			ptr = nullptr;
			return temp;
		}

		pointer get() const noexcept
		{
			return ptr;
		}

		typename std::add_lvalue_reference<element_type>::type operator*() const
		{
			return *ptr;
		}

		pointer operator->() const noexcept
		{
			return ptr;
		}

	private:
		pointer ptr;
	};
}
