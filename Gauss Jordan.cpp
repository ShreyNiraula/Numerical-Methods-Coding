  #include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variable:";   //asking for no of simultaneous eqn
    cin >> n;

float A[n][n+1], X[n], temp;

//input system
    cout << "enter coeff of eqn:" << endl;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < (n+1) ; j++)
           cin >> A[i][j];

    //column action
    for(int j = 0; j <n ; j++)
    {
        //row acion
            for(int i = 0; i < n ;i++)
            {
                if(i != j)
                {
                    temp = A[i][j]/A[j][j];   //neccessary otherwise previous value=0
                    // for shifting in column during substraction
                    for(int k = 0; k < (n+1) ; k++)
                    {
                        A[i][k] = A[i][k] - temp*A[j][k];
                    }
                }
            }
    }
     cout<<"matrix is:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<A[i][j]<<" \t ";
        }
        cout<<endl;
    }
    cout << "soln=";
    for(int i = 0; i< n; i++)
    {
        X[i] = A[i][n]/A[i][i];
        cout << X[i] << ",";
    }
}
