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
	ll n, m, k;
	cin >> n >> m >> k;
	if(k <= n-1)
	{
		cout << k + 1 << ' ' << 1;
		return 0;
	}
	if(k <= (n + m - 2))
	{
		k -= (n - 1);
		cout << n << ' ' << k + 1;
		return 0; 
	}
	ll now = k - (n - 1 + m);
	ll row = now / (m-1);
	ll lr = 1;
	if(row % 2 == 0)
	{
		lr = 0;
	}
	ll col = now % (m-1);
	cout << n - row - 1 << ' ';
	if(lr == 1)
	{
		cout << col + 2;
	} 
	else
	{
		cout << m - col;
	}
	return 0;
}