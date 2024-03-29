#include "roller.h"

#include <iostream>
#include <random>

using std::cout;
using std::endl;

Roller::Roller() {}

QString Roller::roll(QString rollStr, QString &subtotalStr)
{
    // Sanity check
    if (rollStr == nullptr || rollStr == "")
    {
        std::cerr << "Roll string is null." << endl;
        return "Invalid roll entered.";
    }

    rollStr = rollStr.simplified().toUpper();

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
    QString diceSidesStr = rollStr.mid(firstDIndex + 1);
    bool success;
    diceSides = diceSidesStr.toInt(&success);
    if (!success || diceSides < 1)
    {
        std::cerr << "Invalid number of sides." << endl;
        return "Invalid number of sides.";
    }

    int result = roll(diceCount, diceSides, subtotalStr);
    return QString::number(result);
}

int Roller::roll(int diceCount, int sides, QString &subtotalStr)
{
    int total = 0;

    for (int i = 0; i < diceCount; i++)
    {
        int roll = rollDie(sides);
        subtotalStr += "D" + QString::number(sides) + " #" + QString::number(i + 1) + " -> " + QString::number(roll);
        if (i < diceCount - 1)
        {
            subtotalStr += "\n";
        }
        cout << "Die " << i << " rolled " << roll << endl;
        total += roll;
    }

    return total;
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
