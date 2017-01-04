#pragma once

#include <string>
#include <unordered_set>

using Dictionary = std::unordered_set<std::string>;

struct Language
{
	Dictionary dictionary;
	float wordMatchRatio = 0.0;
	// Averages
	float minTextLengthPerSpace = 0.0;
	float maxTextLengthPerSpace = 0.0;
};

bool readDictionary(const std::string& file, Dictionary& dictionary);