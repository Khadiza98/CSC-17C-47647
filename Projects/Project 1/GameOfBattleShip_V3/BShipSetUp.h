/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on October 12, 2024, 1:27 PM
 * Purpose: Specification file for BShipSetUp class
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H
#include <string>
using namespace std;

#include "BattleShip.h"

//class declaration
class BShipSetUp :public BattleShip {    // Declare a class for different types battle ship set up
    private:
        string playerName; // Declare the input array to take player name
        int aircraft[5][2]; //Aircraft length is 5 for tracking its coordinate value
        int battleship[4][2]; // Battleship length is 4 for tracking its coordinate values (row,col)
        int destroyer[3][2]; // Destroyer length is 3 for its coordinate values (row,col)
        int corvette[2][2]; // Corvette length is 2 for tracking its coordinate values (row,col)   
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(list<std::list<char>>, int, int, int, char);
        
    public:
        //Exception class for InvalidName
        class InvalidName {};
        //constructor #1
        BShipSetUp() {
            playerName = "";
        }
        //constructor #2
        BShipSetUp(string name) {
            bool space = false;
            if (name.empty()) throw InvalidName();
            else if (name.size() > 0) {
                for (int i = 0; i < name.size(); i++) {
                    if (isspace(name[i])) space = true;
                    else {
                        space = false;
                        break;
                    }
                }
                if (space == true) throw InvalidName();
                else              playerName = name;
            }
        }
        string getPlayerName()const {return playerName;} //Accessor inline function, return playerName
        //BShipSetUp setYourBattleShip(list<std::list<char>>); // mutator function,and set player ship position and return structure
        //Determine the letter (A,...J) value to integer y-axis value (0,1,2...9) using enum identifier 
        // mutator function,and set player ship position and return ship members
        BShipSetUp setYourBattleShip(BShipSetUp);
        //Set computer ship position and return ship members
        BShipSetUp setComputerBattleShip(BShipSetUp);
        list<list<char>> playerMatrix; // to hold player matrix information 
        list<list<char>> computerMatrix;// to hold computer Matrix information 

        friend int letterToRowNumber(char); 
        void drawPlayerArea(list<std::list<char>>); //Display player matrix     
        void gameHead(); //Display player name
        const BShipSetUp operator=(const BShipSetUp& right);
}; 
#endif /* BSHIPSETUP_H */

