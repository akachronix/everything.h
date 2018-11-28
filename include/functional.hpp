#pragma once

#include "utility.hpp"

namespace brisk
{
	template <class Function, class... Args>
	decltype(auto) invoke(Function&& f, Args&&... args) noexcept
	{
		return forward<Function>(f)(forward<Args>(args)...);
	}
}
