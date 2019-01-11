//PROGRAM to demonstrate IEEE standard for floating points numbers

#include<iostream>
using namespace std;

int main()
{
    float x=0.25;
    float y=0.75;
    float a=0.1;
    float b=0.3;

    if(x+x+x==y)
        cout<<"true"<<endl;   //true as 0.25=2^-2 ie exact value representation and 0.75=(2^-1)+ (2^-2)
    else
        cout<<"false"<<endl;


    if(a+a+a==b)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;   //false as 0.1 does not have exact representation of any power 2 or its sum

}
