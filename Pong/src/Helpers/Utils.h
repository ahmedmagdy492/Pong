#pragma once

#include <iostream>
#include <sstream>

static std::string ConvertUIntToString(unsigned int value) {
	std::stringstream stream;

	stream << value;

	std::string output;
	stream >> output;

	return output;
}