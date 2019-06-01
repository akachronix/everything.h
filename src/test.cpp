#include "brisk.h"

int main(void)
{
	brisk::logger cout(brisk::loglevel::everything, "cout.log");

	brisk::vector<int> v(10);
	for (unsigned int i = 0; i < v.size(); ++i) {
		v.at(i) = i;
		cout << v.at(i) << ' ';
	}

	brisk::fill_n(v.begin(), v.size() / 2, 8);

	cout << '\n';

	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << ' ';
	}

	cout << '\n';
}