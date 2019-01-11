#include <iostream>
#include <cmath>
using namespace std;

inline float slope(float x, float y)
{
    return y/(exp(x)+1);
}

int main()
{
    float h, x0, y0,x;

    cout<<"enter step-size h:"; cin>>h;
    cout<<"enter x:"; cin>>x;
    cout<<"enter initial x0:"; cin>>x0;
    cout<<"enter initial y0:"; cin>>y0;


    while(x0<=x)
    {
        y0+=h*slope(x0, y0);
        x0=x0+h;
       cout<<"x="<<x0<<"\t\t"<<"y="<<y0<<"\t\t"<<"slope="<<slope(x0,y0)<<endl;
    }
    cout<<"soln="<<y0;


}
