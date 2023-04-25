#include "fraction_calculator.h"
#include "fraction.h"
using namespace std;

fraction_calculator::fraction_calculator(){}

void fraction_calculator::startcalculator(){
    cout<<"-------------welcome to calculator-------------"<<endl;
    while(true){
    fraction f1,f2;

    int x;

        cout<<endl<<"1.Adding\n"<<
        "2.subtracting"<<endl
        <<"3.multiplication"<<endl
        <<"4.dividing"<<endl<<"5.reduce"<<endl
        <<"6.exit"<<endl
        <<"Please enter your choice:";
        cin>>x;


        if(x==1){
             cout<<"please enter numerator then denominator separate by space"<<endl;
             cout<<"please enter your first fraction:"<<endl;
             cin>>f1;
             cout<<"please enter your second fraction:"<<endl;
             cin>>f2;
             fraction f3(f1+f2);
             cout<<"f1+f2="<<f3<<endl;
        }
        else if(x==2){
             cout<<"please enter numerator then denominator separate by space"<<endl;
             cout<<"please enter your first fraction:"<<endl;
             cin>>f1;
             cout<<"please enter your second fraction:"<<endl;
             cin>>f2;
             fraction f3(f1-f2);
             cout<<"f1-f2="<<f3<<endl;
        }
        else if(x==3){
             cout<<"please enter numerator then denominator separate by space"<<endl;
             cout<<"please enter your first fraction:"<<endl;
             cin>>f1;
             cout<<"please enter your second fraction:"<<endl;
             cin>>f2;
             fraction f3(f1*f2);
             cout<<"f1*f2="<<f3<<endl;
        }
        else if(x==4){
             cout<<"please enter numerator then denominator separate by space"<<endl;
             cout<<"please enter your first fraction:"<<endl;
             cin>>f1;
             cout<<"please enter your second fraction:"<<endl;
             cin>>f2;
             fraction f3(f1+f2);
             cout<<"f1/f2="<<f3<<endl;
        }
        else if(x==5){
            cout<<"please enter numerator then denominator separate by space"<<endl;
            cout<<"Enter fraction you want to reduce:";
            fraction f1;
            cin>>f1;
            f1.reduce();

        }

        else{
            cout<<"---------thanks for your time----------"<<endl;
            break;
        }
        }}


