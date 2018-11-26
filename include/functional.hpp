#pragma once

#include <utility>

namespace brisk
{
	template <class Function, class... Args>
	decltype(auto) invoke(Function& f, Args&&... args)
	{
		return std::forward<Function>(f)(std::forward<Args>(args)...);
	}
}