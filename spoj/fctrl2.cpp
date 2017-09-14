#include<bits/stdc++.h>

using namespace std;

int func(int x,int ressize,int res[100000])
{

	int carry=0,i,prod;

	for(i=0;i<ressize;i++)
	{
		prod=(x*res[i])+carry;
		res[i]=prod%10;
		carry=prod/10;

	}
	while(carry)
	{
		res[ressize]=carry%10;
		carry/=10;
		ressize++;

	}

return ressize;

}

void factorial(int n)
{
    int ressize=1,x,i;
    int res[100000];
    res[0]=1;
    for(x=2;x<=n;x++)
    {
    	ressize=func(x,ressize,res);
    }
    for(i=ressize-1;i>=0;i--)
    	cout<<res[i];
    cout<<'\n';


}


int main()
{
    long long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        factorial(n);
    }

}
