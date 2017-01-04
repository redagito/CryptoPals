#include "TextHistogram.h"

#include <cctype>

void updateHistogram(const std::string& text, TextHistogram& histogram)
{
	for (char c : text)
	{
		if (std::isalpha(c) != 0)
		{
			if (histogram.histogram.count((char)std::tolower(c)) == 0)
			{
				histogram.histogram[(char)std::tolower(c)] = 1;
			}
			else
			{
				histogram.histogram[(char)std::tolower(c)] += 1;
			}
			histogram.totalCount++;
		}
	}
}