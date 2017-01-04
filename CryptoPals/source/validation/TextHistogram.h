#pragma once

#include <string>
#include <unordered_map>

struct TextHistogram
{
	std::unordered_map<char, unsigned int> histogram;
	unsigned int totalCount = 0;
};

void updateHistogram(const std::string& text, TextHistogram& histogram);