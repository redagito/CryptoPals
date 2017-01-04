#include "Test.h"

#include <iostream>
#include <fstream>

#include "codec/Base64.h"
#include "codec/Hex.h"
#include "codec/Xor.h"

#include "breaker/XorBreaker.h"
#include "validation/HammingDistance.h"

bool testHex()
{
	std::string in =
		"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	return encodeHex(decodeHex(in)) == in;
}

bool testBase64()
{
	std::string in =
		"49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	auto result = encodeBase64(decodeHex(in));
	std::string expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
	return result == expected;
}

bool testXor()
{
	std::string data = "1c0111001f010100061a024b53535009181c";
	std::string key = "686974207468652062756c6c277320657965";
	std::string expected = "746865206b696420646f6e277420706c6179";
	return expected == encodeHex(encodeDecodeXor(decodeHex(data), decodeHex(key)));
}

bool testXorBreaker(const std::string& hexStr, const Language& language)
{
	auto data = decodeHex(hexStr);
	auto keys = breakSingleByteXor(data, language);

	if (!keys.empty())
	{
		std::cout << std::endl;
	}

	for (auto key : keys)
	{
		auto decoded = encodeDecodeXor(data, { key });
		std::cout << std::string((const char*)decoded.data(), decoded.size()) << std::endl;
	}
	return keys.size() == 1;
}

bool testXorBreaker(const Language& lang)
{
	return testXorBreaker("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", lang);
}

bool findSingleByteXorEncodedMessage(const Language& lang)
{
	std::ifstream ifs("data/s1c4.txt");
	std::string line;

	std::vector<std::string> result;
	int i = 0;
	while (std::getline(ifs, line))
	{
		if (testXorBreaker(line, lang))
		{
			result.push_back(line);
		}
	}
	return result.size() == 1;
}

bool testStreamXorCipher()
{
	std::string text = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
	std::string key = "ICE";
	auto encoded = encodeDecodeXor(text, key);
	return encodeHex(encoded) == "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
}

bool testHammingDistance()
{
	bool ret = true;
	ret &= (hammingDistance('a', 'a') == 0);
	ret &= (hammingDistance((char)0xFF, (char)0xF0) == 4);
	ret &= (hammingDistance("this is a test", "wokka wokka!!!") == 37);

	return ret;
}

bool testRepeatingXorBreaker(const Language& lang)
{
	std::string file = "data/s1c6.txt";
	return false;
}