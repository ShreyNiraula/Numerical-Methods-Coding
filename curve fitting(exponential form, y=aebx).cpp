// curve fitting method for exponential format (y=aebx)

#include<iostream>
#include<cmath>
using namespace std;

int main()
{

    int n ;
    cout<<"enter n:"; cin>>n;


    float x[n],y[n], Ex=0, Exy=0, Ey=0, Ex2=0, det, det1, det2;

    cout<<"enter x(s)"<<endl;
    for(int i=0; i<n; i++)
        cin>>x[i];
    cout<<"enter y(s)"<<endl;
    for(int i=0; i<n; i++)
        cin>>y[i];



    for(int i=0; i<n; i++)
    {
        Ex+=x[i];
        Ey+=log(y[i]);
        Exy+=x[i]*log(y[i]);
        Ex2+=x[i]*x[i];
    }

    //solving the unknown a and b by cramers rule

    det=Ex2*n-Ex*Ex;
    det1=Ex2*Ey-Ex*Exy;
    det2=Exy*n-Ex*Ey;


    cout<<"a="<<(exp(det1/det))<<endl;
    cout<<"b="<<(det2/det)<<endl;


}


