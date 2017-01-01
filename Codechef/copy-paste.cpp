#include<iostream>
#include<stdlib.h>

using namespace std;
int main()
{

    int t;
    cin>>t;
    long int n,a[100000],i,j,size=0;
    while(t--)
    {
        size=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[abs(a[i])]>=0)
                a[abs(a[i])]=-a[abs(a[i])];
            else
                ++size;

        }


        cout<<n-size<<"\n";

    }

}
