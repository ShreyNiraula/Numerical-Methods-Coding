#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of variable:";
    cin >> n;

float A[2*n][2*n], temp;

//input system
    cout << "enter coeff of eqn:" << endl;

    for(int i = 0; i < n ; i++)
        for(int j = 0; j < (n+1) ; j++)  //n+1 for augmented constant
           cin >> A[i][j];


    //for addting unit mat at the end
    for(int i = 0; i < n ; i++)
    {
        for(int j = n; j < 2*n ; j++)
        {
            if((i+n) == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }


    //column action
    for(int j = 0; j < n ; j++)
    {
        //row acion
            for(int i = 0; i < n ;i++)
            {
                if(i != j)   //making other element other than diagonal as zero
                {
                    temp = A[i][j]/A[j][j];
                    for(int k = 0; k < (2*n) ; k++)   //till 2nth element
                    {
                        A[i][k] = A[i][k] - temp*A[j][k];
                    }
                }
                else    //making diagonal element 1
                {
                     temp = A[i][j];   //a11 or a22 or a33 ...value
                     for(int k = 0; k < (2*n) ; k++)
                     {
                        A[i][k] = A[i][k]/temp;
                     }
                }
            }
    }

    cout << "Inverse mat is:" << endl;
    for(int i = 0; i < n ; i++)
    {
        for(int j = n; j < (2*n); j++)
        {
            cout << A[i][j] << "  ";

        }
        cout << endl;
    }


}


