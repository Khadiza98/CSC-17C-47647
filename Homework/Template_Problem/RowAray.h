/* 
 * File:   RowAray.h
 * Created on September 19, 2024, 8:58 AM
 * Purpose: RowAray Template class specification.
 */

#ifndef ROWARAY_H
#define ROWARAY_H

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int mrkRand(int);
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template<class T>
int RowAray<T>::mrkRand(int seed){
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

template<class T>
RowAray<T>::RowAray(int n){
    size=n;
    rowData=new T[size];
    for(int i=0;i<size;i++){
        rowData[i]=mrkRand(size)%90+10;
    }
}

template<class T>
RowAray<T>::~RowAray(){
    delete []rowData;
}

template<class T>
void RowAray<T>::setData(int row,T val){
    if(row>=0&&row<size)rowData[row]=val;
    else rowData[row]=0;
}


#endif /* ROWARAY_H */

