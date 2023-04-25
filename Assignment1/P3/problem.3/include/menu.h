
#include <bits/stdc++.h>
#include "matrix.h"
using namespace std;
template<class T>
class Menu
{
    public:
        Menu(){}

        void printmenu(matrix<T>& ob){
        cout << "Welcome to  Matrix Calculator"<<endl;
        cout << "----------------------------------------"<<endl;
        matrix <T>ob2,ob3;
        int num;
        bool c=true;
        while(c)
        {
            cout << "1- Perform Matrix Addition"<<"\n2- Perform Matrix Subtraction."
                 <<"\n3- Perform Matrix Multiplication."<<"\n4- Matrix Transpose."
                 "\n5- Enter 0 to Exit."<<endl;
            cin >> num;
            switch(num)
            {
            case 0:
                c=false;
                break;
            case 1:

                cout << "Enter Your First Matrix dimensions then your data : ";
                cin >> ob;

                cout << "Enter Your Second Matrix dimensions then your data : ";
                cin>>ob2;
                if(ob.getrow()==ob2.getrow() && ob.getcol()==ob2.getcol()){
                    ob3 = ob + ob2;

                    cout <<"\nMatrix 1 + Matrix 2 = "<< ob3<<endl;
                }
                else    cout<<"\nRows and Columns are not equal\n";
                break;
            case 2:

                cout << "Enter Your First Matrix dimensions then your data: ";
                cin >> ob;
                cout << "Enter Your Second Matrix dimensions then your data : ";
                cin>>ob2;
                if(ob.getrow()==ob2.getrow() && ob.getcol()==ob2.getcol()){
                    ob3 = ob - ob2;
                    cout <<"\nMatrix 1 - Matrix 2 = "<< ob3;
                }
                else    cout<<"Rows and Columns are not equal\n";
                break;
            case 3:
                cout << "Enter Your First Matrix dimensions then your data : ";
                cin >> ob;
                cout << "Enter Your Second Matrix dimensions then your data: ";
                cin>>ob2;
                if(ob.getcol()==ob2.getrow()){
                    cout <<"\nMatrix 1 * Matrix 2 = "<< (ob*ob2);
                }
                else    cout<<"Rows and Columns are not equal\n";
                break;
            case 4:
                cout << "Enter Your Matrix dimensions then your data: ";
                cin >> ob;
                cout << "transposed Matrix : " << endl;
                cout << trans(ob) << endl << endl;
                break;
            default:
                continue;
            }
        }

        cout <<endl<< "Press any key to continue";

    }



};

