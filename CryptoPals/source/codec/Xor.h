#pragma once

#include <cstdint>
#include <vector>
#include <string>

std::vector<std::uint8_t> encodeDecodeXor(
	const std::uint8_t* data, std::uint32_t dataSize,
	const std::uint8_t* key, std::uint32_t keySize);

std::vector<std::uint8_t> encodeDecodeXor(
	const std::vector<std::uint8_t>& data,
	const std::vector<std::uint8_t>& key);

std::vector<std::uint8_t> encodeDecodeXor(
	const std::string& data,
	const std::string& key);