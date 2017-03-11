#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,t,a[22],k;
	long long sum=0;
	cin>>t;
	while(t--)
	{
	    bool isnot=false;
		sum=0;
		cin>>n>>k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%k!=0)
			cout<<"no\n";
		else
		{
            for(i=0;i<n;i++)
            {
                if(a[i]>(sum/k))
                {
                    isnot=false;
                    break;
                }
                else
                {
                    isnot=true;
                }
            }
            if(isnot==true)
            {
                cout<<"yes\n";
            }
            else
            {
                cout<<"no\n";
            }
		}
	}
}
