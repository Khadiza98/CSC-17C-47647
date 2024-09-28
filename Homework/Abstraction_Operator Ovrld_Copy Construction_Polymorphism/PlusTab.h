/* 
 * File:   PlusTab.cpp
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:29 PM
 * Purpose: PlusTab class Specification
 */

#ifndef PLUSTAB_H
#define PLUSTAB_H

#include "Table.h"

class PlusTab:public Table{
    public:
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        PlusTab operator+(const PlusTab &);
};

#endif /* PLUSTAB_H */

