/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on October 12, 2024, 1:27 PM
 * Purpose: Implementation file for BShipSetUp class
 */

#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime> //set for time()
#include <string>
#include <cstring>
#include <list>
#include <map>
using namespace std;//Standard Name-space under which System Libraries reside

#include "BShipSetUp.h"

//*****************************************************************
//Definition of function gameHead. This is a member function of   *
//BShipSetUp class and display the player name                    
//*****************************************************************
void BShipSetUp::gameHead() {
    system("cls");
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    cout << " -                     ~~~Welcome to BattleShip~~~               -\n";
    cout << " -                     ~~~Player Name: " << playerName << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
}
//**********************************************************************
//Definition of operator= . This function overloaded = operator
//when assign one object to another object.
//Return constant BShipSetUp object.
//**********************************************************************
const BShipSetUp BShipSetUp::operator=(const BShipSetUp& right) {
    if (this != &right) {
        memcpy(aircraft, right.aircraft, 5 * 2 * sizeof(int));
        memcpy(battleship, right.battleship, 4 * 2 * sizeof(int));
        memcpy(destroyer, right.destroyer, 3 * 2 * sizeof(int));
        memcpy(corvette, right.corvette, 2 * 2 * sizeof(int));
    }
    return *this;
}


//*****************************************************************
//Definition of function drawPlayerArea                           *
//Display player matrix                                           *
//*****************************************************************
void BShipSetUp::drawPlayerArea(list<std::list<char>> matrixData) {
    system("cls");
    int i = 0;
    char yCoord[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0' };     // declare a character array for maintain y-coordinate as a character
    cout << "           Your Area                           " << endl;              // write a text head for computer zone
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -            " << endl;                     // display the x-coordinate value
    for (const auto& row : matrixData) {                                                // loop to draw the 2-D matrix
        cout << " | " << yCoord[i] << " | ";
        i++;
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << "|" << endl;
    }
}
//*************************************************************************
//Definition of function letterToRowNumber.This function is declared as a                        *
//friend by Battleship class and it will determine the letter (A, B, C...J)
// value to integer y-axis value (0,1,2...9) using map container          
//*************************************************************************
int letterToRowNumber(char letter)
{
    std::map<char, int> yCoord = {                      //declare a map for maintaining coordinate values
    {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4},
    {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}
    };
    if (yCoord.find(letter) != yCoord.end()) { //check for valid key selection
        return yCoord[letter];             // return the value of map element     
    }
    else {
        return -1;                          // invalid selection
    }
    
}
//*****************************************************************
//Definition of function conflictWithOtherShip                    *
//This check the ship position conflict with other ship or not    *
//*****************************************************************
bool BShipSetUp::conflictWithOtherShip(list<std::list<char>> playerMatrix, int row, int col,
        int shipLength, char shipOrientation)
{
    if (shipOrientation == 'h')                      // check the ship orientation
    {
        auto rowIt = std::next(playerMatrix.begin(), row);
        for (int i = col; i < col + shipLength; i++) // for horizontal orientation check the column till ship length
        {
            auto k = std::next(rowIt->begin(), i);
            if (*k != '*') {       // check the character for position of the matrix, if it is not '*' that means it is conflict with other ship position
                return true;                         // and return true   
            }
        }
    }
    else
    {
        //auto colIt = std::next(playerMatrix.begin(), col);
        for (int i = row; i < row + shipLength; i++)  // for horizontal orientation check the row till ship length
        {
            auto rowIt = std::next(playerMatrix.begin(), i);
            auto colIt = std::next(rowIt->begin(), col); // Accessing the column

            //auto k = std::next(colIt->begin(), row);
            if (*colIt != '*') {       // check the character for position of the matrix, if it is not '*' that means it is conflict with other ship position
                return true;                         // and return true   
            }
            //if (playerMatrix[i][col] != '*') { // check the character for position of the matrix, if it is not '*' that means it is conflict with other ship position         
              //  return true;                    // and return true 
            //}
        }
    }
    return false;
}

//*****************************************************************
//Definition of function setYourBattleShip                        *
//Set player ship position and return structure                   *
//*****************************************************************
BShipSetUp BShipSetUp::setYourBattleShip(BShipSetUp b) {

    const int AIRCRAFT_LENGTH = 5;     // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;   // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;    // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;     // Unit length of the corvette
    const int POSITION_LENGTH = 2;     // Input length of a grid position
    char shipOrientiation;             // Take the input for ship orientation (h or v)                              
    string shipPosition = "";          // Take the input for ship starting position (a0, a2...j9 so on) 
    BattleShip obj;                    // Declare an object of BattleShip

    //BShipSetUp b;
    playerMatrix = getMatrixData();
    while (true) {                              // Loop for setup the aircraft position    
        cout << "Setup your aircraft carrier location" << endl;
        cout << "Select your aircraft carrier orientation "
                "(h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' 
                    || tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";     // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            } //end else
        } //end while-loop
        cout << "Enter the aircraft position without a space "
                "(example: a0, a1...): " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for air craft position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J')
                     && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid aircraft position without a space"
                            " (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            } //end if
            else {
                cout << "Enter a valid aircraft position without a"
                        " space (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }


        }

        if (tolower(shipOrientiation) == 'h') { // check for horizontal setup

            int startPositionRow = letterToRowNumber(shipPosition[0]);// Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            if (startPositionCol > AIRCRAFT_LENGTH) { // not able to setup the aircraft horizontally from this position
                cout << "You cannot place the aircraft in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else {
                int counter = 0;
                auto rowIt = std::next(playerMatrix.begin(), startPositionRow); // Accessing the row
                for (int i = startPositionCol; 
                        i < startPositionCol + AIRCRAFT_LENGTH; i++) {
                    auto colIt = std::next(rowIt->begin(), i);
                    *colIt = 'A';    // set the player matrix with 'A' for indicating the aircraft location
                    b.aircraft[counter][0] = startPositionRow;  // insert the ship position values in the structure variable
                    b.aircraft[counter][1] = i;
                    counter++;  // increase the counter one
                }
                break;
            } //end else
        } //end if
        if (tolower(shipOrientiation) == 'v') { // check for the vertical setup
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';  // make a character value to integer

            if (startPositionRow > AIRCRAFT_LENGTH) { // not able to setup the aircraft vertically from this position
                cout << "You cannot place the aircraft in this position."
                        " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else {
                int counter = 0;
                for (int i = startPositionRow; 
                        i < startPositionRow + AIRCRAFT_LENGTH; i++)
                {
                    auto rowIt = std::next(playerMatrix.begin(), i);
                    auto colIt = std::next(rowIt->begin(), startPositionCol); // Accessing the column
                    *colIt = 'A';
                    //playerMatrix[i][startPositionCol] = 'A'; // set the player matrix with 'A' for indicating the aircraft location
                    b.aircraft[counter][0] = i;              // insert the ship position values in the structure variable
                    b.aircraft[counter][1] = startPositionCol;
                    counter++; // increase the counter one
                } //end for
                break;
            } //end else

        } //end if
    } //end while-loop

    drawPlayerArea(playerMatrix);  // redraw the player area with the position of battleship    
    shipOrientiation = '\0';     // reset the ship orientation
    shipPosition.clear();        // clear the shipPosition
    while (true)                // loop for setup the battleship position    
    {
        cout << "Setup your battleship carrier location" << endl;
        cout << "Select your battleship carrier orientation"
                " (h-horizontal) and (v-vertical) : " << endl;
        while (true) {    // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;  // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' || tolower(shipOrientiation) == 'v') { // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            } //end if
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n"; // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            } //end else
        }
        cout << "Enter the battleship position without a space"
                " (example: a0, a1...): " << endl;
        while (true) {  // take a infinite loop for satisfying the valid input for battleship position
            getline(cin, shipPosition); // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') 
                     && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                } //end if
                else {
                    cout << "Enter a valid battleship position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                } //end else
            }
            else {
                cout << "Enter a valid battleship position without a space"
                        " (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
            
        } //end while-loop

        if (tolower(shipOrientiation) == 'h')   // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]); // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                               startPositionRow, startPositionCol,
                               BATTLESHIP_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > BATTLESHIP_LENGTH + 2) || isConflict)      // not able to setup the battleship horizontally from this position
            {
                cout << "You cannot place the battleship in this position."
                        "TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                auto rowIt = std::next(playerMatrix.begin(), startPositionRow); // Accessing the row
                for (int i = startPositionCol; 
                        i < startPositionCol + BATTLESHIP_LENGTH; i++)
                {
                    auto colIt = std::next(rowIt->begin(), i);
                    *colIt = 'B';    // set the player matrix with 'A' for indicating the aircraft location
                    //playerMatrix[startPositionRow][i] = 'B';    // set the player matrix with 'B' for indicating the battle location
                    b.battleship[counter][0] = startPositionRow;   // insert the ship position values in the structure variable
                    b.battleship[counter][1] = i;
                    counter++; // increase the counter one
                } //end for
                break;
            } //end else
        } //end if
        if (tolower(shipOrientiation) == 'v')   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]); // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';             // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                  startPositionRow, startPositionCol, BATTLESHIP_LENGTH,
                  tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > BATTLESHIP_LENGTH + 2) || isConflict) // not able to setup the battleship vertically from this position

            {
                cout << "You cannot place the battleship in this position."
                        " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow 
                        + BATTLESHIP_LENGTH; i++)
                {
                    auto rowIt = std::next(playerMatrix.begin(), i);
                    auto colIt = std::next(rowIt->begin(), startPositionCol); // Accessing the column
                    *colIt = 'B';
                    //playerMatrix[i][startPositionCol] = 'B';  // set the player matrix with 'B' for indicating the battle location
                    b.battleship[counter][0] = i;             // insert the ship position values in the structure variable
                    b.battleship[counter][1] = startPositionCol;
                    counter++;   // increase the counter one
                } //end  for
                break;
            } //end else

        } //end if
    } //end while
    drawPlayerArea(playerMatrix);  // redraw the player area with the position of destroyer    
    shipOrientiation = '\0';                   // reset the ship orientation
    shipPosition.clear();   // clear the shipPosition
    while (true)                                        // loop for setup the battleship position    
    {
        cout << "Setup your destroyer carrier location" << endl;
        cout << "Select your destroyer carrier orientation (h-horizontal)"
                " and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' ||
                tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";     // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the destroyer position without a space "
                "(example: a0, a1...): " << endl;
        while (true) {    // take a infinite loop for satisfying the valid input for destroyer position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') 
                     && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid destroyer position without a space"
                            " (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid destroyer position without a space"
                        " (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            } //endl else
            
        }

        if (tolower(shipOrientiation) == 'h')  { // check for horizontal setup
            int startPositionRow = letterToRowNumber(shipPosition[0]); // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                  startPositionRow, startPositionCol, DESTROYER_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > DESTROYER_LENGTH + 3) || isConflict) { // not able to setup the battleship horizontally from this position
                cout << "You cannot place the battleship in this position."
                        " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else
            {
                int counter = 0;
                auto rowIt = std::next(playerMatrix.begin(), startPositionRow); // Accessing the row

                for (int i = startPositionCol; i < startPositionCol 
                        + DESTROYER_LENGTH; i++)
                {
                    auto colIt = std::next(rowIt->begin(), i);
                    *colIt = 'D';    // set the player matrix with 'A' for indicating the aircraft location
                    //playerMatrix[startPositionRow][i] = 'D';                          // set the player matrix with 'D' for indicating the battle location
                    b.destroyer[counter][0] = startPositionRow;                             // insert the ship position values in the structure variable
                    b.destroyer[counter][1] = i;
                    counter++;                                                      // increase the counter one
                }
                break;
            } //end else
        }
        if (tolower(shipOrientiation) == 'v')                                   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                    startPositionRow, startPositionCol, DESTROYER_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > DESTROYER_LENGTH + 3) || isConflict) { // not able to setup the destroyer vertically from this position

                cout << "You cannot place the battleship in this position."
                        " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow 
                        + DESTROYER_LENGTH; i++)
                {
                    auto rowIt = std::next(playerMatrix.begin(), i);
                    auto colIt = std::next(rowIt->begin(), startPositionCol); // Accessing the column
                    *colIt = 'D';
                    //playerMatrix[i][startPositionCol] = 'D'; // set the player matrix with 'D' for indicating the battle location
                    b.destroyer[counter][0] = i;             // insert the ship position values in the structure variable
                    b.destroyer[counter][1] = startPositionCol;
                    counter++;// increase the counter one
                }
                break;
            }

        }
    }

    drawPlayerArea(playerMatrix); // redraw the player area with the position of CORVETTE    
    shipOrientiation = '\0';                   // reset the ship orientation
    shipPosition.clear();   // clear the shipPosition
    while (true)         // loop for setup the battleship position    
    {
        cout << "Setup your corvette carrier location" << endl;
        cout << "Select your corvette carrier orientation "
                "(h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' ||
                    tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n"; // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the corvette position without a space "
                "(example: a0, a1...): " << endl;
        while (true) {  // take a infinite loop for satisfying the valid input for corvette position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') 
                     && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid corvette position without a space "
                            "(example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid corvette position without a space"
                        " (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
           
        }

        if (tolower(shipOrientiation) == 'h')  // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                 startPositionRow, startPositionCol, CORVETTE_LENGTH, 
                 tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > CORVETTE_LENGTH + 4) || isConflict) {  // not able to setup the battleship horizontally from this position
                cout << "You cannot place the corvette in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                auto rowIt = std::next(playerMatrix.begin(), startPositionRow); // Accessing the row
                for (int i = startPositionCol; i < startPositionCol 
                        + CORVETTE_LENGTH; i++)
                {
                    auto colIt = std::next(rowIt->begin(), i);
                    *colIt = 'C';    // set the player matrix with 'A' for indicating the aircraft location

                     //playerMatrix[startPositionRow][i] = 'C';  // set the player matrix with 'C' for indicating the battle location
                    b.corvette[counter][0] = startPositionRow;  // insert the ship position values in the structure variable
                    b.corvette[counter][1] = i;
                    counter++; // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v') { // check for the vertical setup
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, 
                    startPositionRow, startPositionCol, CORVETTE_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > CORVETTE_LENGTH + 4) || isConflict) { // not able to setup the destroyer vertically from this position
                cout << "You cannot place the battleship in this position."
                        " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow + CORVETTE_LENGTH; i++)
                {
                    auto rowIt = std::next(playerMatrix.begin(), i);
                    auto colIt = std::next(rowIt->begin(), startPositionCol); // Accessing the column
                    *colIt = 'C';
                    //playerMatrix[i][startPositionCol] = 'C';// set the player matrix with 'C' for indicating the battle location
                    b.corvette[counter][0] = i;  // insert the ship position values in the structure variable
                    b.corvette[counter][1] = startPositionCol;
                    counter++;  // increase the counter one
                }
                break;
            }

        }
    } //end while-loop
    drawPlayerArea(playerMatrix); // redraw the player area with the position of destroyer    


    return b;
} //end of setYourBattleShip

