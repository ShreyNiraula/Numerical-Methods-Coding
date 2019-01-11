#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, counter=0;
    cout<<"enter n:"; cin>>n;
    float A[n][n], guess[n], ans[n], x[n], sub[n], maxm, dmax;

    cout<<"enter element of guess matrix by using 0 and 1 only:";
    for(int i=0; i<n; i++)
    {
        cin>>guess[i];
        //checking for invalidity of all element=0
        if(guess[i]==0)
            counter++;
        if(counter>=3)
        {
            do
            {   cout<<"Re-enter last element other than 0:";
                cin>>guess[i];
            }while(guess[i]==0);
        }
    }
    cout<<"enter the element of square matrix:"<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>A[i][j];

    while(true)
    {
        // sq mat * guess mat process
        for(int i=0; i<n; i++)
        {
            ans[i]=0;    //DO NOT FORGET
            for(int j=0; j<n; j++)
                ans[i]+=A[i][j]*guess[j];
        }
    //normalization begins...
        //finding max element to divide for...
        maxm=0; //to reset for each loop
        for(int i=0; i<n; i++)
            if(fabs(ans[i])>maxm)   //fasb as we need only 18 not -18 (+ve value)
                maxm=fabs(ans[i]);

        for(int i=0; i<n; i++)
        {
            x[i]=ans[i]/maxm;    //as x2, x3...xn+1
            sub[i]=x[i]-guess[i];
            guess[i]=x[i];     //as x1, x2,....xn
        }
//finding the max element to compare for Xn+1-Xn nearly zero
        dmax=0;
        for(int i=0; i<n; i++)
            if(fabs(sub[i])>dmax)
                dmax=fabs(sub[i]);

        if(dmax<0.0001)
            break;
    }

    cout<<"Eigen value="<<maxm<<endl;
    for(int i=0; i<n; i++)
        cout<<"element of Eigen vector="<<x[i]<<endl;
}
