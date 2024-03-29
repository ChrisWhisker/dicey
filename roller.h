#ifndef ROLLER_H
#define ROLLER_H

#include <QString>

class Roller
{
public:
    Roller();

    // Roll dice and return the result based on a roll-string
    QString roll(QString rollStr);

    // Get the result of rolling a <sides>-sided die <diceCount> times
    QString roll(int diceCount, int sides);

    // Get the result of rolling a single <sides>-sided die
    int rollDie(int sides);
};

#endif // ROLLER_H
