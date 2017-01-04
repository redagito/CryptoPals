#include <iostream>

#include "Test.h"

int main(int argc, char** argv)
{
	// English language
	Language lang;
	readDictionary("data/dict/english.txt", lang.dictionary);
	lang.wordMatchRatio = 0.4f;
	lang.maxTextLengthPerSpace = 7.0f;
	lang.minTextLengthPerSpace = 3.0f;
	/*
	std::cout << testHex() << std::endl;
	std::cout << testBase64() << std::endl;
	std::cout << testXor() << std::endl;
	std::cout << testXorBreaker(lang) << std::endl;
	std::cout << findSingleByteXorEncodedMessage(lang) << std::endl;
	std::cout << testStreamXorCipher() << std::endl;
	*/
	std::cout << "Hamming: " << testHammingDistance() << std::endl;
	std::cout << "Stream Xor breaker: " << testRepeatingXorBreaker(lang) << std::endl;
	return 0;
}