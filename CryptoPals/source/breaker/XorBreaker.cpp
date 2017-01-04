#include "XorBreaker.h"

#include <iostream>
#include <string>

#include "validation/TextValidation.h"
#include "codec/Xor.h"

std::vector<std::uint8_t> breakSingleByteXor(const std::uint8_t* data, std::uint32_t size, const Language& language)
{
	std::vector<std::uint8_t> keys;

	// For all possible keys
	for (std::uint16_t i = 0; i < 256; ++i)
	{
		std::uint8_t key = static_cast<std::uint8_t>(i);
		
		// Generate decoded message
		auto decoded = encodeDecodeXor(data, size, &key, 1);

		// Validate message
		if (isASCIIText(decoded))
		{
			// Check for language
			if (isText((const char*)decoded.data(), decoded.size(), language))
			{
				keys.push_back(key);
			}
		}
	}
	return keys;
}

std::vector<std::uint8_t> breakSingleByteXor(const std::vector<std::uint8_t>& data, const Language& language)
{
	return breakSingleByteXor(data.data(), data.size(), language);
}