#pragma once
class Reader
{
public:
	// Return a copy of the input string with its letters in all caps
	const char* toUpper(const char* input);

	// Roll dice and return the result based on a roll-string
	int roll(const char* rollStr);

	// Get a substring of a C-style string
	char* getSubstring(const char* str, int start, int length);

	// Convert a string containing an integer to an int
	int toInt(const char* input);

	// Get the result of rolling a <sides>-sided die <diceCount> times
	int roll(int diceCount, int sides);

	// Get the result of rolling a single <sides>-sided die
	int rollDie(int sides);
};
