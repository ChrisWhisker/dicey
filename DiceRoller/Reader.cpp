#include "Reader.h"
#include <iostream>
#include <string>

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

// Function to get a substring of a C-style string
char* Reader::getSubstring(const char* str, int start, int length)
{
	if (str == nullptr || start < 0 || length < 0) // Check for null pointer and invalid start/length
		return nullptr;

	int strLength = strlen(str);
	if (start >= strLength) // Check if start index is out of bounds
		return nullptr;

	// Adjust length if it exceeds the length of the remaining string
	length = std::min(length, strLength - start);

	char* sub = new char[length + 1]; // Allocate memory for the substring (+1 for null terminator)

	// Copy characters from the original string to the substring
	std::memcpy(sub, str + start, length);
	sub[length] = '\0'; // Null-terminate the substring

	return sub;
}

// Translate the all-caps input into human-readable dice rolls
const char* Reader::translate(const char* input)
{
	// Sanity check
	if (input == nullptr)
	{
		return "Invalid roll entered";
	}
	
	int diceCount;
	const char* firstD = std::strchr(input, 'D');
	if (firstD == nullptr) // No 'D' in text
	{
		return "Invalid roll entered";
	}
	else
	{
		int firstDIndex = firstD - input;

		if (firstDIndex == 0) // 'D' is the first character
		{
			diceCount = 1;
			return "1";
		}
		else // 'D' is not the first character
		{
			const char* diceCountStr = getSubstring(input, 0, firstDIndex);

			// Get number of dice to roll
			try
			{
				diceCount = std::stoi(diceCountStr);
			}
			catch (const std::invalid_argument& ia)
			{
				std::cerr << "Invalid argument: " << ia.what() << std::endl;
			}
			catch (const std::out_of_range& oor)
			{
				std::cerr << "Out of range error: " << oor.what() << std::endl;
			}

			return diceCountStr;
		}
	}
}
