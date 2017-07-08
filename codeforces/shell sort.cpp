#include<bits/stdc++.h>

using namespace std;

void shell(int n,int a[1000])
{
    int t,i,gap=n/2;
    while(gap)
    {
        for(i=0;i<n-gap;i++)
        {
            if(a[i]>a[i+gap])
            {
                t=a[i+gap];
                a[i+gap]=a[i];
                a[i]=t;
            }
            //cout<<a[i]<<' ';
        }
        //for(i=0;i<n;i++)
           // cout<<a[i]<<' ';
        cout<<'\n';
        gap/=2;
    }

}

int main()
{
    int i,n,a[1000];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    shell(n,a);
    shell(n,a);
    for(i=0;i<n;i++)
    cout<<a[i]<<' ';
}
