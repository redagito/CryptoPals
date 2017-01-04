#include "TextValidation.h"

#include <cctype>
#include <string>

bool isASCIIText(const std::uint8_t* data, std::uint32_t size)
{
	for (std::uint32_t i = 0; i < size; ++i)
	{
		if ((std::isprint(data[i]) == 0) && (std::isspace(data[i]) == 0))
		{
			return false;
		}
	}
	return true;
}

bool isASCIIText(const std::vector<std::uint8_t>& data)
{
	return isASCIIText(data.data(), data.size());
}

TextAnalysis analyseText(const std::string& text)
{
	TextAnalysis analysis;
	analysis.length = text.length();

	std::string word;
	for (char c : text)
	{
		if (std::isalpha(c))
		{
			word.push_back(c);
		}
		else
		{
			if (std::isspace(c))
			{
				analysis.spaces++;
			}

			if (!word.empty()) 
			{
				analysis.words.push_back(word);
				word.clear();
			}
		}
	}
	return analysis;
}

std::vector<std::string> splitText(const std::string& text)
{
	auto analysis = analyseText(text);
	return analysis.words;
}

bool isText(const char* text, std::uint32_t size, const Language& lang)
{
	return isText(std::string(text, size), lang);
}

bool isText(const std::string& text, const Language& lang)
{
	auto analysis = analyseText(text);
	
	// Average spaces per text
	auto textLengthPerSpace = (float)analysis.length / (float)analysis.spaces;
	if (textLengthPerSpace > lang.maxTextLengthPerSpace || textLengthPerSpace < lang.minTextLengthPerSpace)
	{
		return false;
	}

	int matches = 0;
	for (const auto& word : analysis.words)
	{
		if (lang.dictionary.count(word) != 0)
		{
			++matches;
		}
	}
	float matchRate = (float) matches / (float) analysis.words.size();
	return matchRate >= lang.wordMatchRatio;
}