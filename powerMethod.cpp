//Power method for dominant Eigen value and Eigen vector

#include<iostream>
using namespace std;

double abs(double x){
    return(x<0?(-x):x);
}

void control(int n){
    double a[n][n], EigenVector[n], EigenValue, tolerance;

/**************************** INPUT ***************************/

    for(int i=0; i<n; i++){
        for(int j=0; j<n ; j++){
            cout<<"a["<<i<<"]["<<j<<"]:";
            cin>>a[i][j];
        }
        EigenVector[i]= 1;
        cout<<endl;
    }

    cout<<"Enter tolerance:";
    cin>>tolerance;

//variables declaration

    int iterate=0;
    double maxError=0;
    double temp[n];

    do{
/****************** MULTIPLY MATRIX TO FIND EIGEN VECTOR *********************/

        for(int i=0; i<n; i++){
            temp[i] = EigenVector[i];
            EigenVector[i] = 0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                EigenVector[i] += temp[j]*a[i][j];
            }
        }
/******************** FIND EIGEN VALUE **************************/

        EigenValue = EigenVector[0];
        for(int i=1 ; i<n ; i++){
            if(abs(EigenVector[i])>abs(EigenValue))
                EigenValue = EigenVector[i];
        }
//divide the Eigen vector by the eigen value
        for(int i =0; i<n ; i++)
            EigenVector[i]= EigenVector[i]/EigenValue;

/****************** DETERMINE MAX-ERROR ************************/

        cout<<endl<<"Iteration "<<iterate+1<<":"<<endl<<"Eigen Vector :";
        for(int i=0; i<n; i++){
            if((maxError < abs(temp[i] - EigenVector[i]) )|| i==0)
                maxError = abs(temp[i] - EigenVector[i]);
            cout<<endl<<" x"<<i+1<<" :"<<EigenVector[i]<<" ";
        }
        cout<<endl<<"Eigen value for iteration "<<iterate+1<<" is: "<<EigenValue<<endl;
        iterate++;
    }while(maxError > tolerance);

/******************** FINAL DISPLAY ******************************/

    cout<<endl<<"The final solution is";
    cout<<"\nThe eigen value is: "<<EigenValue;
    cout<<"\nThe eigen vector is: ";
    for(int i=0;i<n;i++){
        cout<<"\nX"<<i+1<<" = "<<EigenVector[i];
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter order of matrix:";
    cin>>n;
    control(n);
return 0;
}
