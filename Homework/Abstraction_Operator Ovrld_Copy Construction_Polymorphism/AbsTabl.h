/* 
 * File:   AbsTabl.h
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:20 PM
 * Purpose: AbsTabl class Specification 
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h"

class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual int getData(int,int)const = 0;
};


#endif /* ABSTABL_H */

