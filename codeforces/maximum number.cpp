//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
	ll n;
	cin>>n;
	if(n == 2)
	{
		cout<<1;
	}
	else if(n == 3)
	{
		cout<<7;
	}
	else
	{
	string prev1 = "1";
	string prev2 = "7";
	string ans = "";
	rep(i,4,n+1)
	{
		if(i%2 == 0)
		{
			ans = prev1 + "1";
		}
		else
		{
			ans = prev1 + "1";
		}
		prev1 = prev2;
		prev2 = ans;
	}
	cout<<ans;
}
	
	return 0;
}