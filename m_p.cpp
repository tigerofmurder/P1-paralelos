#include <bits/stdc++.h>
#include "second.h"
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix extract(Matrix &A,int i,int j,int i_f, int j_f){
    int m = i_f - i;
    int n = j_f - j;
    Matrix salida(m,vector<int>(n,0));
    int ii = 0;
    for (int a = i; a<i_f;a++){
        int jj = 0;
        for (int b = j; b<j_f;b++){
            salida[ii][jj] = A[a][b];
            jj++;
        }
        ii++;
    }
    return salida;
}

void In_part(Matrix &A,Matrix &B,int i,int j,int i_f,int j_f){
    int ii =0;
    for (int a = i;a<i_f;a++){
        int jj=0;
        for (int b =j;b<j_f;b++){
            A[a][b] = B[ii][jj];
            jj++;
        }
        ii++;
    }
}
Matrix operator + (const Matrix &A, const Matrix &B){
    int m = A.size();
    int n = A.front().size();
    int p = B.size();
    int q = B.front().size();
    Matrix salida(m,vector<int>(n,0));
    if (m!=p or n!=q)
        return salida;
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            salida[i][j] = A[i][j]+B[i][j];
    return salida;
}
Matrix Partition(Matrix &A,Matrix &B){
    int m = A.size();
    int n = A.front().size();
    int p = B.size();
    int q = B.front().size();
    Matrix salida(m,vector<int>(q,0));
    if(n != p)
        return salida;
    Matrix m_1_1 = extract(A,0,0,m-1,1)*extract(B,0,0,1,1)+extract(A,0,1,m-1,3)*extract(B,1,0,3,1)+extract(A,0,3,m-1,n)*extract(B,3,0,p,1);
    In_part(salida,m_1_1,0,0,m-1,1);
    Matrix m_1 = extract(A,m-1,0,m,1)*extract(B,0,0,1,1)+extract(A,m-1,1,m,3)*extract(B,1,0,3,1)+extract(A,m-1,3,m,n)*extract(B,3,0,p,1);
    In_part(salida,m_1,m-1,0,m,1);
    Matrix m_0_0 = extract(A,0,0,m-1,1)*extract(B,0,1,1,q)+extract(A,0,1,m-1,3)*extract(B,1,1,3,q)+extract(A,0,3,m-1,n)*extract(B,3,1,p,q);
    In_part(salida,m_0_0,0,1,m-1,q);
    Matrix m_q = extract(A,m-1,0,m,1)*extract(B,0,1,1,q)+extract(A,m-1,1,m,3)*extract(B,1,1,3,q)+extract(A,m-1,3,m,n)*extract(B,3,1,p,q);
    In_part(salida,m_q,m-1,1,m,q);
    //cout<<salida<<endl;
    return salida;
}

int main(){
    int n = 1000;
    int m = 1000;
    int p = 1000;
    Matrix A(m,vector<int>(n,0));
    Matrix B(n,vector<int>(p,0));
    Llenar(A);
    Llenar(B);
    //cout<<A<<endl<<B<<endl<<A*B;
    Partition(A,B);
}

