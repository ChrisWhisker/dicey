# Dice Roller

![image](https://github.com/ChrisWhisker/dice-roller/assets/6521800/894a13e7-2d8b-4ace-a1fc-f235c529926c)

## Overview
This is a simple dice roller Windows application written in C++ with a Qt Creator 12.0.2 GUI. It allows users to roll one or more dice with different numbers of sides and view the results.

## Getting Started
To run the application, follow these steps:
1. Ensure you have Qt Creator installed on your system.
2. Clone or download the repository to your local machine.
3. Open the project in Qt Creator.
4. Build and run the project.

## Usage
1. Upon launching the application, you'll see the main window with an editable text box at the top labeled "Dice:".
2. Enter the dice you want to roll according to the Valid Rolls section below.
3. Click the "Roll" button to roll the dice.
4. The results of each roll will be displayed under "Subtotal" and the total will appear under "Result". To re-roll the same dice, click the "Roll" button again.

## Valid Rolls

Rule | Valid input | Invalid input
-|-|-
Roll must start with D or a number|"6d6", "D20", "d4"|"4"
No modifiers*|"d8"|"d8+2"
1 die type only*|"d12"|"d12 + 1d4"
No keeping/dropping†|"4d10"|"4d10dl1", "4d10kh3"

*Math operations are being implemented in the next version.

†Ability to keep or drop a number of dice is being implemented in an upcoming version.

## Dependencies
This application is built using Qt Creator, based on Qt 6.6.0. Ensure you have Qt installed on your system to build and run the project.

## Compatibility
This application is developed for Windows systems.

---
Created by [Chris Worcester](https://www.linkedin.com/in/chrisworcester/). Feel free to contribute by forking the repository and submitting pull requests.
