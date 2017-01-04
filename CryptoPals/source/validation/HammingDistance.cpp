#include "HammingDistance.h"

#include <iostream>
#include <cmath>
#include <algorithm>

unsigned int hammingDistance(char a, char b)
{
	char diff = a ^ b;
	unsigned int distance = 0;
	for (int i = 0; i < 8; ++i)
	{
		distance += (diff >> i) & 1;
	}
	return distance;
}

unsigned int hammingDistance(const std::string& a, const std::string& b)
{
	auto min = std::min(a.size(), b.size());
	auto max = std::max(a.size(), b.size());
	auto diff = max - min;
	
	unsigned int distance = 0;
	for (unsigned int i = 0; i < min; ++i)
	{
		distance += hammingDistance(a.at(i), b.at(i));
	}
	distance += diff * 8;

	return distance;
}