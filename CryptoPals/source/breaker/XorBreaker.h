#pragma once

#include <cstdint>
#include <vector>

#include "validation/Language.h"

// Break xor cipher for key byte size 1
// Returns 0 or more possible solutions
std::vector<std::uint8_t> breakSingleByteXor(const std::uint8_t* data, std::uint32_t size, const Language& language);
std::vector<std::uint8_t> breakSingleByteXor(const std::vector<std::uint8_t>& data, const Language& language);