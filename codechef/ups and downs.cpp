#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long int i,t,n,a[100000];

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        if(n>2)
        {


        for(i=1;i<n-1;i+=2)
            swap(a[i],a[i+1]);
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }

}
