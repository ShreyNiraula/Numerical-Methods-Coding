#include <iostream>
#include<cmath>
using namespace std;


// NO FUNCTION


int main()
{
    double a, b, h, y[100], x[100], iTrape,i18th, i38th,sTrape=0, s18th=0, s38th=0;
    int c;
    cout<<"enter limits a and b:";
    cin>>a>>b;
    cout<<"enter h:";
    cin>>h;

    c=(b-a)/h;

    cout<<"enter y(s):";

    for(int i=0; i<=c; i++)   //<=c so as to include cth value also
        {
            cin>>y[i];
        }


    sTrape=y[0]+y[c];
//    s18th=y[0]+y[c];
//    s38th=y[0]+y[c];

    //for trapezoidal method
    for(int i=1; i<c; i++)          //limit excludes 1st and last element (i.e except y0 and yn)
    {
        sTrape+=2*y[i];

//        if(i%2==0)
//            s18th+=2*y[i];
//        else
//            s18th+=4*y[i];
//
//        if(i%3==0)
//            s38th+=2*y[i];
//        else
//            s38th+=3*y[i];
    }
    iTrape=0.5*h*sTrape;
//    i18th=(h/3)*s18th;
//    i38th=(3*h)/8*s38th;
    cout<<"ans ="<<iTrape<<endl;
//    cout<<"ans by simpson 1/8th method="<<i18th<<endl;
//    cout<<"ans by simpson 3/8th method="<<i38th<<endl;
}
