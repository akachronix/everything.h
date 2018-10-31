#include <iostream>
#include <string>

#include "everything.h"

int main(void)
{
	Logger console(loglevel_t::everything, "console.log");

	Vector<int> vector = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector.shrink_to_fit();

	console << "Elements allocated: " << vector.capacity() << newl;
	console << "Elements allocated (bytes): " << vector.capacity_bytes() << newl;
	console << newl;
	console << "Elements filled: " << vector.size() << newl;
	console << "Elements filled (bytes): " << vector.size_bytes() << newl;
	console << newl;
	console << "Front element: " << vector.front() << newl;
	console << "Back element: " << vector.back() << newl;
	console << newl;
	console << "Empty? " << (vector.empty() ? "yes" : "no") << newl;

	std::cin.get();
	return 0;
}