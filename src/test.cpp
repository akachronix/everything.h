#include <iostream>
#include <type_traits>

#include "brisk.h"

struct Vec2
{
	float x, y;

	Vec2() = default;
	~Vec2() = default;

	Vec2(float _x, float _y)
		: x(_x), y(_y)
	{}
};

std::ostream& operator<<(std::ostream& out, const Vec2& vec2)
{
	out << vec2.x << ", " << vec2.y;
	return out;
}

int main(void)
{
	brisk::array<Vec2, 5> coordinate_pairs;
	coordinate_pairs[0] = Vec2(2, 4);
	coordinate_pairs[1] = Vec2(4, 8);
	coordinate_pairs[2] = Vec2(8, 16);
	coordinate_pairs[3] = Vec2(16, 32);
	coordinate_pairs[4] = Vec2(32, 64);

	brisk::vector<std::remove_reference<decltype(coordinate_pairs[0])>::type> coords = brisk::copy(coordinate_pairs);

	for (auto it = coords.crbegin(); it != coords.crend(); ++it)
		std::cout << *it << '\n';

	return 0;
}
