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
	ll a, b, x;
	cin >> a >> b >> x;
	char fst = '0', scnd = '1';
	if(a < b)
	{
		swap(fst, scnd);
		swap(a, b);
	}
	string ans = "";
	rep(i,0,x - 1)
	{
		if(i % 2 == 0)
		{
			ans += fst;
			--a;
		}
		else
		{
			ans += scnd;
			--b;
		}
	}
	if((x - 1) % 2 == 0)
	{
		rep(i,0,a)
		{
			ans += fst;
		}
		rep(i,0,b)
		{
			ans += scnd;
		}
	}
	else
	{
		rep(i,0,b)
		{
			ans += scnd;
		}
		rep(i,0,a)
		{
			ans += fst;
		}
	}
	cout << ans;
	return 0;
}