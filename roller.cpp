#include "roller.h"

#include <iostream>
#include <random>

using std::cout;
using std::endl;

Roller::Roller() {}

QString Roller::roll(QString rollStr)
{
    // Sanity check
    if (rollStr == nullptr)
    {
        std::cerr << "Roll string is null." << endl;
        return "Invalid roll entered.";
    }

    rollStr = rollStr.simplified().toUpper(); // TODO Remove white space in middle of string also

    int diceCount, diceSides;
    int firstDIndex = rollStr.indexOf('D');
    if (firstDIndex == -1) // No 'D' in text
    {
        std::cerr << "No D found in roll string." << endl;
        return "Invalid roll entered.";
    } else if (firstDIndex == 0) // 'D' is the first character
    {
        diceCount = 1;
    }
    else // 'D' is not the first character
    {
        // Get number of dice to roll
        // const char* diceCountStr = getSubstring(rollStr, 0, firstDIndex);
        QString diceCountStr = rollStr.mid(0, firstDIndex);
        bool success;
        diceCount = diceCountStr.toInt(&success);
        if (!success)
        {
            std::cerr << "Invalid number of dice." << endl;
            return "Invalid number of dice.";
        }
    }

    // Get dice number of sides
    // const char* diceSidesStr = getSubstring(rollStr, firstDIndex + 1, std::strlen(rollStr) - firstDIndex);
    QString diceSidesStr = rollStr.mid(firstDIndex + 1);
    bool success;
    diceSides = diceSidesStr.toInt(&success);
    if (!success || diceSides < 1)
    {
        std::cerr << "Invalid number of sides." << endl;
        return "Invalid number of sides.";
    }

    QString result = roll(diceCount, diceSides);
    return result;
}

QString Roller::roll(int diceCount, int sides)
{
    QString result = "";
    int total = 0;

    for (int i = 0; i < diceCount; i++)
    {
        int roll = rollDie(sides);
        result += "D" + QString::number(sides) + " #" + QString::number(i + 1) + " -> " + QString::number(roll) + "\n";
        cout << "Die " << i << " rolled " << roll << endl;
        total += roll;
    }

    result += "\nTOTAL: " + QString::number(total);
    return result;
}

int Roller::rollDie(int sides)
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
