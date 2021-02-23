//Gauss-Seidal method

#include<iostream>
#include<iomanip>
using namespace std;

double abs(double a){
    if (a>=0)
        return a;
    else
        return -1*a;
}

void control(){
    int n;
    cout<<"Enter number of unknowns: ";cin>>n;
    cout<<"Diagonal dominant equations prefer"<<endl;
    double a[n][n+1],e;
/************** INPUT *************/
    for(int i=0;i<n;i++){
        cout<<"Enter coefficients of the "<<i+1<<" equation:"<<endl;
        for(int j=0;j<n+1;j++){
            cout<<"a["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
        cout<<endl;
    }
/*************** Initial guess values ****************/
    double x[n];
    cout<<"Input initial guess values, except the first term :"<<endl;
    for(int i=1;i<n;i++){
        cout<<"Element "<<i+1<<": ";
        cin>>x[i];
    }
    int k=0;        //iteration variable
    double z,error,test=0,MaxError=0;
    char choice;

    cout<<endl<<"Enter accuracy:";cin>>e;

//set up parameter for display
    cout<<"k";
    for(int i=0;i<n;i++)
        cout<<setw(10)<<"x"<<i;
    cout<<setw(15)<<"max error";


/********************** LOOP START ***************************/
    do{
/**************************** EXIT CONDITIONS ***************************************/
//besides first loop
        if(k>0){
            test -= MaxError;
            if(test<0){
                cout<<endl<<endl<<"The solution is diverging"<<endl<<"Do you want to continue(Y/N):";
                cin>>choice;
                if(choice == 'N' || choice == 'n')
                    break;
            }
        }
//if 50 iterations reached
        if(k >50){
            cout<<"Divergent solution, cannot be computed"<<endl;
            exit(EXIT_FAILURE);
        }
/************** iteration formula ****************/
        for(int i=0; i<n ;i++){
            error = x[i];
            z=0;
            for(int j=0; j<n ;j++){
                if(j != i)
                    z += a[i][j]*x[j];
            }
            x[i]=(a[i][n] - z)/a[i][i];

            if(abs(error-x[i]) > MaxError || i == 0)
                MaxError = abs( error - x[i]);
        }

/********** Display **************/
        cout<<endl<<k;
        for(int i=0;i<n;i++)
            cout<<" | "<<setw(9)<<x[i];
        cout<<" | "<<setw(12)<<MaxError;
        k++;
        test = MaxError;

    }while(MaxError > e);

/******************** LOOP END ****************************/

/************ FINAL OUTPUT ************/
    cout<<endl<<endl<<"The final solution is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"x"<<i<<"= "<<x[i]<<endl;
    }

}

int main(){
    control();
    return 0;
}