//*****************************************************************
//Definition of function setComputerBattleShip                    *
//Set computer ship position and return ship position             *
//*****************************************************************
BShipSetUp BShipSetUp::setComputerBattleShip(BShipSetUp computerShipPosition) {
    const int AIRCRAFT_LENGTH = 5;                      // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;                    // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;                     // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;                      // Unit length of the corvette
    computerMatrix = getMatrixData();
    //BShipSetUp computerShipPosition = BShipSetUp();  // Declare a structure variable to store computer ship position
    //setup aircraft
    int rowPosition = rand() % 2 + 2;                       // Randomly select a row position from 2-3  
    int colPosition = rand() % 2 + 2;                       // Randomly select a column position from 2-3
    int shipOrientation = rand() % 2;                   // Select a ship orientation value 0 or 1
    if (shipOrientation == 0)                           // If value is 0 then consider the orientation as horizontal;
    {
        auto rowIt = std::next(playerMatrix.begin(), rowPosition); // Accessing the row 
        int counter = 0;
        for (int i = colPosition; i < colPosition + AIRCRAFT_LENGTH; i++)
        {
            auto colIt = std::next(rowIt->begin(), i); //assigning data using iterator
            *colIt = 'A';    // set the player matrix with 'A' for indicating the aircraft location

            computerShipPosition.aircraft[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.aircraft[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {                                                                       // Otherwise orientation is vertical
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + AIRCRAFT_LENGTH; i++)
        {
            auto rowIt = std::next(playerMatrix.begin(), i);
            auto colIt = std::next(rowIt->begin(), colPosition); // Accessing the column
            *colIt = 'A';
            computerShipPosition.aircraft[counter][0] = i;              // Insert the ship position values in the structure variable
            computerShipPosition.aircraft[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }

    //setup the battleship
    rowPosition = (rand() % 2) + 5;                       // Randomly select a row position from 5-6  
    colPosition = (rand() % 2) + 5;                       // Randomly select a column position from 5-6
    shipOrientation = (rand() % 2);                   // Select a ship orientation value 0 or 1
    if (shipOrientation == 0)                       // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        auto rowIt = std::next(playerMatrix.begin(), rowPosition); // Accessing the row
        for (int i = colPosition; i < colPosition + BATTLESHIP_LENGTH; i++)
        {
            auto colIt = std::next(rowIt->begin(), i);
            *colIt = 'B';    // set the player matrix with 'B' for indicating the aircraft location
            //computerMatrix[rowPosition][i] = 'B';                          // Set the computer matrix with 'B' for indicating the battleship location
            computerShipPosition.battleship[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.battleship[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {                                                                       // Otherwise orientation is vertical
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + BATTLESHIP_LENGTH; i++)
        {
            auto rowIt = std::next(playerMatrix.begin(), i);
            auto colIt = std::next(rowIt->begin(), colPosition); // Accessing the column
            *colIt = 'B';
            //computerMatrix[i][colPosition] = 'B';                       // Set the player matrix with 'B' for indicating the battle location
            computerShipPosition.battleship[counter][0] = i;              // Insert the ship position values in the structure variable
            computerShipPosition.battleship[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }

    //setup the corvette
    rowPosition = (rand() % 2) + 8;                   // Randomly select a row position from 8-9  
    colPosition = (rand() % 3);                       // Randomly select a column position from 0-2
    shipOrientation = (rand() % 2);
    if (shipOrientation == 0)                         // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        auto rowIt = std::next(playerMatrix.begin(), rowPosition); // Accessing the row

        for (int i = colPosition; i < colPosition + DESTROYER_LENGTH; i++)
        {
            auto colIt = std::next(rowIt->begin(), i);
            *colIt = 'D';    // set the player matrix with 'D' for indicating the aircraft location
            //computerMatrix[rowPosition][i] = 'D';                          // Set the computer matrix with 'D' for indicating the battleship location
            computerShipPosition.destroyer[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.destroyer[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {
        // Otherwise orientation is vertical
        rowPosition = (rand() % 3);                       // Randomly select a row position from 0-2  
        colPosition = (rand() % 2) + 8;                   // Randomly select a column position from 8-9
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + DESTROYER_LENGTH; i++)
        {
            auto rowIt = std::next(playerMatrix.begin(), i);
            auto colIt = std::next(rowIt->begin(), colPosition); // Accessing the column
            *colIt = 'D';
            //computerMatrix[i][colPosition] = 'D';                       // Set the player matrix with 'D' for indicating the battle location
            computerShipPosition.destroyer[counter][0] = i;            // Insert the ship position values in the structure variable
            computerShipPosition.destroyer[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }
    //setup the destroyer
    shipOrientation = (rand() % 2);                    // Randomly select ship orientation for destroyer 
    if (shipOrientation == 0)                         // If value is 0 then consider the orientation as horizontal;
    {
        rowPosition = (rand() % 2);                   // Randomly select a row position from 0-1  
        colPosition = (rand() % 7);                       // Randomly select a column position from 0-6
        int counter = 0;
        auto rowIt = std::next(playerMatrix.begin(), rowPosition); // Accessing the row
        for (int i = colPosition; i < colPosition + CORVETTE_LENGTH; i++)
        {
            auto colIt = std::next(rowIt->begin(), i);
            *colIt = 'C';    // set the player matrix with 'D' for indicating the aircraft location
            //computerMatrix[rowPosition][i] = 'C';                          // Set the computer matrix with 'C' for indicating the battleship location
            computerShipPosition.corvette[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.corvette[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {
        // Otherwise orientation is vertical
        rowPosition = (rand() % 5) + 2;                       // Randomly select a row position from 2-6  
        colPosition = (rand() % 2);                   // Randomly select a column position from 0-1
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + CORVETTE_LENGTH; i++)
        {
            auto rowIt = std::next(playerMatrix.begin(), i);
            auto colIt = std::next(rowIt->begin(), colPosition); // Accessing the column
            *colIt = 'C';
            //computerMatrix[i][colPosition] = 'C';                       // Set the player matrix with 'C' for indicating the battle location
            computerShipPosition.corvette[counter][0] = i;            // Insert the ship position values in the structure variable
            computerShipPosition.corvette[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }
    return computerShipPosition;
}



