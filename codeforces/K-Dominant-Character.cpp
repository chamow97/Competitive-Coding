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

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	string str;
	cin>>str;
	ll n = str.length();
	str = '0' + str;
	ll ans =  n;
	rep(i,0,26)
	{
		char curr = 'a' + i;
		vec occurence(n+1,0);
		rep(j,1,n+1)
		{
			if(str[j] == curr)
			{
				occurence[j]  = occurence[j-1] + 1;
			}
			else
			{
				occurence[j] = occurence[j-1];
			}
		}
		ll low = 1, high = n;
		while(low <= high)
		{
			ll mid = (low + high + 1)/2;
			// cout<<mid<<" ";
			bool possible = true;
			// rep(k,1,n+1)
			// {
			// 	cout<<occurence[k]<<" ";
			// }
			// cout<<'\n';
			for(ll j = mid; j <= n; j ++)
			{
				// cout<<occurence[j] - occurence[j- mid]<<" ";
				if(occurence[j] - occurence[j- mid] == 0)
				{
					possible = false;
					break;
				}
			}
			// cout<<'\n';
			if(possible)
			{
				ans = min(ans, mid);
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}
	cout<<ans;
	return 0;
}
