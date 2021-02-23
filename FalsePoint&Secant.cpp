/*
Determine real root of non linear equation using
1. Secant method
2. False Position Method
*/

/*
    In this program as the question has asked it solves by both method which have different functions with respective names,
    in functional value calculation three functions have been hard coded , they may be used one at a time depending on the requirements
*/

#include<iostream>
#include<cmath>
using namespace std;

/***************************** Functional value calculation *******************************************/
double fxn(double var){
    double final;

    //x^3 - 3x^2 + 2x - 2.22
    //final = pow(var,3) - 3*pow(var,2) + 2*var - 2.22;

    //x*sin(x) + cos(x)
    //final = var*sin(var)+ cos(var);

    //x^2 + 4x + 5
    final= pow(var,2) + 4* var +5; //the roots are complex
return final;
}


/*********************** Secant Method ************************************/
void Secant(){
    double a, b, c, value;
    int i=1;
    const double accuracy = 0.000005;

    //step 1 , get initial values
    cout<<"Enter two initial guess values, such that first is less than second:";
    cin>>a>>b;

    //check if the given values have a root in their interval
    if(a > b || fxn(a)*fxn(b) > 0 ){
        cout<<"The initial values do not match the required conditions"<<endl<<"The roots of the equation may be complex"<<endl;
        exit(EXIT_FAILURE);
    }

    //iterate for solution
    do{
        //obtain next value
        c = ((a*fxn(b)) - (b*fxn(a)))/(fxn(b) - fxn(a));

        //obtain the functional value(i.e., accuracy) of next value
        value = fxn(c);

        cout<<i<<". iteration c= "<<c<<" and f(c)= "<<value<<endl;
        i++;
        //check the obtained functional value
        if(value == 0){
        cout<<"The exact solution is:"<<c<<endl;
        exit(EXIT_SUCCESS);
        }
        else {
            a=b;
            b=c;
        }
    }while(abs(value) >= accuracy);

    cout<<"The root with required 5 decimal point accuracy is: "<<c;
}

/*********************** False Point Method ************************************/
void FalsePoint(){
    double a, b, c, value;
    int i=1;
    const double accuracy = 0.000005;

    //step 1 , get initial values
    cout<<"Enter two initial guess values, such that first is less than second:"<<endl;
    cin>>a>>b;

    //check if the given values have a root in their interval
    if(a > b || fxn(a)*fxn(b) > 0 ){
        cout<<"The initial values do not match the required conditions"<<endl<<"The roots of the equation may be complex";
        exit(EXIT_FAILURE);
    }

    //iterate for solution
    do{
        //obtain next value
        c = ((a*fxn(b)) - (b*fxn(a)))/(fxn(b) - fxn(a));

        //obtain the functional value(i.e., accuracy) of next value
        value = fxn(c);

        cout<<"For "<<i<<" iteration c= "<<c<<" and f(c)= "<<value<<endl;
        i++;
        //check the obtained functional value
        if(value == 0){
        cout<<"The exact solution is:"<<c<<endl;
        exit(EXIT_SUCCESS);
        }
        else if(fxn(a)*fxn(c)< 0)
            b=c;
        else if(fxn(b)*fxn(c)< 0)
            a=c;
        else{
            cout<<"Computational error"<<endl;
            exit(EXIT_FAILURE);
        }
    }while(abs(value) >= accuracy);

    cout<<"The root with required 5 decimal point accuracy is: "<<c;
}

/******************************* Implementation *************************************/
int main(){

    //cout<<"Function x^3 - 3x^2 + 2x -2.22:"<<endl<<endl;
    //cout<<"Function x*sin(x) + cos(x):"<<endl<<endl;
    cout<<"Function x^2 + 4x + 5"<<endl<<endl;

    cout<<"From Secant Method:"<<endl;
    Secant();

    //cout<<endl<<endl<<"From False Point Method:"<<endl;
    //FalsePoint();

return 0;
}
