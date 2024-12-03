/*
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on November 17, 2024, 10:24 PM
 * Purpose: Implementation file for BattleShip class
 */
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include "BattleShip.h" //needed for BattleShip class

using namespace std;

//****************************************************************
// Definition of BattleShip. This constructor dynamically fills the 
// matrix grid (10x10) with '*' character for computer or player matrix.
//****************************************************************
BattleShip::BattleShip() {
    // Initialize the list with 10 rows and 10 columns, filled with '*'
    listMatrix = list<list<char>>(ROWS, list<char>(COLS, '*'));
}