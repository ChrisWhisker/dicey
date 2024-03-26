#include "Reader.h"
#include <iostream>
#include <string>
#include <random>

using std::endl;
using std::cout;

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
const char* Reader::roll(const char* rollStr)
{
	// Sanity check
	if (rollStr == nullptr)
	{
		return "Invalid roll entered.";
	}

	int diceCount, diceSides;
	const char* firstD = std::strchr(rollStr, 'D');
	if (firstD == nullptr) // No 'D' in text
	{
		return "Invalid roll entered.";
	}

	int firstDIndex = firstD - rollStr;

	if (firstDIndex == 0) // 'D' is the first character
	{
		diceCount = 1;
		//return "1";
	}
	else // 'D' is not the first character
	{
		// Get number of dice to roll
		const char* diceCountStr = getSubstring(rollStr, 0, firstDIndex);
		try
		{
			diceCount = std::stoi(diceCountStr);

			if (diceCount < 1)
			{
				return "Invalid number of dice.";
			}
		}
		catch (const std::invalid_argument& ia)
		{
			std::cerr << "Invalid argument: " << ia.what() << endl;
		}
		catch (const std::out_of_range& oor)
		{
			std::cerr << "Out of range error: " << oor.what() << endl;
		}
	}

	// Get dice number of sides
	const char* diceSidesStr = getSubstring(rollStr, firstDIndex + 1, std::strlen(rollStr) - firstDIndex);
	try
	{
		diceSides = std::stoi(diceSidesStr);

		if (diceSides < 1)
		{
			return "Invalid number of sides.";
		}
	}
	catch (const std::invalid_argument& ia)
	{
		std::cerr << "Invalid argument: " << ia.what() << endl;
	}
	catch (const std::out_of_range& oor)
	{
		std::cerr << "Out of range error: " << oor.what() << endl;
	}

	int rolled = roll(diceCount, diceSides);
	cout << "You rolled: " << rolled << endl;

	return diceSidesStr;
}

int Reader::roll(int diceCount, int sides)
{
	int total = 0;

	for (int i = 0; i < diceCount; i++)
	{
		int roll = rollDie(sides);
		cout << "Die " << i << " rolled " << roll << endl;
		total += roll;
	}

	return total;
}

int Reader::rollDie(int sides)
{
	// Create a random device to seed the random number generator
	std::random_device rd;

	// Create a random number engine using the random device as the seed
	std::mt19937 gen(rd());

	// Create a uniform distribution for integers from 1 to 20
	std::uniform_int_distribution<> dis(1, sides);

	// Generate and output a random number
	//cout << "Random number: " << dis(gen) << endl;

	return dis(gen);
}
