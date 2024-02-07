Task 2. Fishing game

What should be done
Implement a simple fishing simulation game.
The playing field consists of nine sectors of a conditional pond.
At the beginning of the game, a fish appears in one of these sectors using a random number generator.
In the same way, three boots are collected randomly across sectors of the pond.
In this case, a boot and a fish cannot be in the same place at the same time, just like several boots at once in one of the sectors.

The player throws a fishing rod with bait into one of the sectors, the number of which is determined in the standard way through the console.
The player's task is to guess the sector in which the fish is located and, thus, catch it.
If the player lands on an empty sector, then the fishing rod must be cast again.
If the player catches the boot, the game ends with a negative result.

The task must be implemented using exceptions: upon successful casting of the fishing rod, a sequential special user output, after which the program should change and notify the user about successful fishing and the number of variables that he needed for this.
If a boot was caught, then the conclusion should be drawn that the catch was unsuccessful.
