#pragma once

#include <cstdint>
#include <string>
#include <vector>

std::string encodeHex(const std::uint8_t* data, std::uint32_t size);
std::vector<std::uint8_t> decodeHex(const char* str, std::uint32_t size);

// Util
std::string encodeHex(const std::vector<std::uint8_t>& data);
std::vector<std::uint8_t> decodeHex(const std::string& hexStr);