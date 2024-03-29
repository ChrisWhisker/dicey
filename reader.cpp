#include "reader.h"

#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

const char* Reader::removeWhiteSpace(const char* input) {
    if (input == nullptr) // Check if the input pointer is null
        return nullptr;

    int len = strlen(input);
    char* result = new char[len + 1]; // Allocate memory for the modified string
    int index = 0;

    for (int i = 0; i < len; i++) {
        if (!isspace(input[i])) {
            result[index++] = input[i];
        }
    }
    result[index] = '\0'; // Add null terminator
    cout << "Removed white space: " << result << endl;
    return result;
}

const char* Reader::toUpper(const char* input)
{
    // Copy input to new string
    size_t inputLength = std::strlen(input) + 1;
    char* result = new char[inputLength];
    strcpy_s(result, inputLength, input);

    // Convert each character to uppercase
    for (int i = 0; i < inputLength; ++i)
    {
        result[i] = std::toupper(result[i]);
    }
    cout << "In uppercase: " << result << endl;
    return result;
}



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

int Reader::toInt(const char* input)
{
    try
    {
        return std::stoi(input);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cerr << "Invalid argument: " << ia.what() << endl;
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Out of range error: " << oor.what() << endl;
    }
    return -1;
}
