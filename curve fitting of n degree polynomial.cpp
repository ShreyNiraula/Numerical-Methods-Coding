#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int d, n, i, j;
    float temp;
    cout<<"enter degree of equation to fit:"; cin>>d;
    cout<<"enter number of data:"; cin>>n;

    float x[n], y[n], m[d+1][d+2];   //as for 2 degree, 3 eqn (3 row + (3+1(due to augmented constant))columns)

    cout<<"enter the set of x:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>x[i];
    }

    cout<<"enter the set of y:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>y[i];
    }

    //for main operation
    for(int i=0; i<(d+1); i++) //d+1 as a,b,c variable ie d=0 to d=2
    {
        float sum2=0;
        for(j=0; j<d+1; j++)   //not int j as j used outside its loop
        {
            float sum=0;
            for(int k=0; k<n; k++)  //as there are n data, extra loop needed to access set of x
                {
                    sum+= pow(x[k],j+i);  //j+i as 2nd row begins by Ex not n ie starting power value is i value
                }

            m[i][j]=sum;
        }
        for(int k=0; k<n; k++)    //for Ey, Exy, Ex2y part....
            sum2+=pow(x[k],i)*y[k];

        m[i][j]=sum2;             //j=3 always
    }

//    cout<<"displaying matrix:"<<endl;
//    for(int i=0; i<d+1; i++)
//    {
//        for(int j=0; j<d+2; j++)
//        {
//            cout<<m[i][j]<<" ";
//        }
//        cout<<"\n";
//    }

    //Gauss jordan to solve the matrix
    for(int j=0; j<d+1; j++)    //for n deg, n+1 unknown
    {
        for(int i=0; i<d+1; i++)
        {
            if(i!=j)   //elements other than diagonal element
            {
                temp= m[i][j]/m[j][j];    //this value may change after row operation, so preserving itAS
                for(int k=0; k<d+2; k++)   //k=d+2
                {

                    m[i][k]-=temp*m[j][k];
                }
            }
        }
    }
    float X[d+1];   //for 2nd degree three unknown: a,b,c
    cout << "a,b,c=";
    for(int i = 0; i<d+1; i++)
    {
        X[i] =m[i][d+1]/m[i][i];   //4th column element divided by its eqv diagonal element
        cout << X[i] << ",";
    }

}
