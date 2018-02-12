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

ll n, m;
const ll maxn = 1e5+100;
vec bikes(maxn, 0);
vec boys(maxn, 0);
ll extra;
ll maxBoys;
ll minCost;
ll extraRemaining;

void binary_search(ll low, ll high)
{
	if(low > high)
	{
		return;
	}
	ll mid = (low + high)/2;
	ll nowExtra = extra;
	ll nowCost = 0;
	bool isPossibleNow = true;
	rep(i,0,mid)
	{
		if(boys[mid - i - 1] >= bikes[i])
		{
			nowCost += bikes[i];
		}
		else
		{
			ll difference = bikes[i] - boys[mid - i - 1];
			if(nowExtra >= difference)
			{
				nowExtra -= difference;
				nowCost += boys[mid - i - 1];
			}
			else
			{
				isPossibleNow = false;
				break;
			}
		}
	}
	if(!isPossibleNow)
	{
		binary_search(low, mid - 1);
	}
	else
	{
		maxBoys = mid;
		minCost = nowCost;
		extraRemaining = nowExtra;
		binary_search(mid + 1, high);
	}
}

int main()
{
	fastread;
	cin >> n >> m >> extra;
	boys.resize(n);
	bikes.resize(m);
	rep(i,0,n)
	{
		cin >> boys[i];
	}
	rep(i,0,m)
	{
		cin >> bikes[i];
	}
	sort(boys.rbegin(), boys.rend());
	sort(bikes.begin(), bikes.end());
	binary_search(0, min(n, m));
	cout << maxBoys << ' ' << max(0ll, minCost - extraRemaining);
	return 0;
}