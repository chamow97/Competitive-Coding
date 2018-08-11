//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

bool myFunc(pair< ll, pair<ll, ll> > &p1, pair<ll, pair<ll, ll> > &p2)
{
	return p1.f > p2.f;
}

int main()
{
	ll n, m;
	cin >> n >> m;
 	vector< pair< ll, pair<ll, ll> > > p(n);
 	ll total = 0;
 	rep(i,0,n)
 	{
 		cin >> p[i].s.f;
 		cin >> p[i].s.s;
 		total += p[i].s.f;
 		p[i].f = p[i].s.f - p[i].s.s;
 	}
 	ll counter = 0;
 	sort(p.begin(), p.end(), myFunc);
 	if(total > m)
 	{
 		rep(i,0,p.size())
 		{
 			total -= p[i].f;
 			++counter;
 			if(total <= m)
 			{
 				break;
 			}
 		}
 	}
 	if(total > m)
 	{
 		cout << -1;
 	}
 	else
 	{
 		cout << counter;
 	}
	return 0;
}