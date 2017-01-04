#pragma once

#include <cstdint>
#include <vector>

#include "Language.h"

struct TextAnalysis
{
	std::vector<std::string> words;
	int length = 0;
	int spaces = 0;
};

// Only contains valid/printable ASCII values?
bool isASCIIText(const std::uint8_t* data, std::uint32_t size);
bool isASCIIText(const std::vector<std::uint8_t>& data);

TextAnalysis analyseText(const std::string& text);

std::vector<std::string> splitText(const std::string& text);

bool isText(const char* text, std::uint32_t size, const Language& language);
bool isText(const std::string& text, const Language& language);