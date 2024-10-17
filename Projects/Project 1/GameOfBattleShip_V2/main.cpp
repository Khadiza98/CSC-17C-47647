   /*
     * File:   main.cpp
     * Author: Khadiza Akter
     * Created on October 10, 2024, 1:20 PM
     * Purpose: Game of BattleShip
     *          Fill 2-D list with '*'
     *          Apply the Rules of Battleship
     *          Set up player battleship
     *          Specification and implementation of BattleShip class
     */
     //System Level Libraries
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime>    //set for time()
#include <string>   //Strings
using namespace std;//Standard Name-space under which System Libraries reside

//User defined libraries
#include "BattleShip.h" //needed for BattleShip class
#include "BShipSetUp.h" //needed for BShipSetUp class

//Function Prototypes
void gameRules();   //display the game rules

// Execution begins here!
int main(int argc, char** argv) {
    // Random seed
    srand(static_cast<unsigned int>(time(0)));

    // Declare variables
    const int NUM_PLAYERS = 2; // Number of player
    BattleShip objBShip; //Define an object of BattleShip class
    BShipSetUp* bSetUp;  //Define a pointer of BShipSetUp class to create object dynamically
    BShipSetUp bsPlayer[NUM_PLAYERS];// Array of class BShipSetUp
    string playerName;   //To hold the player name

    char choice;         // Take input for checking the start play or game rules
    //BattleShip objBShip; // Define an object of BattleShip class
    bool sGame;          // To track do while-loop for menu

    // Get computer and player matrix (10x10) filled with '*' characters
    auto pcMatrix = objBShip.getMatrixData();
    auto playerMatrix = objBShip.getMatrixData();
        // Output the game statistics or menu to the screen
  //Output the game statistics or menu to the screen
    do {
        sGame = true;
        cout << "\n\t --------------WELCOME TO BATTLESHIP GAME--------------\n";
        cout << "\t (1) Game Rules " << endl;
        cout << "\t ()  Any other key to play " << endl;
        cout << "\t (x) Exit " << endl;
        cout << "\n\t Please choose an item...: ";

        cin >> choice;  // Ask for input to see the rules or continue to game

        if (choice == '1')      gameRules();   //Call function to view the games rules   
        else if (choice == 'x') return 0;      // exit the program 
        else                    sGame = false; // Start to play

    } while (sGame); //End do-while loop
    bSetUp = new BShipSetUp(); //dynamically create an object of BShipSetUp class
    cin.ignore(); //To ignore one or more characters from the input buffer
    cout << "\tPlease enter your name: "; //Ask user to enter name
    getline(cin, playerName); // Take the player name
    bSetUp->setPlayerName(playerName);
    //Display player information
    bSetUp->gameHead();
    //Display player matrix
    bSetUp->drawPlayerArea(playerMatrix, objBShip);
    //Set player ship position and return structure
    bsPlayer[0] = bSetUp->setYourBattleShip(playerMatrix);

    //De-allocate memory
    delete bSetUp;


    return 0;
}

// Function definition for gameRules()
void gameRules() {
    cout << "\n\t BATTLESHIP GAME RULES: " << endl;
    cout << "\t (1) Player and computer both have a 10x10 grid." << endl;
    cout << "\t (2) Take turns guessing where the opponent's ships are." << endl;
    cout << "\t (3) First to sink all opponent's ships wins." << endl;
}

