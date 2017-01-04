#pragma once

#include <vector>
#include <string>
#include <cstdint>

std::string encodeBase64(const std::uint8_t* data, std::uint32_t size);
std::vector<std::uint8_t> decodeBase64(const char* str, std::uint32_t size);

// Utility
std::string encodeBase64(const std::string& text);
std::string encodeBase64(const std::vector<std::uint8_t>& data);
std::vector<std::uint8_t> decodeBase64(const std::string& base64str);