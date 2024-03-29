#ifndef READER_H
#define READER_H

class Reader
{
public:
    // Remove white space characters from a string
    const char* removeWhiteSpace(const char* input);

    // Return a copy of the input string with its letters in all caps
    const char* toUpper(const char* input);

    // Get a substring of a C-style string
    char* getSubstring(const char* str, int start, int length);

    // Convert a string containing an integer to an int
    int toInt(const char* input);
};

#endif // READER_H
