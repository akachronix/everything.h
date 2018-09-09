#pragma once

#include <cstdint>

class Random
{
public:
	Random(uint32_t _min, uint32_t _max);
	Random();

	~Random();

	void Randomize();

	uint32_t RandInt(uint32_t _min, uint32_t _max) const;
	uint32_t RandInt() const;

	uint32_t GetMin() const;
	uint32_t GetMax() const;

private:
	uint32_t m_min;
	uint32_t m_max;
};