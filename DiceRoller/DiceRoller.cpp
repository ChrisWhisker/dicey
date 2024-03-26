// DiceRoller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reader.h"
using std::cout;

int main()
{
    Reader reader;
    reader.roll("10 d20");
}
