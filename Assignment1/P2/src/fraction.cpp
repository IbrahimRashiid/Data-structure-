#include "fraction.h"
#include <iostream>
using namespace std;

fraction::fraction()
{
   num=0;
   den=1;
}
fraction::fraction(int x,int y){
    num=x;
    den=y;
    this->lowestfraction();
}
fraction::fraction(const fraction &f){
    num=f.num;
    den=f.den;
    this->lowestfraction();
}

int fraction::findgcd(int a, int b) {
      if (b == 0)
       return a;
      return findgcd(b, a % b);
}

void fraction::lowestfraction(){
       int gcd = findgcd(num,den);
      num/=gcd;
      den/=gcd;

}
void fraction::reduce(){
       int gcd = findgcd(num,den);
      num/=gcd;
      den/=gcd;
      cout<<num<<"/"<<den;

}
bool fraction::operator==(fraction obj){
    if(num==obj.num&&den==obj.den)
        return 1;
    return 0;
}
bool fraction::operator<=(fraction obj){
  if(( float )num/den<=( float )obj.num/obj.den)
    return 1 ;
  return 0;
}
bool fraction::operator>=(fraction obj){
    if(( float )num/den>=( float )obj.num/obj.den)
      return 1 ;
    return 0;
}
istream & operator>>(istream & in,fraction &obj){

    in>>obj.num;

    in>>obj.den;
    return in;

}
ostream & operator<<(ostream & out,fraction &obj){
    if(obj.den==0)
        out<<"invalid divide by zero"<<endl;
    else if(obj.num==0)
        out<<0<<endl;
    else if(obj.num==obj.den)
        out<<1<<endl;
    else
        out<<obj.num<<"/"<<obj.den;
    return out;
}
fraction fraction::operator+(fraction obj){
    fraction r;
    r.num=(num*obj.den)+(obj.num*den);
    r.den=den*obj.den;
    r.lowestfraction();
    return r;

}
fraction fraction::operator-(fraction obj){
    fraction r;
    r.num=(num*obj.den)-(obj.num*den);
    r.den=den*obj.den;
    r.lowestfraction();
    return r;

}
fraction fraction::operator*(fraction obj){
    fraction r;
    r.num=num*obj.num;
    r.den=den*obj.den;
    r.lowestfraction();
    return r;
}
fraction fraction::operator/(fraction obj){
    fraction r;
    r.num=num*obj.den;
    r.den=den*obj.num;
    r.lowestfraction();
    return r;

}
