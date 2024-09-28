/* 
 * File:   RowAray.h
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:17 PM
 * Purpose: RowAray class Specification
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include "AbsRow.h"

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};

#endif /* ROWARAY_H */

