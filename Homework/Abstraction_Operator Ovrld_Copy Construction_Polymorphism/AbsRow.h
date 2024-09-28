/* 
 * File:   AbsRow.h
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:14 PM
 * Purpose: AbsRow class Specification
 */

#ifndef ABSROW_H
#define ABSROW_H

class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

#endif /* ABSROW_H */

