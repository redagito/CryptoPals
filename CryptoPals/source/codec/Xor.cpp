#include "Xor.h"

std::vector<std::uint8_t> encodeDecodeXor(
	const std::uint8_t* data, std::uint32_t dataSize,
	const std::uint8_t* key, std::uint32_t keySize)
{
	std::vector<std::uint8_t> encoded;
	encoded.reserve(dataSize);
	for (std::uint32_t i = 0; i < dataSize; ++i)
	{
		std::uint8_t d = data[i] ^ key[i % keySize];
		encoded.push_back(d);
	}
	return encoded;
}

std::vector<std::uint8_t> encodeDecodeXor(
	const std::vector<std::uint8_t>& data,
	const std::vector<std::uint8_t>& key)
{
	return encodeDecodeXor(data.data(), data.size(), key.data(), key.size());
}

std::vector<std::uint8_t> encodeDecodeXor(
	const std::string& data,
	const std::string& key)
{
	return encodeDecodeXor((const std::uint8_t*) data.data(), data.size(), (const std::uint8_t*) key.data(), key.size());
}