#pragma once

#include <string>

#include "validation/Language.h"

bool testHex();
bool testBase64();
bool testXor();
bool testXorBreaker(const std::string& hexStr, const Language& language);
bool testXorBreaker(const Language& lang);
bool findSingleByteXorEncodedMessage(const Language& lang);
bool testStreamXorCipher();
bool testHammingDistance();
bool testRepeatingXorBreaker(const Language& lang);