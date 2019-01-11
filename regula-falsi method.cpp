#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

//function to return the given expression
inline float f(float x)
{
    return cos(x)-x*exp(x);
}

int main()
{
    float a,b,c, dum1, dum2;
    int loop=0, iteration=0;
    while(1)
    {
        cout<<"enter the brackets a and b:";
        cin>>a>>b;
        if(f(a)*f(b)<0)
            break;

    }
    cout<<"S.N"<<setw(17)<<"a"<<setw(24)<<"b"<<setw(33)<<"c=(a*f(b)-b*f(a))/(f(b)-f(a))"<<setw(40)<<"f(c)"<<endl;
    while(1)
    {
        iteration++;
        dum1=a;
        dum2=b;
        loop++;


        c=(a*f(b)-b*f(a))/(f(b)-f(a));



        if(f(b)*f(c)>0)
            b=c;

        else
            a=c;



        cout<<loop<<setw(17)<<dum1<<setw(24)<<dum2<<setw(33)<<c<<setw(40)<<f(c)<<endl;
        if(fabs(f(c))<0.0001)
         break;
    }
    cout<<"\nthe solution to the given expression is:"<<c;
    cout<<"\nthe functional value is: "<<f(c)<<endl;;
    cout<<"the no of iteration is:"<<iteration;
}



