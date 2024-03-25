// DiceRoller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reader.h"
//#include <cstring>
//#include <cctype>

using std::cout;

int main()
{
    Reader reader;
    const char* upper = reader.toUpper("Hello, World!\n");
    cout << upper;
}
