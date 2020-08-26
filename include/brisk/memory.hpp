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

		unique_ptr(unique_ptr&& x) noexcept
		{
			ptr = x.ptr;
			x.ptr = nullptr;
		}

		unique_ptr(const unique_ptr&) = delete;

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

		void reset(pointer p = pointer())
		{
			if (ptr != nullptr)
				delete ptr;
			ptr = p;
		}

		void swap(unique_ptr& other) noexcept
		{
			pointer temp = ptr;
			ptr = other.ptr;
			other.ptr = temp;
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

	template <class Type1, class Type2>
	bool operator==(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return x.get() == y.get();
	}

	template <class Type1, class Type2>
	bool operator!=(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return x.get() != y.get();
	}

	template <class Type1, class Type2>
	bool operator<(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return std::less<typename std::common_type<typename unique_ptr<Type1>::pointer, typename unique_ptr<Type2>::pointer>::type>()(x.get(), y.get());
	}

	template <class Type1, class Type2>
	bool operator<=(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return !(y < x);
	}

	template <class Type1, class Type2>
	bool operator>(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return std::greater<typename std::common_type<typename unique_ptr<Type1>::pointer, typename unique_ptr<Type2>::pointer>::type>()(x.get(), y.get());
		// could also be "return (y < x)" but im using that ^ for now because more verbose
	}

	template <class Type1, class Type2>
	bool operator>=(const unique_ptr<Type1>& x, const unique_ptr<Type2>& y)
	{
		return !(x < y);
	}

	template <class Type>
	bool operator==(const unique_ptr<Type>& x, nullptr_t) noexcept
	{
		return !(x.get());
	}

	template <class Type>
	bool operator!=(const unique_ptr<Type>& x, nullptr_t) noexcept
	{
		return bool(x.get());
	}

	template <class Type>
	bool operator==(nullptr_t, const unique_ptr<Type>& x) noexcept
	{
		return !(x.get());
	}

	template <class Type>
	bool operator!=(nullptr_t, const unique_ptr<Type>& x) noexcept
	{
		return bool(x.get());
	}

	template <class Type>
	bool operator<(const unique_ptr<Type>& x, nullptr_t)
	{
		return std::less<typename unique_ptr<Type>::pointer>()(x.get(), nullptr);
	}

	template <class Type>
	bool operator<(nullptr_t, const unique_ptr<Type>&x) noexcept
	{
		return std::less<typename unique_ptr<Type>::pointer>()(nullptr, x.get());
	}

	template <class Type>
	bool operator<=(const unique_ptr<Type>& x, nullptr_t)
	{
		return !(nullptr < x);
	}

	template <class Type>
	bool operator<=(nullptr_t, const unique_ptr<Type>& x)
	{
		return !(x < nullptr);
	}

	template <class Type>
	bool operator>(const unique_ptr<Type&> x, nullptr_t)
	{
		return (nullptr < x);
	}

	template <class Type>
	bool operator>(nullptr_t, const unique_ptr<Type>& x)
	{
		return (x < nullptr);
	}

	template <class Type>
	bool operator>=(const unique_ptr<Type>& x, nullptr_t)
	{
		return !(x < nullptr);
	}

	template <class Type>
	bool operator>=(nullptr_t, const unique_ptr<Type>& x)
	{
		return !(nullptr < x);
	}
}
