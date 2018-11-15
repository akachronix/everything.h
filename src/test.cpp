#include <iostream>

#include "array.hpp"

int main(void)
{
	brisk::array<int, 50> arr;
	for (int i = 0; i < arr.size(); ++i) {
		arr[i] = i;

		std::cout << arr[i] << ' ';
	}

	return 0;
}