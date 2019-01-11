#include <iostream>
#include<cmath>
using namespace std;

float f(float x, float y)
{
    return y/(exp(x)+1);

}
int main()
{
    float x0, y0,x , k1,k2,k3,k4, k, h;
    cout<<"enter initial conditions x0, y0:"; cin>>x0>>y0;
    cout<<"enter step-size h:"; cin>>h;
    cout<<"enter the point to find:"; cin>>x;

    while(x0<=x)
    {
        k1=h*f(x0, y0);
        k2=h*f(x0+h/2, y0+k1/2);
        k3=h*f(x0+h/2, y0+k2/2);
        k4=h*f(x0+h, y0+k3);

        k=(k1+2*k2+2*k3+k4)/6;

        x0+=h;
        y0+=k;
        cout<<"at x="<<x0<<" y is:"<<y0<<endl;
    }
}
