#include <iostream>
#include<cmath>
using namespace std;

float f(float x)  //function to integrate within user provided limits
{
    //return 1+sin(x);
    return 1/(1+x*x);
}
int main()
{
    double a, b, h, y[100], x[100], iTrape,i18th, i38th,sTrape=0, s18th=0, s38th=0;
    int c;
    cout<<"enter limits a and b:";
    cin>>a>>b;
    cout<<"enter h:";
    cin>>h;

    c=(b-a)/h;
    cout<<c<<endl;

    double value=a;

    for(int i=0; i<=c ; i++, value=value+h)    // value=a as always not fixed as 0, and f(value) not f(a) as there will be fractional step increase
    {
        x[i]=value;
        y[i]=f(value);
    }


//    int j=0;
//    double value=a;
//    while(1)
//    {
//        x[j]=value;
//        y[j]=f(value);
//        j++;
//        value= value+h;
//        if(value>=b)
//            break;
//    }
    cout<<"the values of y are:"<<endl;
    for(int i=0; i<=c; i++)
    {
        cout<<x[i]<<"\t"<<y[i]<<endl;
    }

    sTrape=y[0]+y[c];
    s18th=y[0]+y[c];
    s38th=y[0]+y[c];

    //for trapezoidal method
    for(int i=1; i<c; i++)
    {
        sTrape+=2*y[i];

        if(i%2==0)
            s18th+=2*y[i];
        else
            s18th+=4*y[i];

        if(i%3==0)
            s38th+=2*y[i];
        else
            s38th+=3*y[i];
    }
    iTrape=0.5*h*sTrape;
    i18th=(h/3)*s18th;
    i38th=(3*h)/8*s38th;
    cout<<"ans by trapezoidal method="<<iTrape<<endl;
    cout<<"ans by simpson 1/8th method="<<i18th<<endl;
    cout<<"ans by simpson 3/8th method="<<i38th<<endl;
}
