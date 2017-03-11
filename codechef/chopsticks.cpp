#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,sum=0;
    long long int n,d,t,j;
    cin>>n>>d;
   long int a[n];

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);

    for(i=0;i<n-1;)
    {
        if(a[i+1]-a[i]<=d)
        {
            sum++;
            i+=2;
        }
        else
            i++;

    }
    cout<<sum<<"\n";


}
