#include<iostream>
#include<cmath>
using namespace std;

float diffFunValue(float x){
    //return (3.1415 - 2*sin(x));
    //return(4*x*x*x - 4.298 *x + 66);
    return(3*cos(x)+ 5*sin(x)+ exp(x));
}

float funValue(float x){
    //return (3.1415* x + 2* cos(x)-1);
    //return (x*x*x*x - 2.149* x*x + 66*x -20);
    return (3* sin(x)-5*cos(x)+ exp(x)-22.4);
}

int main(){
    float x0,error,g,f,g1,f1,x1,n,count =1;
    cout<<"Enter initial guess:";
    cin>>x0;
    cout<<"Enter tolerable error:";
    cin>>error;
    cout<<"Enter maximum iteration:";
    cin>>n;
    try{
        do{
            g=diffFunValue(x0);
            f=funValue(x0);
            if(g==0)
                throw 0;
            x1=x0-f/g;
            x0=x1;
            count++;
            if(count>n)
                throw 1;
            f1=funValue(x1);
        }while(abs(f1)>error);
        cout<<"Root is:"<<x1;
    }
    catch(int num){
        cout<<(num==0)?"Exception: Derivative is zero":"Exception: No convergent";
    }
}
