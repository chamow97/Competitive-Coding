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
typedef vector<ll> vec;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
	ll n,m;
	cin>>n>>m;
	vec arr(m,0);
	rep(i,0,m)
	{
		cin>>arr[i];
	}
	ll steps = 0;
	ll previous = 1;
	rep(i,0,m)
	{
		if(arr[i] == previous)
		{
			//do nothing
		}
		else if(arr[i] < previous)
		{
			steps += ((n - previous) + (arr[i]));
			previous = arr[i];
		}
		else
		{
			steps += ((arr[i] - previous));
			previous = arr[i];
		}
		//cout<<steps<<endl;

	}
	cout<<steps<<endl;
	return 0;
}