#include<bits/stdc++.h>

using namespace std;
long long callfunc(long long i,long long n)
{
    long long counter=0;
    while(n!=1 )
    {
        n/=i;
        counter++;
        if(n/i==0)
            break;
    }
    return counter;
}


int main()
{
    long long i,j,t,n,sum=1;
    cin>>t;
    while(t--)
    {
        sum=1;
    	cin>>n;
    	int a[n+1];
    	for(i=2;i<=n;i++)
    		a[i]=0;
    	for(i=2;i<=pow(n,0.5);i++)
    	{
    		if(a[i]==1)
    			continue;
    		for(j=i*2;j<=n;j+=i)
    		{
    			a[j]=1;
    		}
    	}
        for(i=2;i<=n;i++)
        {
            if(a[i]==0)
            {               
                long long power=callfunc(i,n);
                sum*=(pow(i,power));
                
            }
        }
        cout<<sum<<'\n';
    	

    }
}
