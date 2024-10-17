/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on October 10, 2024, 1:26 PM
 * Purpose: Specification file for BShipSetUp class
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H
#include <string>
using namespace std;

#include "BattleShip.h"

//class declaration
class BShipSetUp {    // Declare a class for different types battle ship set up
    private:
        string playerName; // Declare the input array to take player name
        int aircraft[5][2]; //Aircraft length is 5 for tracking its coordinate value
        int battleship[4][2]; // Battleship length is 4 for tracking its coordinate values (row,col)
        int destroyer[3][2]; // Destroyer length is 3 for its coordinate values (row,col)
        int corvette[2][2]; // Corvette length is 2 for tracking its coordinate values (row,col)   
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(list<std::list<char>>, int, int, int, char);
        
    public:
        //set playerName inline function
        void setPlayerName(string name) {
            playerName = name;
        }
        string getPlayerName()const {return playerName;} //Accessor inline function, return playerName
        BShipSetUp setYourBattleShip(list<std::list<char>>); // mutator function,and set player ship position and return structure
        //Determine the letter (A,...J) value to integer y-axis value (0,1,2...9) using enum identifier 
        friend int letterToRowNumber(char); 
        void drawPlayerArea(list<std::list<char>>, const BattleShip&); //Display player matrix     
        void gameHead(); //Display player name

}; 
#endif /* BSHIPSETUP_H */

