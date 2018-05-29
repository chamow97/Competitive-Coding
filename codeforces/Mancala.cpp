//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


/*-------------------------------------------------------- */

int main()
{
	fastread;
	vec arr(20, 0);
	ll maximum = 0;
	rep(i,1,15)
	{
		cin >> arr[i];
	}

	rep(i,1,15)
	{
		if(arr[i] == 0)
		{
			continue;
		}
		vec prefix(20, 0);
		prefix = arr;
		ll quo = arr[i] / 14;
		prefix[i] = 0;
		rep(j,1,15)
		{
			prefix[j] += quo;
		}
		ll rem = arr[i] % 14;
		ll counter = 0;
		rep(j,i+1,min(15ll, i + rem + 1))
		{
			prefix[j] += 1;
			counter++;
		}
		rem -= (counter);
		rep(j,1,1 + rem)
		{
			prefix[j] += 1;
		}
		ll ctr = 0;
		rep(j,1,15)
		{
			if(prefix[j] % 2 == 0)
			{
				ctr += prefix[j];
			}
		}
		maximum = max(maximum, ctr);
	}
	cout << maximum;
	return 0;
}