
#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;
template <class t>
class matrix{
private:
	t** info;
	int row, col;
public:


	matrix(){}

	matrix(int row, int col, t arr[]){
    this->row = row;
    this->col = col;
    info= new t*[row];

    for (int i = 0; i < row; i++)
        info[i] = new t[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            info[i][j] = arr[i][j];
	}


	matrix(int row, int col){
	        this->row = row;
    this->col = col;
    info = new t*[row];
    for (int i = 0; i < row; i++)
        info[i] = new t[col];
	}

	int getrow(){
	     return row;
	}
	int getcol(){
	    return col;
	}


	template<class m>
	friend istream& operator>> (istream& in, matrix<m>& mat){

	     cin >> mat.row >> mat.col;

    mat.info = new m*[mat.row];

    for (int i = 0; i < mat.row; i++)
        mat.info[i] = new m[mat.col];

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            in >> mat.info[i][j];

    return in;
	}

	template <class m>
	friend ostream& operator<< (ostream& out, const matrix<m>& mat){
	     for (int i = 0; i < mat.row; i++)
    {
        out << endl;
        for (int j = 0; j < mat.col; j++)
            out << mat.info[i][j] << "  ";
    }
    out << endl << endl;

    return out;
	}


	matrix<t> operator+(matrix<t> & mat2){
	     matrix<t> mat(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.info[i][j] = 0;

    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.info[i][j] = (info[i][j] + mat2.info[i][j]);
        }
    }
    return mat;
	}

	matrix<t> operator-(matrix<t> &mat2){
	    matrix<t> mat(row,col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.info[i][j] = 0;


    for (int i = 0; i < mat.row; i++)
    {
        for (int j = 0; j < mat.col; j++)
        {
            mat.info[i][j] = (info[i][j] - mat2.info[i][j]);
        }
    }
    return mat;
	}

	matrix<t> operator*(matrix<t> &mat2){

	 matrix<t> mat(row, col);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < mat2.col; j++)
            mat.info[i][j] = 0;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < mat2.col; j++){
            for (int k = 0; k <col; k++)
            {
                mat.info[i][j] += info[i][k] * mat2.info[k][j];
            }}}

    return mat;
	}



	template <class m>
	friend matrix<m>& trans(matrix<m>& mat){
	     matrix<m> mat1(mat.col, mat.row);

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat1.info[i][j] = mat.info[j][i];

    for (int i = 0; i < mat.row; i++)
        for (int j = 0; j < mat.col; j++)
            mat.info[i][j] = mat1.info[i][j];

    return mat;
	}

	virtual ~matrix(){}
};










