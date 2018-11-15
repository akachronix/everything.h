#include <iostream>
#include <type_traits>

#include "brisk.h"

int main(void)
{
	brisk::array<int, 50> arr;
	for (int i = 0; i < arr.size(); ++i)
		arr[i] = i;
	
	brisk::vector<std::remove_reference<decltype(arr[0])>::type> vector = brisk::copy(arr);
	for (auto& it : vector)
		std::cout << it << ' ';

	return 0;
}