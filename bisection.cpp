// C++ program for implementation of Bisection Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    //return 66*x*x*x - 24*x*x + 2;
	//return x* sin (x) - 3*cos(x) ;
	return  11.121* exp(x) - log10(x);
}

// Prints root of func(x) with error of E
void bisection(double a, double b,double E)
{
    if (func(a) * func(b) >= 0){
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c;
    while ((b-a) >= E)
    {
        // Find middle point
        c = (a+b)/2;
        // Check if middle point is root
        if (func(c) == 0.0)
            break;
        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

int main()
{
   	double a, b, E;
	cout<< "Enter Tolerable Error:";
	cin>> E;
	cout<<"Enter initial interval values:";
	cin>> a >> b ;
	bisection(a, b, E);
    return 0;
}
