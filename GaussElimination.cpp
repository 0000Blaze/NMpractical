/***
    The program performs Gauss Elimination Method to find the value of unknowns
    Limitations:
         1. If zero is encountered as diagonal matrix the program exits
         2. Swap has not been implemented , which could have been done to swap rows when all elements in a given column are not all zero
**/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//Gauss Elimination Method

/*********** Implementation *********/
int main(){
    cout.precision(3);
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
     for(int j=0;j<n-1;j++){

        if(arr[j][j] == 0){
            cout<<"Could not find solution"<<endl;
            exit(EXIT_FAILURE);
        }

        for(int i=j+1;i<n;i++){
            t= arr[i][j]/arr[j][j];
            for(int k=0;k<n+1;k++){
                arr[i][k]= arr[i][k]-(t*arr[j][k]);
            }
        }
    }

/*************** Back substitution *************/
    double x[n];
    x[n]=arr[n][n+1]/arr[n][n];

    for(int i=n-1;i>=0;i--){
        x[i] = arr[i][n];

        for(int j=i+1;j<n;j++){
            x[i]=x[i]-arr[i][j]*x[j];
        }
        x[i] = x[i]/arr[i][i];
    }

    cout<<"The Solution:"<<endl;
/****************** display ***********************/
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
    }

return 0;
}
