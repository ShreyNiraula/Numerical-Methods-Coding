#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variable:";
    cin >> n;

float A[n][n+1], X[n], temp, sum;

//input system
    cout << "enter coeff of eqn:" << endl;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < (n+1) ; j++)
           cin >> A[i][j];

    //column action
    for(int j = 0; j < n ; j++)
    {
        //row acion
            for(int i = 0; i < n ;i++)
            {
                if(i > j)    //make element =0 where i>j
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
    X[n-1] = A[n-1][n]/A[n-1][n-1];   // finding z and storing at the last position of x matrix (n-1 as n=3 but x[3] means 4th element but soln has only three elements)

    //for back substitution
    for(int i = n-2 ;i >= 0; i--)
    {
        sum = 0;
        for(int j = i; j < n ; j++)
        {
            sum += A[i][j]*X[j];
        }
        X[i] = (A[i][n] - sum)/A[i][i];
    }

    cout << "Soln=";
    for(int i = 0; i < n ; i++)
    {
        cout << X[i] << ",";
    }
}
