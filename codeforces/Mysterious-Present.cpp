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

bool cmp(const pair< pair<ll, ll>, ll> &p1, const pair< pair<ll, ll>, ll> &p2)
{
	return ((p1.f.f * p1.f.s) < (p2.f.f * p2.f.s));
}

int main()
{
	fastread;
	ll n, w, h;
	cin >> n >> w >> h;
	vector< pair< pair<ll, ll>, ll> > arr;
	rep(i,1,n + 1)
	{
		ll w1, h1;
		cin >> w1 >> h1;
		arr.pb(mp(mp(w1, h1), i));
	}
	sort(arr.begin(), arr.end(), cmp);
	ll pos = n;
	rep(i,0,n)
	{
		if(arr[i].f.f > w && arr[i].f.s > h)
		{
			pos = i;
			break;
		}
	}
	if(pos == n)
	{
		cout << 0;
		return 0;
	}
	vec LIS(n + 1, 1);
	vec val(n + 1);
	rep(i,0,n+1)
	{
		val[i] = -1;
	}
	val[0] = -1;
	rep(i,pos + 1, n)
	{
		rep(j,pos,i)
		{
			if(arr[i].f.f > arr[j].f.f && arr[i].f.s > arr[j].f.s && arr[j].f.f > w && arr[j].f.s > h)
			{
				if(LIS[i] < LIS[j] + 1)
				{
					LIS[i] = LIS[j] + 1;
					val[i] = j;
				}
			}
		}
	}
	ll oldPos = pos;
	ll best = 1;
	rep(i,0,n)
	{
		if(LIS[i] > best)
		{
			best = LIS[i];
			pos = i;
		}
	}
	vec ans;
	while(pos >= oldPos && pos != -1)
	{
		ans.pb(arr[pos].s);
		pos = val[pos];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}