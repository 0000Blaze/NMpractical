/***
    The program performs Gauss Jordan Method to find the value of unknowns
    Limitations:
         1. If zero is encountered as diagonal matrix the program exits
         2. Swap has not been implemented , which could have been done to swap rows when all elements in a given column are not all zero
**/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//Gauss Jordan Method

/*********** Implementation *********/
int main(){
    int n;
    cout<<"Enter number of unknowns:";
    cin>>n;
    double arr[n][n+1];

/********* input matrix ***************/
    for(int i=0 ;i<n ; i++){
        cout<<"Enter coefficients of equation "<<i+1<<":"<<endl;
        for(int j=0 ;j<n+1 ;j++){
            cout<<"arr["<<i<<"]["<<j<<"] : ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
/************** Apply method  ************************/
     double t;
     for(int j=0;j<n;j++){

        if(arr[j][j] == 0){
            cout<<"Could not find solution"<<endl;
            exit(EXIT_FAILURE);
        }

        for(int i=0;i<n;i++){
            if(i != j){
                t= arr[i][j]/arr[j][j];
                for(int k=0;k<n+1;k++){
                    arr[i][k]= arr[i][k]-(t*arr[j][k]);
                }
            }
        }
    }
/****************** display ***********************/

    double b;
    cout<<"\nThe solution is: ";
    for(int i=0;i<n;i++){
        b = arr[i][n] / arr[i][i];
        cout<<"\nX"<<i+1<<" = "<<b;
    }
return 0;
}
