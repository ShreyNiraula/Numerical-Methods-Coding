// curve fitting method for linear curve(st line of form y=ax+b)

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //define two sets of values in array for n sets of data
    int n ;
    cout<<"enter the value of n:"; cin>>n;

    //define two sets of values in array for n sets of data
    float x[50]; float y[50];
    cout<<"enter the values of x"<<endl;
    for(int i=0; i<n; i++)
        cin>>x[i];
    cout<<"enter the values of y"<<endl;
    for(int i=0; i<n; i++)
        cin>>y[i];

    //finding summation of x, y, xy, and x^2
    float Ex=0, Exy=0, Ey=0, Ex2=0;
    for(int i=0; i<n; i++)
    {
        Ex+=x[i];
        Ey+=y[i];
        Exy+=x[i]*y[i];
        Ex2+=x[i]*x[i];
    }

    //solving the unknown a and b by cramers rule
    float det, det1, det2, a, b;
    det=Ex*Ex-Ex2*n;
    det1=Ex*Ey-n*Exy;
    det2=Ex*Exy-Ex2*Ey;

    cout<<"a="<<(det1/det)<<endl;
    cout<<"b="<<(det2/det)<<endl;


}
//THEORY
//y=ax+b;
//aEx+nb=Ey
//aEx2+bEx=Exy
//
//in mat form
//Ex   n     a    =   Ey
//Ex2  Ex    b        Exy
