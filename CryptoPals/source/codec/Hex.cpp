#include "Hex.h"

#include <cassert>

static const char* hexTable = "0123456789abcdef";

static std::uint8_t charToHex(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'a':
		return 10;
	case 'b':
		return 11;
	case 'c':
		return 12;
	case 'd':
		return 13;
	case 'e':
		return 14;
	case 'f':
		return 15;
	default:
		assert(false);
		return 0;
	}
}

std::string encodeHex(const std::uint8_t* data, std::uint32_t size)
{
	std::string hex;
	for (std::uint32_t i = 0; i < size; ++i)
	{
		auto d = data[i];
		auto ub = (d >> 4) & 0x0F;
		auto lb = d & 0x0F;
		hex.push_back(hexTable[ub]);
		hex.push_back(hexTable[lb]);
	}
	return hex;
}

std::vector<std::uint8_t> decodeHex(const char* str, std::uint32_t size)
{
	assert(size % 2 == 0);

	std::vector<std::uint8_t> data;
	for (std::uint32_t i = 1; i < size; i += 2)
	{
		auto ub = charToHex(str[i - 1]);
		auto lb = charToHex(str[i]);
		std::uint8_t b = (ub << 4) + lb;
		data.push_back(b);
	}
	return data;
}

std::string encodeHex(const std::vector<std::uint8_t>& data)
{
	return encodeHex(data.data(), data.size());
}

std::vector<std::uint8_t> decodeHex(const std::string& hexStr)
{
	return decodeHex(hexStr.data(), hexStr.size());
}