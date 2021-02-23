/***
    The program performs Gauss Jordan Method to find the inverse of matrix
    Limitations:
         1. If zero is encountered as diagonal matrix the program exits
         2. Swap has not been implemented , which could have been done to swap rows when all elements in a given column are not all zero
**/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//Gauss Jordan Inverse Matrix Method

/*********** Implementation *********/
int main(){
    cout.precision(3);
    int n;
    cout<<"Enter order of matrix:";
    cin>>n;
    double arr[n][n];
    double inv[n][n];

/********* input matrix ***************/
    for(int i=0 ;i<n ; i++){
        for(int j=0 ;j<n ;j++){
            cout<<"arr["<<i<<"]["<<j<<"] : ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
//setup the unity matrix
    for(int i=0 ;i<n ; i++){
        for(int j=0 ;j<n ;j++){
            if(i == j)
                inv[i][j] = 1;
            else
                inv[i][j] = 0;
        }
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
                for(int k=0;k<n;k++){
                    arr[i][k]= arr[i][k]-(t*arr[j][k]);
                    inv[i][k]= inv[i][k]-(t*inv[j][k]);
                }
            }
        }
    }

/****************** display ***********************/
    cout<<"The inverse of given matrix is:"<<endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<n; j++){
            inv[i][j]= inv[i][j]/arr[i][i];
            cout<<inv[i][j]<<"  ";
        }
        cout<<endl;
    }


return 0;
}

