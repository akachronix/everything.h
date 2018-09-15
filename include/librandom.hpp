#pragma once

class Random
{
public:
	Random(unsigned int _min, unsigned int _max);
	Random();

	~Random();

	void Randomize() const noexcept;

	unsigned int RandInt(unsigned int _min, unsigned int _max) const noexcept;
	unsigned int RandInt() const noexcept;

	unsigned int GetMin() const noexcept;
	unsigned int GetMax() const noexcept;

	void SetMin(unsigned int _min) noexcept;
	void SetMax(unsigned int _max) noexcept;

private:
	unsigned int m_min;
	unsigned int m_max;
};