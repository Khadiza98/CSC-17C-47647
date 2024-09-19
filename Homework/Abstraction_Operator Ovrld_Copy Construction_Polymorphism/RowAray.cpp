/* 
 * File:   RowAray.cpp
 * Author: Khadiza Akter
 * Created on September 14, 2024, 6:17 PM
 * Purpose: RowAray class implementation
 */

#include "RowAray.h"

int RowAray::mrkRand(int seed){
    //Xn+1 = (aXn + c) mod m
    //where X is the sequence of pseudo-random values
    //m, 0 < m  - modulus 
    //a, 0 < a < m  - multiplier
    //c, 0 ≤ c < m  - increment
    //x0, 0 ≤ x0 < m  - the seed or start value
    unsigned int a=31051;      //Short Prime
    unsigned int c=997;        //Another Prime
    unsigned int shrt=1<<15-1; //Range of positive signed short
    unsigned int m=1<<31-1;    //Range of positive signed int
    static int Xn=30937;       //Short Prime
    static int cnt=0;          //Initialize the seed
    if(cnt==0&&seed<=shrt)Xn=seed;
    cnt++;
    Xn=(a*Xn+c)%m;
    return Xn;
}

RowAray::RowAray(unsigned int n){
    size=n;
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

RowAray::~RowAray(){
    delete []rowData;
}

void RowAray::setData(int row,int val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}


