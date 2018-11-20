#include "brisk.h"

int main(void)
{
	// Create a logger object
	brisk::logger console(brisk::loglevel::everything, "console.log");

	// Create an array with hard-coded size
	brisk::array<int, 5> my_array;

	// Set values of elements
	my_array[0] = 1;
	my_array[1] = 6;
	my_array[2] = 5;
	my_array[3] = 8;
	my_array[4] = 2;

	// Copy the array into a vector so we may add elements
	brisk::vector<std::remove_reference<decltype(my_array[0])>::type> my_vector = brisk::copy(my_array);

	// Iterate through every element in vector and add 5
	brisk::for_each(my_vector.begin(), my_vector.end(), [] (auto& x, auto y) { x += y; }, 5);

	// Create a pair object
	brisk::pair<char, int> my_pair('A', 41);

	// Create a rectangle object (default template type is 'long double')
	brisk::shape::rectangle<> my_rectangle = { 5, 6 };

	// Tse the logger object to print out the results of the rectangle area calculation
	console << "Rectangle dimensions: " << my_rectangle.length << " x " << my_rectangle.width << brisk::newl;
	console << "Rectangle area: " << my_rectangle() << brisk::newl;

	return 0;
}