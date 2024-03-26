// DiceRoller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reader.h"
using std::cout;

int main()
{
    Reader reader;
    const char* upper = reader.toUpper("10d20");
    reader.translate(upper);
}
