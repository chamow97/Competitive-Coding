#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long int i,t,n,a[50000],move1=0,move2=0;
    cin>>t;
    while(t--)
    {
        move1=0;
        move2=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(i=0;i<n;)
        {
            if(a[i]==a[i+1])
            {
                ++move2;
                i++;
            }
            if(i==n-1)
            {++move2;
            break;}
            else if(a[i]!=a[i+1])
            {
                ++move1;
                i+=2;
            }


        }
        cout<<move1+move2<<"\n";
    }
}
