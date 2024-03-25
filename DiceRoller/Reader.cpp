#include "Reader.h"

#include <iostream>

const char* Reader::toUpper(const char* input)
{
	size_t inputLength = std::strlen(input) + 1;
	// Copy input to new string
	char* modified = new char[inputLength];
	strcpy_s(modified, inputLength, input);

	// Convert each character to uppercase
	for (int i = 0; i < inputLength; ++i)
	{
		modified[i] = std::toupper(modified[i]);
	}

	return modified;
}
