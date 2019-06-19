#include "brisk.h"

int main(int argc, const char* argv[])
{
	brisk::logger cout(brisk::loglevel::everything, "cout.log");

	brisk::vector<int> v(10);
	brisk::fill(v.begin(), v.end(), 10);

	brisk::vector<int> v2(v.size());
	brisk::copy(v2.begin(), v2.end(), v.begin());

	for (auto& it : v) {
		cout << it << ' ';
	}

	for (auto& it : v2) {
		cout << it << ' ';
	}

	cout << '\n';
	cout.shrink_to_fit();
}