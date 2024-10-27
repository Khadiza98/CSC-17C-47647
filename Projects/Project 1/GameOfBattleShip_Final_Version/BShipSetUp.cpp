/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on October 26, 2024, 10:02 PM
 * Purpose: Implementation file for BShipSetUp class
 */
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime>    //Time functions, often for random seeds
#include <string>   //String manipulation
#include <cstring>  //C-string handling
#include <list>     // lsit STL
#include <map>      //Key-value pairs, sorted by key
#include <set>      //Unique elements, sorted
#include <queue>    //FIFO structure
#include <stack>    // LIFO structure
#include <unordered_map>//Hash table, key-value pairs, unordered
#include <algorithm>// work with algorithm

using namespace std;//Standard Name-space under which System Libraries reside

#include "BShipSetUp.h"

//*****************************************************************
//Definition of function gameHead. This is a member function of   *
//BShipSetUp class and display the player name                    
//*****************************************************************
void BShipSetUp::gameHead() {
    //system("cls");
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
    stack<char> charStack;//stack to store hearder info
    string header = "- - - 0 1 2 3 4 5 6 7 8 9 -";
    // Push each character from the string into the stack
    for (char c : header) {
        charStack.push(c);
    }
    queue<char> yCoord;
    char coords[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
     // Push coordinates into queue
    for (char c : coords) {
        yCoord.push(c);
    }    cout << "           Your Area                           " << endl;  // write a text head for computer zone
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -            " << endl;              // display the x-coordinate value
    for (const auto& row : matrixData) {                                     // loop to draw the 2-D matrix
        cout << " | " << yCoord.front() << " | ";   // Get the front element
        yCoord.pop();                               // Remove the front element
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
                return true;           // and return true   
            }
            
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
        auto rowIt = std::next(computerMatrix.begin(), rowPosition); // Accessing the row 
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
            auto rowIt = std::next(computerMatrix.begin(), i);
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
        auto rowIt = std::next(computerMatrix.begin(), rowPosition); // Accessing the row
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
            auto rowIt = std::next(computerMatrix.begin(), i);
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
        auto rowIt = std::next(computerMatrix.begin(), rowPosition); // Accessing the row

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
            auto rowIt = std::next(computerMatrix.begin(), i);
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
        auto rowIt = std::next(computerMatrix.begin(), rowPosition); // Accessing the row
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
            auto rowIt = std::next(computerMatrix.begin(), i);
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
//*****************************************************************
//Definition of function showPlayZone                    
//This draw the computer and player play zone    
//*****************************************************************
void BShipSetUp::showPlayZone() {
    
    char charArray[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    set<char> yCoord;// to hold row data
    // Use copy  method to copy elements from charArray into the set
    copy(std::begin(charArray), std::end(charArray), std::inserter(yCoord, yCoord.end()));
    cout << " -          Computer Zone                          Your Zone      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -           - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    // Accessing all elements using an iterator
    //for (const auto& elem : yCoord) {
      //  cout << " | " << elem << " | ";    // Set the y-column 'A' to 'J'
    //}
    set<char>::iterator yItem = yCoord.begin();
    list<list<char>>::iterator playerRow_it = playerMatrix.begin();
    // Accessing all computerMatrix using bidirection iterator
    for (list<list<char>>::iterator row_it = computerMatrix.begin(); row_it != computerMatrix.end(); ++row_it) {
        cout << " | " << *yItem << " | ";    // Set the y-column 'A' to 'J'
        for (list<char>::iterator elem_it = row_it->begin(); elem_it != row_it->end(); ++elem_it) {
            if (*elem_it >= 'A' && *elem_it <= 'D') // Hide the computer ship position
            {
                cout << "* ";   // Display the computer matrix
            }
            else {
                cout << *elem_it << " ";   // Display the computer matrix
            }
            
        }
        cout << "|           | " << *yItem << " | ";     //set the y-column 'A' to 'J'
        for (list<char>::iterator ele_it = playerRow_it->begin(); ele_it != playerRow_it->end(); ++ele_it) {
            cout << *ele_it << " ";   // Display the computer matrix
        }
        cout << "|" << endl;
        advance(yItem, 1); // Advance the iterator to the one element
        ++playerRow_it;
    }
}

//*****************************************************************
//Definition of function startPlay                    *
//This function allow to input player and computer attack position each other   *
//*****************************************************************
void BShipSetUp::startPlay(BShipSetUp battleShipPlayer, BShipSetUp battleShipComputer)
{
     unordered_map<int, char> yCoord = {
        {0, 'A'}, {1, 'C'}, {2, 'B'}, {3, 'E'}, {4, 'D'},
        {5, 'F'}, {6, 'G'}, {7, 'H'}, {8, 'I'}, {9, 'J'}
    };
    // Finding the minimum value from unordered_map
    auto minElement = min_element(
        yCoord.begin(), yCoord.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; }
    );

    // Finding the maximum value from unordered_map
    auto maxElement = max_element(
        yCoord.begin(), yCoord.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; }
    );
    const int POSITION_LENGTH = 2;      // The input position string length always two, for example, a0,b9, c3....
    int rowPosition;                    // row value
    int colPosition;                    // column value
    string attackPosition;              // input string for attack
    bool isSuccessful;                  // Successfully attack or not
    int trackWin;
    cout << "~~ Now your turn to attack the computer ship position ~~" << endl;
    while (true) {
        while (true) {                                      // Take a infinite loop for satisfying the valid input for attack position
            cout << "Choose a position for attacking the computer "
                "ships (example: a0, a1...): " << endl;
            getline(cin, attackPosition);                     // Get the ship position
            if (attackPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : attackPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((attackPosition[0] >= minElement->second && attackPosition[0] <= maxElement->second)
                    && (attackPosition[1] >= '0'+ minElement->first && attackPosition[1] <= '0'+ maxElement->first)) { // check for valid input and convert number to character
                    rowPosition = letterToRowNumber(attackPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
                    colPosition = attackPosition[1] - '0';                   // Convert the column position character to integer  
                    isSuccessful = checkSuccessful(battleShipComputer, 'p',
                        rowPosition, colPosition); // Check it is successfully hit or not
                    if (isSuccessful) {                         // If successfully hit then player will get another change for attack
                        trackWin = displayShipStatus(battleShipPlayer,
                            battleShipComputer);
                        gameHead();                   // Draw the game head
                        showPlayZone();   // Draw the play zone
                        cout << " You attack successfully !!! " << endl;
                        attackPosition.clear();
                        if (trackWin == 0) break; // Player won the game; do not need continue
                        continue;
                    }
                    else {
                        trackWin = displayShipStatus(battleShipPlayer,
                            battleShipComputer);
                        gameHead();                   // Draw the game head
                        showPlayZone();   // Draw the play zone
                        cout << "You miss the hit. Now computer's turn! \n";
                        break;                                  // End the player attack and computer will attack now to player battle ship
                    }
                }
                else {
                    cout << "----Enter a valid aircraft position without a "
                        "space (example: a0, a1...)----" << endl;   // ask for valid input again
                    attackPosition.clear();
                    continue;
                }
            }
            else {
                cout << "----Enter a valid aircraft position without a space"
                    " (example: a0, a1...)----" << endl;   // ask for valid input again
                attackPosition.clear();
                continue;
            }
        }
        if (trackWin == 0)  // The player won
        {
            cout << "Congratulation!!! ~~~" << playerName << "~~~ "
                "You won this game!!!" << endl;
            break;
        }
        while (true) {   // Take a infinite loop for satisfying the valid input for attack position
            cout << "Computer is now attacking your ships...: " << endl;
            rowPosition = rand() % 10;                        // randomly select a row position from 0-9 
            colPosition = rand() % 10;                        // randomly select a column position from 0-9 
            isSuccessful = checkSuccessful(battleShipPlayer, 'c',
                rowPosition, colPosition); // Check if it is successfully hit or not 
            if (isSuccessful) {                         // If successfully hit then player will get another change for attack
                trackWin = displayShipStatus(battleShipPlayer, battleShipComputer);
                gameHead();                   // Draw the game head
                showPlayZone();   // Draw the play zone
                cout << "Computer attack the position: " << yCoord[rowPosition]
                    << colPosition << endl;
                cout << "Computer attack your ship successfully !!! " << endl;
                if (trackWin == 1) break; // Computer won the game; do not need continue
                continue;
            }
            else {
                trackWin = displayShipStatus(battleShipPlayer, battleShipComputer);
                gameHead();                   // Draw the game head
                showPlayZone();   // Draw the play zone
                cout << "Computer attack the position: " << yCoord[rowPosition]
                    << colPosition << endl;
                cout << "Computer miss the hit. Now your turn! " << endl;
                break;                                  // End the computer attack and player will attack now to player battle ship
            }
        }
        if (trackWin == 1)  // The computer won
        {
            cout << "Congratulation!!! ~~~ Computer ~~~ won this game!!!\n";
            break;
        }

    }
}
//*****************************************************************
//Definition of function checkSuccessful                          *
//This function check the attack is successful or not and         *
//Update the ship position structure. Return boolean status       *                              *
//*****************************************************************
bool BShipSetUp::checkSuccessful(BShipSetUp& bShipInfo, char sourceData,
    int row, int col) {
    const int AIRCRAFT_LENGTH = 5;                      // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;                    // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;                     // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;                      // Unit length of the corvette
    bool isFound = false;
    for (int i = 0; i < AIRCRAFT_LENGTH; i++) {         // Check the air craft position
        if (bShipInfo.aircraft[i][0] != -1)         // If the position not hit yet
        {
            if (bShipInfo.aircraft[i][0] == row && bShipInfo.aircraft[i][1] == col) //hit successful
            {
                bShipInfo.aircraft[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    // Iterate to the correct row
                    auto rowIt = playerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)
                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully
                }
                else
                {
                    // Iterate to the correct row
                    auto rowIt = computerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)

                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully

                    //computerMatrix[row][col] = '@';        // Set the matrix position '@' if hit successfully
                }
                isFound = true;                     // The value is found already
                return isFound;
            }//end if 
        } //end if 
    } //end for loop

    for (int i = 0; i < BATTLESHIP_LENGTH; i++)     // Check the battle ship position
    {
        if (bShipInfo.battleship[i][0] != -1)   // If the position not hit yet
        {
            if (bShipInfo.battleship[i][0] == row &&
                bShipInfo.battleship[i][1] == col) //hit successful
            {
                bShipInfo.battleship[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    // Iterate to the correct row
                    auto rowIt = playerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)
                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully
                    //playerMatrix[row][col] = '@';        // Set the matrix position '@' if hit successfully
                }
                else
                {
                    // Iterate to the correct row
                    auto rowIt = computerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)

                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully

                    //computerMatrix[row][col] = '@';        // Set the matrix position '@' if hit successfully
                }
                isFound = true;                     // The value is found already
                return isFound;
            }//end if 
        }//end if 
    }//end for loop

    for (int i = 0; i < DESTROYER_LENGTH; i++)     // Check the Destroyer position
    {
        if (bShipInfo.destroyer[i][0] != -1)   // If position not hit yet 
        {
            if (bShipInfo.destroyer[i][0] == row &&
                bShipInfo.destroyer[i][1] == col) //hit successful
            {
                bShipInfo.destroyer[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    // Iterate to the correct row
                    auto rowIt = playerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)
                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully
                    //playerMatrix[row][col] = '@';        // Set the matrix position '@' if hit successfully
                }
                else
                {
                    // Iterate to the correct row
                    auto rowIt = computerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)

                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully

                    //computerMatrix[row][col] = '@';        // Set the matrix position '@' if hit successfully
                }
                isFound = true;                     // The value is found already
                return isFound;
            }//end if 
        }//end if 
    }//end for loop

    for (int i = 0; i < CORVETTE_LENGTH; i++)     // Check the corvette position
    {
        if (bShipInfo.corvette[i][0] != -1)   // If position not hit yet 
        {
            if (bShipInfo.corvette[i][0] == row &&
                bShipInfo.corvette[i][1] == col) //hit successful
            {
                bShipInfo.corvette[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                { // Iterate to the correct row
                    auto rowIt = playerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)
                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully
                    //playerMatrix[row][col] = '@'; // Set the matrix position '@' if hit successfully
                }
                else
                {
                    // Iterate to the correct row
                    auto rowIt = computerMatrix.begin();
                    advance(rowIt, row);  // Move iterator to the 2nd row (1-based)

                    // Iterate to the correct column within the row
                    auto colIt = rowIt->begin();
                    advance(colIt, col);  // Move iterator to the 3rd column (1-based)
                    *colIt = '@';       // Set the matrix position '@' if hit successfully
                    //computerMatrix[row][col] = '@';  // Set the matrix position '@' if hit successfully
                }
                isFound = true;  // The value is found already
                return isFound;
            }//end if 
        }//end if 
    }//end for loop
    if (sourceData == 'c')
    {
        // Iterate to the correct row
        auto rowIt = playerMatrix.begin();
        advance(rowIt, row);  // Move iterator to the 2nd row (1-based)
        // Iterate to the correct column within the row
        auto colIt = rowIt->begin();
        advance(colIt, col);  // Move iterator to the 3rd column (1-based)
        *colIt = 'o';       // Set the matrix position '@' if hit successfully
        //playerMatrix[row][col] = 'o';  // Set the matrix position 'o' if hit unsuccessful
    }
    else
    {
        // Iterate to the correct row
        auto rowIt = computerMatrix.begin();
        advance(rowIt, row);  // Move iterator to the 2nd row (1-based)

        // Iterate to the correct column within the row
        auto colIt = rowIt->begin();
        advance(colIt, col);  // Move iterator to the 3rd column (1-based)
        *colIt = 'o';       // Set the matrix position 'o' if hit unsuccessful
        //computerMatrix[row][col] = 'o'; // Set the matrix position '@' if hit successfully
    }
    return isFound;
}
//*****************************************************************
//Definition of function displayShipStatus                    
//Check the ship status using structure reference
//Draw the ship status     
//Return the integer indicating the game is over or not
//*****************************************************************
int BShipSetUp::displayShipStatus(BShipSetUp player, BShipSetUp computer)
{
    system("cls");
    const int AIRCRAFT_LENGTH = 5;         // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;       // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;        // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;         // Unit length of the corvette
    int airCarftComputer = 0;              // Counter for air craft
    int battelShipComputer = 0;            // Counter for battleship
    int destroyerComputer = 0;             // Counter for destroyer
    int corvetteComputer = 0;              // Counter for corvette
    int airCarftPlayer = 0;                // Counter for air craft
    int battelShipPlayer = 0;              // Counter for battleship
    int destroyerPlayer = 0;               // Counter for destroyer
    int corvettePlayer = 0;                // Counter for corvette

    bool isFound = false;
    //Count aircraft
    for (int i = 0; i < AIRCRAFT_LENGTH; i++) // Check the air craft position
    {
        if (computer.aircraft[i][0] != -1)   // If the position not hit yet
        {
            airCarftComputer += 1;           // Count the computer air craft 
        }
        if (player.aircraft[i][0] != -1)
        {
            airCarftPlayer += 1;            // Count the player air craft
        }
    }
    //Count battleship
    for (int i = 0; i < BATTLESHIP_LENGTH; i++) // Check the battle ship position
    {
        if (computer.battleship[i][0] != -1)    // If the position not hit yet
        {
            battelShipComputer += 1;           // Count the computer battle ship 
        }
        if (player.battleship[i][0] != -1)
        {
            battelShipPlayer += 1;        // Count the player battle ship
        }
    }
    //Count destroyer
    for (int i = 0; i < DESTROYER_LENGTH; i++)  // Check the Destroyer position
    {
        if (computer.destroyer[i][0] != -1)     // If the position not hit yet
        {
            destroyerComputer += 1;         // Count the computer destroyer ship 
        }
        if (player.destroyer[i][0] != -1)
        {
            destroyerPlayer += 1;            // Count the player destroyer ship
        }
    }
    //Count corvette
    for (int i = 0; i < CORVETTE_LENGTH; i++)     // Check the corvette position
    {
        if (computer.corvette[i][0] != -1)        // If the position not hit yet
        {
            corvetteComputer += 1;           // Count the computer corvette ship 
        }
        if (player.corvette[i][0] != -1)
        {
            corvettePlayer += 1;           // Count the player corvette ship
        }
    }
    cout << ".........................................................."
        "..........\n";
    cout << " -  Computer Ships Status                 Your Ship Status-\n";   //Display the ship status
    cout << "............................................................."
        ".......\n";
    cout << "----Aircraft: " << airCarftComputer << " units                 "
        "| ----Aircraft: " << airCarftPlayer << " units" << endl;
    cout << "----Battleship: " << battelShipComputer << " units              "
        " | ----Battleship: " << battelShipPlayer << " units" << endl;
    cout << "----Destroyer: " << destroyerComputer << " units               "
        " | ----Destroyer: " << destroyerPlayer << " units" << endl;
    cout << "----Corvette: " << corvetteComputer << " units                "
        " | ----Corvette: " << corvettePlayer << " units" << endl;
    cout << "..........................................................."
        "..........\n";
    // Check all computer ships were hit successfully
    if (airCarftComputer == 0 && battelShipComputer == 0 &&
        destroyerComputer == 0 && corvetteComputer == 0)
    {
        return 0;   // Computer loss and player win
    }
    // Check all player ships were hit successfully
    else if (airCarftPlayer == 0 && battelShipPlayer == 0 &&
        destroyerPlayer == 0 && corvettePlayer == 0)
    {
        return 1;   // player loss and computer win
    }
    else
    {
        return 2; // Continue play
    }
} //end of displayShipStatus function


