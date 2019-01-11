#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float user;
    cout<<"enter the interpolation point:"; cin>>user;

    int n;
    cout<<"enter no of data set:"; cin>>n;

    float x[40], y[40];
    cout<<"enter set of x values:";
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
    }
    cout<<"enter set of y values:";
    for(int i=0; i<n; i++)
    {
        cin>>y[i];
    }

    //main algo part
    float product,  sum=0;
    for(int i=0; i<n ; i++)
    {
        product=1;   //to reset product value for next ith operation
        for(int j=0; j<n; j++)
        {
            if(j!=i)
            {
                product*=((user-x[j])/(x[i]-x[j]));
            }
        }
        product*=y[i];   //OR do as product=y[i] in line 29
        sum+=product;
    }
    cout<<"soln="<<sum;
}
