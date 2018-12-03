#pragma once

#include "utility.hpp"

namespace brisk
{
	template <class Function, class... Args>
	decltype(auto) invoke(Function&& f, Args&&... args) noexcept
	{
		return forward<Function>(f)(forward<Args>(args)...);
	}

	#if 0
		template <class>
		class function;

		template <class Result, class... Args>
		class function<Result(Args...)>
		{
		public:
			using result_type = Result;

			template <class Function>
			function(Function f)
			{
				*this = move(f);
			}

			/*
				R operator()(ArgTypes... args) const;
				Returns: INVOKE<R>(f, std::forward<ArgTypes>(args)...) ([func.require]), where f is the target object of *this.
			*/

			Result operator()(Args... args) const
			{
				return invoke<Result>(*this, forward<Args>(args)...);
			}
		};
	#endif
}