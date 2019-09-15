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
 
struct lex_compare {
    bool operator() (const pair<ll, pair<ll, ll> > &p1, const pair<ll, pair<ll, ll> > &p2) const {
    	if(p1.s.f == p2.s.f)
    	{
    		return p1.f < p2.f;
    	}
        return p1.s.f > p2.s.f;
    }
};

int main()
{
	fastread;
	ll n;
	cin >> n;
	multiset<pair<ll, pair<ll, ll> >, lex_compare> s;
	rep(i,0,n)
	{
		ll c, p;
		cin >> c >> p;
		s.insert(mp(c, mp(p, i)));
	}
	ll k;
	cin >> k;
	multiset< pair<ll, ll> > s1;
	rep(i,0,k)
	{
		ll tableSize;
		cin >> tableSize;
		s1.insert(mp(tableSize, i));
	}
	ll total = 0;
	vecpair ans;
	while(!s.empty())
	{
		pair<ll, pair<ll, ll> > curr = *s.begin();
		s.erase(s.begin());
		auto it = s1.lower_bound(mp(curr.f, -INF));
		if(it != s1.end())
		{
			total += (curr.s.f);
			ans.pb(mp(curr.s.s, (*it).s));
			s1.erase(it);
		}
	}
	cout << ans.size() << ' ' << total << '\n';
	for(auto it : ans)
	{
		cout << it.f + 1 << ' ' << it.s + 1 << '\n';
	}
	return 0;
}