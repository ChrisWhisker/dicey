#ifndef ROLLER_H
#define ROLLER_H

#include <QString>

class Roller
{
public:
    // Static member function to get the instance of the Singleton class
    static Roller& getInstance() {
        // Static local variable to ensure it's initialized only once
        static Roller instance;
        return instance;
    }

    // Delete copy constructor and assignment operator
    Roller(Roller const&) = delete;
    void operator=(Roller const&) = delete;

    // Roll dice and return the result based on a roll-string
    QString roll(QString rollStr, QString &subtotalStr);

    // Get the result of rolling a <sides>-sided die <diceCount> times
    int roll(int diceCount, int sides, QString &subtotalStr);

    // Get the result of rolling a single <sides>-sided die
    int rollDie(int sides);



private:
    // Private constructor to prevent instantiation of this singleton
    Roller() {};
};

#endif // ROLLER_H
