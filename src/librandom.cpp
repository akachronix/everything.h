#include "librandom.hpp"

#include <cstdint>
#include <cstdlib>
#include <ctime>

Random::Random(uint32_t _min, uint32_t _max)
	: m_min(_min), m_max(_max)
{
	this->Randomize();
}

Random::Random()
	: m_min(0), m_max(0)
{
	this->Randomize();
}

Random::~Random()
{

}

void Random::Randomize()
{
	srand((unsigned)time(NULL));
}

uint32_t Random::RandInt(uint32_t _min, uint32_t _max) const
{
	return rand() % _max + _min;
}

uint32_t Random::RandInt() const
{
	return rand() % m_max + m_min;
}

uint32_t Random::GetMin() const
{
	return m_min;
}

uint32_t Random::GetMax() const
{
	return m_max;
}