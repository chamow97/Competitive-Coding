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
	ll w, h, n;
	//understood the logic, but struggled to implement
	cin >> w >> h >> n;
	set<ll> horizontal, vertical;
	multiset<ll> horz, vert;
	horizontal.insert(0);
	vertical.insert(0);
	horizontal.insert(w);
	vertical.insert(h);
	horz.insert(w);
	vert.insert(h);
	rep(i,0,n)
	{
		string s;
		ll cut;
		cin >> s >> cut; 
		if(s[0] == 'H')
		{
			vertical.insert(cut);
			auto left = --vertical.find(cut);
			auto right = ++vertical.find(cut);
			auto pos = vert.find(*right - *left);
			vert.erase(pos);
			vert.insert(*right - cut);
			vert.insert(cut - *left);

		}
		else
		{
			horizontal.insert(cut);
			auto left = --horizontal.find(cut);
			auto right = ++horizontal.find(cut);
			auto pos = horz.find(*right - *left);
			horz.erase(pos);
			horz.insert(*right - cut);
			horz.insert(cut - *left);
		}
		ll width = *(--horz.end());
		ll height = *(--vert.end());
		cout << width * height << '\n';
	}

	return 0;
}
