//program to demonstrate the NR method considering too many counter cases (output not obtainable)

#include <iostream>
#include <cmath>
using namespace std;

inline float f(float x)
{
    return x*x*x+1;
}
inline float fd(float x)
{
    return 3*x*x;
}
int main()
{
    float a,c;
    int counter=0;

    do
    {
        cout<<"enter initial guess:";
        cin>>a;
    }
    while(fabs(fd(a))<0.0001);   //checking if derivative is nearly zero

    while(1)
    {
        counter++;
        a-=(f(a)/fd(a));   // if c=a- (f(a)/fd(a)) then idk but wrong

        if(counter>=1000 || fabs(f(a))<0.0001)
            break;
    }
    if(counter>=1000)
        cout<<"too much oscillation";   //printed when no real root in solution such as x*x+1
    else
        cout<<"soln and no of iteration="<<a<<" "<<counter;
}


