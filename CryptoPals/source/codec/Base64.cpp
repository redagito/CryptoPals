#include "Base64.h"

#include <cctype>

static const std::string base64Table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static bool isBase64(char c) 
{
	return (std::isalnum(c) || (c == '+') || (c == '/'));
}

std::string encodeBase64(const std::uint8_t* data, std::uint32_t size) 
{
	std::string encoded;
	int i = 0;
	// 24 bits of data for encoding
	char ca3[3];
	// 4 * 6 bits for encoding
	char ca4[4];

	while (size--) 
	{
		// Read 3 bytes = 24 bits
		ca3[i++] = *(data++);

		// Every 24 bits, encode and append
		if (i == 3)
		{
			// Split 24 bits into 6 * 4 bits
			ca4[0] = (ca3[0] & 0xfc) >> 2;
			ca4[1] = ((ca3[0] & 0x03) << 4) + ((ca3[1] & 0xf0) >> 4);
			ca4[2] = ((ca3[1] & 0x0f) << 2) + ((ca3[2] & 0xc0) >> 6);
			ca4[3] = ca3[2] & 0x3f;

			// Encode
			for (i = 0; i < 4; ++i)
			{
				encoded.push_back(base64Table[ca4[i]]);
			}
			i = 0;
		}
	}

	// Remaining bytes
	if (i != 0)
	{
		int j = 0;
		// Fill with zeroes
		for (j = i; j < 3; ++j)
		{
			ca3[j] = '\0';
		}

		ca4[0] = (ca3[0] & 0xfc) >> 2;
		ca4[1] = ((ca3[0] & 0x03) << 4) + ((ca3[1] & 0xf0) >> 4);
		ca4[2] = ((ca3[1] & 0x0f) << 2) + ((ca3[2] & 0xc0) >> 6);
		ca4[3] = ca3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
		{
			encoded.push_back(base64Table[ca4[j]]);
		}

		while (i < 3)
		{
			++i;
			encoded.push_back('=');
		}
	}

	return encoded;
}

std::vector<std::uint8_t> decodeBase64(const char* str, std::uint32_t size) {
	int in_len = size;
	int i = 0;
	int j = 0;
	int in_ = 0;
	char char_array_4[4];
	char char_array_3[3];
	std::vector<std::uint8_t> ret;

	while (in_len-- && (str[in_] != '=') && isBase64(str[in_])) {
		char_array_4[i++] = str[in_]; in_++;
		if (i == 4) {
			for (i = 0; i <4; i++)
				char_array_4[i] = (char) base64Table.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret.push_back(char_array_3[i]);
			i = 0;
		}
	}

	if (i) {
		for (j = i; j <4; j++)
			char_array_4[j] = 0;

		for (j = 0; j <4; j++)
			char_array_4[j] = (char) base64Table.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
	}

	return ret;
}

std::string encodeBase64(const std::string& text)
{
	return encodeBase64(reinterpret_cast<const std::uint8_t*>(text.data()), text.size());
}

std::string encodeBase64(const std::vector<std::uint8_t>& data)
{
	return encodeBase64(data.data(), data.size());
}

std::vector<std::uint8_t> decodeBase64(const std::string& base64str)
{
	return decodeBase64(base64str.data(), base64str.size());
}