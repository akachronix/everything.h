#pragma once

#include <cstddef>
#include <type_traits>

namespace brisk
{
	template <class Type>
	class iterator
	{
	public:
		using pointer = Type*;
		using const_pointer = const Type*;
		using difference_type = ptrdiff_t;

		explicit iterator(const pointer begin, const pointer end)
			: m_it(begin), m_begin(begin), m_end(end)
		{

		}

		iterator(const iterator& i)
		{
			m_it = i.m_it;
			m_begin = i.m_begin;
			m_end = i.m_end;
		}

		iterator(iterator&& i)
		{
			m_it = brisk::move(i.m_it);
			m_begin = brisk::move(i.m_begin);
			m_end = brisk::move(i.m_end);

			i.m_it = nullptr;
			i.m_begin = nullptr;
			i.m_end = nullptr;
		}

		~iterator()
		{

		}

		iterator& operator=(const iterator& i)
		{
			m_it = i.m_it;
			m_begin = i.m_begin;
			m_end = i.m_end;
		}

		iterator& operator=(iterator&& i)
		{
			m_it = brisk::move(i.m_it);
			m_begin = brisk::move(i.m_begin);
			m_end = brisk::move(i.m_end);

			i.m_it = nullptr;
			i.m_begin = nullptr;
			i.m_end = nullptr;
		}

		pointer it() noexcept
		{
			return m_it;
		}

		pointer begin() noexcept
		{
			return m_begin;
		}
		
		pointer end() noexcept
		{
			return m_end;
		}

		const_pointer cbegin() const noexcept
		{
			return m_begin;
		}

		const_pointer cend() const noexcept
		{
			return m_end;
		}

		difference_type distance() const noexcept
		{
			return m_it - m_begin;
		}

		difference_type range() const noexcept
		{
			return m_end - m_begin;
		}

		difference_type pos() const noexcept
		{
			return m_it - m_begin;
		}

		iterator& operator++() noexcept
		{
			++m_it;
			return *this;
		}

		iterator& operator--() noexcept
		{
			--m_it;
			return *this;
		}

		typename std::add_lvalue_reference<Type>::type operator*() const
		{
			return *(m_it);
		}

	private:
		pointer m_it;
		pointer m_begin;
		pointer m_end;
	};
}