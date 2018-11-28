#pragma once

#include <utility>

namespace brisk
{
	template <class Function, class... Args>
	decltype(auto) invoke(Function&& f, Args&&... args) noexcept
	{
		return std::forward<Function>(f)(std::forward<Args>(args)...);
	}
}
