//program to demonstrate the secant method considering the possibility of f(a)=f(b)
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

inline float f(float x)
{
    return x*x*x-4*x-9;
}

int main()
{
    float a,b,c, dum1, dum2;
int counter=0;

    do
    {
        cout<<"enter initial guesses a and b:";
        cin>>a>>b;
    }
    while(f(a)==f(b));
    cout<<"S.N"<<setw(17)<<"a"<<setw(24)<<"b"<<setw(33)<<"c=(a*f(b)-b*f(a))/(f(b)-f(a))"<<setw(40)<<"f(c)"<<endl;
    while(1)
    {
        dum1=a;
        dum2=b;
        counter++;


        c=(a*f(b)-b*f(a))/(f(b)-f(a));



        a=b;
        b=c;


        cout<<counter<<setw(17)<<dum1<<setw(24)<<dum2<<setw(33)<<c<<setw(40)<<f(c)<<endl;
        if(fabs(f(c))<0.0001)
            break;

    }
     cout<<"soln and no of iteration="<<c<<" "<<counter;
}
