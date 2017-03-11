#include<bits/stdc++.h>

using namespace std;
int main()
{

	long long i,n,a[1000],t1=0,t2=0,minimum=INT_MAX,maximum=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
    {
        if(a[0]==a[i])
            ++t1;
        if(a[n-1]==a[i])
            ++t2;
    }


    cout<<a[n-1]-a[0];
    if(a[n-1]==a[0])
        cout<<' '<<n*(n-1)/2;
    else
        cout<<' '<<t1*t2;

}

