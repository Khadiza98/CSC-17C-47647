/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 22, 2024, 10:10 PM
 * Purpose: Game of BattleShip
 *          Fill 2-D list with '*'
 *          Apply the Rules of Battleship
 *          Set up player battleship
 *          Set up computer battleship
 *          Draw the both matrix and playing zone
 *          Start the play, and allow the user input and computer
            randomly selection input
 *          Specification and implementation of Battleship(base) and
            BShipSetUp(derived)classes

 */
 //System Level Libraries
#include <iostream> //Input-output library
#include <string>   //Strings
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime>    //Set for time()
using namespace std;//Standard Name-space under which System Libraries reside

//User defined libraries
#include "BShipSetUp.h" //needed for BShipSetUp class

//Function Prototypes
void gameRules();   //display the game rules

//Execution begins here!
int main(int argc, char** argv) {
    //Random seed here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    char choice;       // take input for checking the start play or game rules
    const int NUM_PLAYERS = 2; // Number of player
    BShipSetUp bsPlayer[NUM_PLAYERS];// Array of class BShipSetUp
    string playerName;   //To hold the player name
    bool sGame;         // To track do while-loop for menu
    bool tryAgain = true; //Flag to reread the input name


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

    cin.ignore(); //To ignore one or more characters from the input buffer
    cout << "\t Please enter your name: "; //Ask user to enter name
    getline(cin, playerName); // Take the player name

    while (tryAgain) {
        try {
            //create an object of BShipSetUp class and using constructor 
            //to initialize member
            BShipSetUp bSetUp(playerName);
            //Display player information
            bSetUp.gameHead();
            //Display player matrix
            bSetUp.drawPlayerArea(bSetUp.getMatrixData());
            //Set player ship position and return structure
            bsPlayer[0] = bSetUp.setYourBattleShip(bSetUp);
            //Set computer ship position and return structure
            bsPlayer[1] = bSetUp.setComputerBattleShip(bSetUp);
            bSetUp.gameHead();
            bSetUp.showPlayZone();
            bSetUp.startPlay(bsPlayer[0], bsPlayer[1]);
            tryAgain = false;
        }  //End try
        catch (BShipSetUp::InvalidName) {
            cout << "\t Error: invalid input -> [" << playerName
                << "] entered for the Player Name!!" << endl;
            cout << "\t Please enter a valid name: ";
            getline(cin, playerName); // Take the player name

        } //End catch
    } //End while-loop

    //Exit the program
    return 0;
} //end of main function

//*****************************************************************
//Definition of function gameRules
//Input->: None, data on game rules
//Output->:No return, Display the game rules                             
//*****************************************************************
void gameRules() {

    system("cls"); //clear the screen
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
        " - - - - - - - - - - - " << endl;
    cout << " - - - - -                     ~~~Welcome to BattleShip Game~~~   "
        "            - - - - - -" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Battleship game information/rules~ ~"
        "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
        " - - - - - - - - - - - -" << endl;
    cout << "1.Total four battleships for each player, the winner is who"
        " destroy other battleships first" << endl;
    cout << "2.The battlefield is 10x10 grid where you place all four ships\n";
    cout << "3.You can place your ships position using coordinate values(e.g."
        ", A0, B1)where 'A' or 'a' is the row and 1-10 is the col number\n";
    cout << "4.Also, you can place the ship orientation, i.e horizontal or "
        "vertical. For horizontal orientation, type 'h' or 'H', and type"
        " 'v' or 'V' for vertical option" << endl;
    cout << "5.You have total four battle ships: Aircraft Carrier-> 5, "
        "Battleship-> 4, Destroyer-> 3 and Corvette-> 2 units long" << endl;
    cout << "6.You cannot place two ship at any same coordinate location\n";
    cout << "7.After placing your ship position; you are ready to play. To "
        "attack the opponent, enter a position value such as A1 or a1, b9,"
        " j5 (without spacing) and so on,  " << endl;
    cout << "8.If your attack is successful then it is denoted by '@' "
        "and you will continue your turn" << endl;
    cout << "9.If your attack is missed then it is denoted by 'o'"
        " and your turn will be end" << endl;

} //End gameRules function


