#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


float f(float x)
{
    return x*x*x-4*x-9;
}

int main()
{
    float a,b,c, dum1, dum2;
    int loop=0;
    while(1)
    {
        cout<<"Enter a and b:";
        cin>>a>>b;
        if(f(a)*f(b)<0)
            break;

    }
    cout<<"S.N"<<setw(17)<<"a"<<setw(24)<<"b"<<setw(33)<<"c=(a+b)/2"<<setw(40)<<"f(c)"<<endl;
    while(1)
    {
        dum1=a;
        dum2=b;
        loop++;
        c=(a+b)/2;
        if(f(b)*f(c)>0)
            b=c;

        else
            a=c;

         cout<<loop<<setw(17)<<dum1<<setw(24)<<dum2<<setw(33)<<c<<setw(40)<<f(c)<<endl;
        if(fabs(f(c))<0.0001)
         break;
    }
    cout<<"the solution="<<c;

}



