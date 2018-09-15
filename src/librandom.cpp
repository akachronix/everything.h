#include "librandom.hpp"

#include <cstdlib>
#include <ctime>

Random::Random(unsigned int _min, unsigned int _max)
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

void Random::Randomize() const noexcept
{
	srand((unsigned)time(NULL));
}

unsigned int Random::RandInt(unsigned int _min, unsigned int _max) const noexcept
{
	return rand() % _max + _min;
}

unsigned int Random::RandInt() const noexcept
{
	return rand() % m_max + m_min;
}

unsigned int Random::GetMin() const noexcept
{
	return m_min;
}

unsigned int Random::GetMax() const noexcept
{
	return m_max;
}

void Random::SetMin(unsigned int _min) noexcept
{
	m_min = _min;
}

void Random::SetMax(unsigned int _max) noexcept
{
	m_max = _max;
}