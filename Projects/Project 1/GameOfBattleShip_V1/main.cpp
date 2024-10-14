   /*
     * File:   main.cpp
     * Author: Khadiza Akter
     * Created on October 07, 2024, 11:15 AM
     * Purpose: Game of BattleShip
     *          Fill 2-D list with '*'
     *          Apply the Rules of Battleship
     *          Specification and implementation of BattleShip class
     */
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime>    //Set for time()
#include "BattleShip.h" //Needed for BattleShip class

    using namespace std;

    // Function Prototypes
    void gameRules();   // Display the game rules

    // Execution begins here!
    int main(int argc, char** argv) {
        // Random seed
        srand(static_cast<unsigned int>(time(0)));

        // Declare variables
        char choice;         // Take input for checking the start play or game rules
        BattleShip objBShip; // Define an object of BattleShip class
        bool sGame;          // To track do while-loop for menu

        // Get computer and player matrix (10x10) filled with '*' characters
        auto pcMatrix = objBShip.getMatrixData();
        auto playerMatrix = objBShip.getMatrixData();
         // Output the game statistics or menu to the screen
        do {
            sGame = true;
            cout << "\n\t --------------WELCOME TO BATTLESHIP GAME--------------\n";
            cout << "\t (1) Game Rules " << endl;
            cout << "\t ()  Any other key to play " << endl;
            cout << "\t (x) Exit " << endl;
            cout << "\n\t Please choose an item...: ";

            cin >> choice;  // Ask for input to see the rules or continue to game

            if (choice == '1') {
                gameRules(); // Call function to view the game rules
            }
            else if (choice == 'x') {
                return 0;
            }
            else {
                // Game logic would go here
                cout << "\n Starting the game...\n";
            }
        } while (sGame);

        return 0;
    }

    // Function definition for gameRules()
    void gameRules() {
        cout << "\n\t BATTLESHIP GAME RULES: " << endl;
        cout << "\t (1) Player and computer both have a 10x10 grid." << endl;
        cout << "\t (2) Take turns guessing where the opponent's ships are." << endl;
        cout << "\t (3) First to sink all opponent's ships wins." << endl;
    }



