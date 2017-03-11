#include<bits/stdc++.h>
using namespace std;

int rec(int u,int v,int a[])
{
    if(u<=v)
    {

    }
}
int main()
{
    int temp,n,t,sum=0,i,a[5000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum&1==1)
        {
            cout<<"0\n";
        }
        else
        {
            rec(0,n-1,a);
        }
    }

}
