#include "FileSystem.h"
#include <fstream>


std::string FileSystem::readFileAsString(std::string path)
{
	std::ifstream fileStream(path);

	std::string fileString;
	std::string line;

	while (!fileStream.eof())
	{
		std::getline(fileStream, line);

		fileString += line;
		fileString += '\n';
	}

	return fileString;
}