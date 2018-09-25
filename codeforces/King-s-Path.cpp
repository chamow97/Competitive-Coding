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
int main()
{
	fastread
	ll x0, x1, y0, y1;
	cin >> x0 >> y0 >> x1 >> y1;
	ll n;
	cin >> n;
	set< pair<ll, ll> > s;
	rep(i,0,n)
	{
		ll r, x, y;
		cin >> r >> x >> y;
		rep(j,x,y+1)
		{
			s.insert(mp(r,j));
		}
	}
	map< pair<ll, ll>, bool> m;
	m[mp(x0, y0)] = true;
	queue< pair< pair<ll, ll>, ll> > q;
	q.push(mp(mp(x0, y0), 0ll));
	while(!q.empty())
	{
		auto top = q.front();
		q.pop();
		ll x = top.f.f;
		ll y = top.f.s;
		ll w = top.s;
		if(x == x1 && y == y1)
		{
			cout << w;
			return 0;
		}
		rep(i,-1,2)
		{
			rep(j,-1,2)
			{
				if(m[mp(x + i, y + j)] == false)
				{
					if(s.find(mp(i + x, y + j)) != s.end())
					{
						m[mp(x + i, y + j)] = true;
						q.push(mp(mp(x + i, y + j), w + 1));
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}