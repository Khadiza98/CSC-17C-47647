
/*
 * File: BattleShip.h
 * Author: Khadiza Akter
 * Created on December 01, 2024, 10:24 PM
 * Purpose: Specification file for BattleShip class
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <list> // Include list for STL list

class BattleShip {
private:
    std::list<std::list<char>> listMatrix; // Use std::list<std::list<char>>

public:
    const int ROWS = 10; // Constant rows for 10x10 matrix
    const int COLS = 10; // Constant columns for 10x10 matrix

    // Constructor fills the arrMatrix with default values
    BattleShip() {
        listMatrix = list<list<char>>(ROWS, list<char>(COLS, '*'));
    }

    // Accessor inline function, return filled matrix
    list<list<char>> getMatrixData() const {
        return listMatrix;
    }

};

#endif /* BATTLESHIP_H */

