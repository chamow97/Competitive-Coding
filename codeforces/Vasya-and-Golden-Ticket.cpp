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
	ll n;
	cin >> n;
	vec arr(n + 1, 0);
	string str;
	cin >> str;
	str = '0' + str;
	rep(i,1,n+1)
	{
		arr[i] = str[i] - '0';
	}
	rep(i,1,n+1)
	{
		arr[i] += arr[i - 1];
	}
	rep(i,1,n)
	{
		ll now = arr[i];
		ll ptr = i;
		bool isPossible = false;
		while(ptr <= n)
		{
			now += arr[i];
			ptr = lower_bound(arr.begin() + ptr + 1, arr.end(), now) - arr.begin();
			if(arr[ptr] != now)
			{
				break;
			}
			if(ptr == n || (arr[ptr] == arr[n]))
			{
				isPossible = true;
			}
		}
		if(isPossible)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}