#include "Language.h"

#include <fstream>

bool readDictionary(const std::string& file, Dictionary& dictionary)
{
	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		return false;
	}

	std::string line;
	while (std::getline(ifs, line))
	{
		if (!line.empty())
		{
			dictionary.insert(line);
		}
	}
	return !dictionary.empty();
}