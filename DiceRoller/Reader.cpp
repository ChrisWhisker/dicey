#include "Reader.h"

#include <iostream>

// Return a copy of the input string with its letters in all caps
const char* Reader::toUpper(const char* input)
{
	// Copy input to new string
	size_t inputLength = std::strlen(input) + 1;
	char* modified = new char[inputLength];
	strcpy_s(modified, inputLength, input);

	// Convert each character to uppercase
	for (int i = 0; i < inputLength; ++i)
	{
		modified[i] = std::toupper(modified[i]);
	}
	return modified;
}

// Translate the all-caps input into human-readable dice rolls
const char* Reader::translate(const char* input)
{
	if (input == nullptr)
	{
		return "";
	}
	
	// Simple roll translation: [2d20] or [d10]
	// Get first instance of "D"
	// if all text before it is a number
	//		that is number of dice
	// if no text before it
	//		number of dice is 1
	// else
	//		invalid roll. fail.

	const char* firstD = std::strchr(input, 'D');

	if (firstD == nullptr)
	{
		return "";
	}
	else if (firstD - input == 0)
	{
		return "D is the first character.";
	}
	else
	{
		return "D is NOT the first character.";
	}
}
