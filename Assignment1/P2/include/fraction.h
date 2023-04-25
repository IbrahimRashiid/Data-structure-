#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class fraction
{
    public:
        fraction();
        fraction (int x,int y);
        fraction (const fraction &obj);


        int findgcd(int a,int b);
        void lowestfraction();
        void reduce();


        bool operator <= (fraction obj);
        bool operator >= (fraction obj);
        bool operator == (fraction obj);



        friend istream & operator >> (istream & in , fraction & obj);
        friend ostream & operator << (ostream & out , fraction & obj);

        fraction operator + (fraction  obj);
        fraction operator - (fraction  obj);
        fraction operator * (fraction  obj);
        fraction operator / (fraction  obj);




    protected:
        int num,den;

};

#endif // FRACTION_H
