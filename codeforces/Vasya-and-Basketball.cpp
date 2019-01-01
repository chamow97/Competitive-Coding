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
	ll n, m;
	cin >> n;
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	cin >> m;
	vec brr(m + 1, 0);
	rep(i,1,m+1)
	{
		cin >> brr[i];
	}
	arr.push_back(1e9 + 100);
	brr.push_back(1e9 + 100);
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	ll maxDiff = 3 * (n - m);
	ll a = 3 * n, b = 3 * m;
	ll currA = 3 * n, currB = 3 * m;
	for(ll i = 1, j = 1; i <= n || j <= m;)
	{
		if(arr[i] < brr[j])
		{
			currA -= 1;
			i++;
		}
		else if(arr[i] > brr[j])
		{
			currB -= 1;
			j++;
		}
		else
		{
			currA -= 1;
			currB -= 1;
			i++;
			j++;
		}
		if(currA - currB > maxDiff)
		{
			maxDiff = currA - currB;
			a = currA;
			b = currB;
		}
	}
	cout << a << ":" << b;
	return 0;
}