#include "brisk.h"

int main(void)
{
	brisk::logger console(brisk::loglevel::everything, "console.log");

	brisk::array<int, 5> a;
	a.fill(5);

	brisk::vector<std::remove_reference<decltype(a[0])>::type> v(a.begin(), a.end());

	brisk::for_each(v.begin(), v.end(), [&console](const auto& x) { console.print(x); });

	return 0;
}