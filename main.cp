
//
//  main.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 11.11.2020.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef int type_matrix[10][10];
void matrix_forming(type_matrix, int, int, int, int);
void matrix_output(type_matrix, int, int, int);
void matrix_min(type_matrix, int[], int, int);
void array_sort(int[], int);
int main(){
    type_matrix A;
    int n=4; int m=4;
    int B[n];
    int begin, end, eps;
    do{
        cout<<"Нижня межа "; cin>>begin;
        cout<<endl<<"Верхня межа "; cin>>end;
        }
    while(begin>end);
    cout<<endl<<"Відступ "; cin>>eps;
    cout<<endl;
    matrix_forming(A, begin, end, n, m);
    matrix_output(A, n, m, eps);
    cout<<endl;
    matrix_min(A, B, n, m);
    cout<<endl;
    array_sort(B, n);
}
void array_sort(int B[], int n){
    int x, j;
    for (int i=1; i<=n-1; i++){
        x=B[i];
        j=i;
        while(j>0 && B[j-1]<x){
            B[j]=B[j-1];
            j=j-1;
        }
        B[j]=x;
    }
    for (int i=0; i<n; i++){
        cout<<i+1<<"-й елемент "<<B[i]<<endl;
    }
}
void matrix_min(type_matrix A, int B[], int n, int m){
    float min;
    for (int i=0; i<m; i++){
        min=A[0][i];
        for(int j=0; j<n; j++){
            if(A[j][i]<min){
                min=A[j][i];
            }
        }
        B[i]=min;
        cout<<" Мін. елемент у "<<i+1<<"-му стовпчику "<<min<<endl;
    }
}
void matrix_forming(type_matrix A, int begin, int end, int n, int m){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
        A[i][j]=begin + rand()%(end-begin+1);
    }
}
void matrix_output(type_matrix A, int n, int m, int eps){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++)
        cout<<setw(2*eps+3)<<A[i][j];
        cout<<endl;
    }
}
