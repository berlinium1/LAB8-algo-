
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
    int B[4];
    int n=4; int m=4;
    int begin, end, eps;
    do{
        cout<<"Введіть нижню межу "; cin>>begin;
        cout<<endl<<"Введіть верхню межу "; cin>>end;
        }
    while(begin>end);
    cout<<endl<<"Введіть пробіл "; cin>>eps;
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
    float min=A[0][0];
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]<min){
                min=A[i][j];
            }
        }
        B[i]=min;
        cout<<" Мін. елемент у "<<i+1<<"-му стовпчику "<<min<<endl;
        min=A[i+1][0];
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
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
        cout<<setw(2*eps+3)<<A[j][i];
        cout<<endl;
    }
}
/*
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void input_m(float*, int, int, int, int);
void max_n_min(float[], int);
float array_sum(float[], float);
void array_change(float*, int, int, float);
void array_output(float*, int, int);
int num1=0,num2=0;
int main(){
    float sum=0;
    int begin, end;
    int eps;
    int a;
    do{
        cout<<"Розмір: ";
        cin>>a;
    }
    while (a<=0);
    float m[a];
    do{
        cout<<"Інтервал цілих значень чисел масиву: ";
        cin>>begin;
        cin>>end;
    }
    while (begin>end);
    do{
        cout<<"Розмір дробної частини дійсних чисел масиву: ";
        cin>>eps;
    }
    while (eps<0);
    cout<<endl;
    input_m(m, a, begin, end, eps);
    array_output(m, a, eps);
    max_n_min(m,a);
    array_sum(m, sum);
    sum=array_sum(m, sum);
    cout<<"Значення суми між ["<<num1<<"]\nта ["<<num2<<"] елементами "<<"дорівнює: "<<fixed<<setprecision(eps)<<sum<<endl<<endl;
    array_change(m, a, eps, sum);
    array_output(m, a, eps);
}
void max_n_min(float array[], int a){
    float max=array[0];
    float min=array[0];
    int numb_max=0;
    int numb_min=0;
    
        for(int j=0; j<a; j++){
            if(array[j]>max){
                max=array[j];
                numb_max=j;
            }
        }
        
        for(int j=0; j<a; j++){
            if(array[j]<min){
                min=array[j];
                numb_min=j;
            }
        }

    numb_max>numb_min? (num1=numb_min):(num1=numb_max);
    numb_max>numb_min? (num2=numb_max):(num2=numb_min);
    cout<<"\nМаксимум = "<<max<<". Порядковий номер: "<<numb_max<<endl;
    cout<<"Мінімум = "<<min<<". Порядковий номер: "<<numb_min<<endl<<endl;
}
void input_m(float *p, int a, int begin, int end, int eps){
    srand(time(NULL));
    for (int i=0; i<a; i++){
        *p=begin + rand()%(end-begin) + (float)( rand()%((int)(pow(10,eps)))/(pow(10,eps)));
        p++;
    }
}
float array_sum(float array[], float sum){
    for(int i=num1; i<=num2; i++){
        sum+=array[i];
    }

    return sum;
}
void array_change(float *p, int a, int eps, float sum){
    for(int i=0; i<a; i++){
        if(*p<0){
            *p=*p+sum;
        }
        p++;
    }
}

void array_output(float *p, int a, int eps){
    cout<<"Отриманий масив: \n";
    for(int i=0; i<a; i++){
        cout<<i<<"-й елемент масиву: "<<fixed<<setprecision(eps)<<*p<<endl;
        p++;
    }
}
*/



/*
#include <iostream>
#include <iomanip>
using namespace std;
void array_check(float[], int);
int main(){
    int begin, end;
    float eps;
    int p;
    int a;
    do{
        cout<<"Введіть бажану величину масиву: ";
        cin>>a;
    }
    while (a<0);
    cout<<endl;
    do{
        cout<<"Введіть інтервал цілих значень чисел масиву: ";
        cin>>begin;
        cin>>end;
    }
    while (begin>end);
    do{
        cout<<"Введіть розмір дробної частини дійсних чисел масива: ";
        cin>>eps;
    }
    while (eps<0);
    float m[a];
    srand(time(NULL));
    for (int i=0; i<a; i++){
        m[i]=begin + rand()%(end-begin) + (float)( rand()%((int)(pow(10,eps)))/(pow(10,eps)));
        cout<<i<<"-й) елемент массиву "<<fixed<<setprecision(eps)<<m[i]<<endl;
    }
    array_check(m,a);
}
void array_check(float array[], int a){
    float max=array[0];
    float min=array[0];
    int numb_max;
    int numb_min;
    int num1, num2;
    float sum=0;
    for(int i=0; i<a; i++){
        cout<<"For element "<<"["<<i<<"] "<<array[i]<<": "<<endl;
        
        for(int j=0; j<a; j++){
            if(array[j]>max){
                max=array[j];
                numb_max=j;
            }
        }
        
        for(int j=0; j<a; j++){
            if(array[j]<min){
                min=array[j];
                numb_min=j;
            }
        }
    }
    numb_max>numb_min? (num1=numb_min):(num1=numb_max);
    numb_max>numb_min? (num2=numb_max):(num2=numb_min);
    for(int i=num1; i<=num2; i++){
        cout<<"["<<i<<"] "<<array[i]<<": "<<endl;
        sum+=array[i];
    }
    cout<<"max = "<<max<<" - "<<numb_max<<endl;
    cout<<"min = "<<min<<" - "<<numb_min<<endl;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<"Sum = "<<sum;
    
}
*/
/*
void array3_formation(char[], char[]);
char maximum(char[]);
char minimum(char[]);

int main()
{
    char array1[a];
    char array2[a];
    for (int i=0; i<a; i++){
        array1[i]=2*i+23;
        printf("Елемент[%d] 1-го массиву: '%c' - код ASCII: %d\n", i, array1[i], int(array1[i]));
    }
    cout<<endl;
    for (int i=0; i<a; i++){
        array2[i]=49-2*i;
        printf("Елемент[%d] 2-го массиву: '%c' - код ASCII: %d\n", i, array2[i], int(array2[i]));
    }
    cout<<endl;
    
    array3_formation(array1, array2);
    cout<<endl<<endl;
    for (int i=0; i<n; i++){
        printf("Елемент[%d] 3-го массиву: '%c' - код ASCII: %d\n", i, array3[i], int(array3[i]));
    }
    cout<<endl;
    cout<<"Код максимального: "<<int(maximum(array3))<<endl;
    cout<<"Код мінімального: "<<int(minimum(array3))<<endl;
    int result = maximum(array3)-minimum(array3);
    printf("Різниця макс. і мін. елементів: %d(символ - %c)\n", result, result);
    return 0;
}

void array3_formation(char* numbers1, char* numbers2)
{
    for (int i=0; i<a; i++){
        for (int j=0; j<a;j++){
        if (int(numbers1[j])==int(numbers2[i])){
            array3[n]=numbers1[j];
            cout<<n<<" - "<<int(array3[n])<<endl;
            n++;
        }
        }
    }
}
char maximum(char* symbs){
   char max=symbs[0];
   for (int i=0; i<n; i++){
       if (symbs[i]>max){
           max=symbs[i];
       }
   }
    return max;
}

char minimum(char* array){
   char min=array[0];
   for (int i=0; i<n; i++){
       if (array[i]<min){
           min=array[i];
       }
   }
    return min;
}
*/
