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
	vec ip(26, 0);
	vec arr[30];
	rep(i,0,26)
	{
		cin >> ip[i];
	}
	string str;
	cin >> str;
	ll n = str.length();
	vec prefix(n, 0);
	rep(i,0,n)
	{
		arr[str[i] - 'a'].pb(i);
		if(i == 0)
		{
			prefix[i] = ip[str[i] - 'a'];
		}
		else
		{
			prefix[i] = prefix[i-1] + ip[str[i] - 'a'];
		}
	}
	ll total = 0;
	rep(i,0,26)
	{
		map<ll, ll> m;
		ll currAns = 0;
		for(auto j : arr[i])
		{
			currAns = currAns + m[prefix[j-1]];
			m[prefix[j]]++;
		}
		total += currAns;
	}
	cout << total;
	return 0;
}