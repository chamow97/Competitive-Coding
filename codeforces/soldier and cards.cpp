#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pbb pop_back
long long factorial(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return n;
    else
        return n*factorial(n-1);
}
int main()
{
    long long val=0;
	int n,k1,k2,i,ar[10],br[10],temp=0,counter=0,pos;
	vector<int> a;
	vector<int> b;
	bool flag=false;
	cin>>n;
	val = factorial(n+1);
	cin>>k1;
	// for(i=0;i<k1;i++)
	// {
	// 	cin>>ar[i];
	// }
	for(i=0;i<k1;i++)
	{
		cin>>temp;
		a.pb(temp);
	}
	cin>>k2;
	// for(i=0;i<k2;i++)
	// {
	// 	cin>>br[i];
	// }
	for(i=0;i<k2;i++)
	{
		cin>>temp;
		b.pb(temp);
	}

	while(flag==false)
	{


		if(a.front()>b.front())
		{
			temp=b.front();
			b.erase(b.begin());
			a.pb(temp);
			temp=a.front();
			a.erase(a.begin());
			a.pb(temp);
		}
		else
		{
			temp=a.front();
			a.erase(a.begin());
			b.pb(temp);
			temp=b.front();
			b.erase(b.begin());
			b.pb(temp);
		}
		++counter;
		if(a.size()==0)
		{
		    pos=2;
			break;
		}
		else if(b.size()==0)
        {
            pos=1;
            break;
        }
        if(counter>val)
        {
            flag=true;
        }
	}
	if(counter<=val)
    {
        cout<<counter<<' '<<pos;
    }
	else
    {
        cout<<"-1";
    }
}
