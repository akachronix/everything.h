#include "brisk.h"

int main(int argc, const char* argv[])
{
	brisk::logger cout(brisk::loglevel::everything, "cout.log");

	brisk::vector<int> v(10);
	brisk::fill(v.begin(), v.end(), 10);
	auto sum = brisk::accumulate(v.begin(), v.end(), 0);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << ' ';

		if (i != (v.size() - 1))
			cout << "+ ";

		else
			cout << "= ";
	}

	cout << sum << '\n';

	return 0;
}