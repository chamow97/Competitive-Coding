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

void seive(boolean &arr)
{
	rep(i,2,sqrt(100000) + 1)
	{
		if(arr[i] == true)
		{
			for(ll j = i*2; j<100000; j+=i)
			{
				arr[j] = false;
			}
		}
	}
}

int main()
{
	ll n, m;
	boolean arr(100001,true);
	seive(arr);
	cin>>n;
	rep(i,1,1001)
	{
		if(arr[((n*i) + 1)] == false)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}