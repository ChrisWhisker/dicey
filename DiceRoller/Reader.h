#pragma once
class Reader
{
public:
	const char* toUpper(const char* input);
	const char* translate(const char* input);
	char* getSubstring(const char* str, int start, int length);
};
