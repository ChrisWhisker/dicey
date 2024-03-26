#pragma once
class Reader
{
public:
	const char* toUpper(const char* input);
	const char* roll(const char* input);
	char* getSubstring(const char* str, int start, int length);
	int roll(int diceCount, int sides);
	int rollDie(int sides);
};
