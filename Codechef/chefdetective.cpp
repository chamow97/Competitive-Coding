#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int n,i,k=0;
    cin>>n;
    long long a[n],b[n],c[n];
    for(i=0;i<n;i++)
        {
            cin>>a[i];

        }
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                c[k++]=i;
            }
        }

        for(i=0;i<k;i++)
            cout<<c[i]<<" ";

}
