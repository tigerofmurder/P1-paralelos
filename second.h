#include<bits/stdc++.h>
using namespace std;


void Llenar(vector<vector<int>> &A){
    srand(time(NULL));
    for (int i=0;i<int(A.size());i++){
        for (int j=0;j<int(A.front().size());j++){
            A[i][j]=rand()%5+1;
        }
    }
}

ostream& operator << (ostream &o,const vector<vector<int>> &p){
    o<<"Matrix: "<<endl;
    for(auto it=p.begin();it!=p.end();it++){
        for(auto et=it->begin();et!=it->end();et++){
            o<<*et<<" ";
        }
        o<<endl;
    }
    return o;
}

vector<vector<int>> operator *(const vector<vector<int>> &A, const vector<vector<int>> &B){
//vector<vector<int>> Multi(vector<vector<int>> &A, const vector<vector<int>> &B){
    int m = A.size();
    int n = A.front().size();
    int p = B.size();
    int q = B.front().size();
    vector<vector<int>> Salida(m,vector<int>(q,0));
    if(n != p){
        return Salida;
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<q;j++){
            double tmp = 0;
            for (int k=0;k<p;k++){
                tmp = tmp+(A[i][k]*B[k][j]);
            }
            Salida[i][j] = tmp;

        }
    }
    return Salida;
}
