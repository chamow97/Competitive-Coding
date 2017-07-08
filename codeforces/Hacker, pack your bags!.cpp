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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

struct val{
    ll l, r, cost;
};

bool myFunc(val &a, val &b)
{
    if(a.l == b.l)
    {
    	return a.cost < b.cost;
    }
    return a.l < b.l;
}
int main()
{
	fastread;
	ll n, x;
	cin>>n>>x;
	val S[n+1];
	
	rep(i,0,n)
	{
	    cin>>S[i].l>>S[i].r>>S[i].cost;
	}
	sort(S, S+n, myFunc);
	vector<val> *v = new vector<val>[x+1];
	rep(i,0,n)
	{
		ll pos = S[i].r - S[i].l + 1;
		if(pos > x)
		{
			continue;
		}
		v[pos].pb(S[i]);
	}
	vec dp(200001,INF);
	rep(i,0,n)
	{
		ll other_pair = (S[i].r - S[i].l + 1);
		ll pair_of = x - other_pair;
		if(pair_of < 0)
		{
			continue;
		}
		ll low = 0, high = v[pair_of].size();
		ll ans = -1;
		while(low < high)
		{
			ll mid = (low + high + 1)/2;
			if(v[pair_of][mid].l > S[i].r)
			{
				ans = mid;
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		if(ans != -1)
		{
			dp[other_pair] = min(dp[other_pair], S[i].cost + v[pair_of][ans].cost);

		}

	}
	ll ans = INF;
	rep(i,1,200001)
	{
		ans = min(ans, dp[i]);
	}
	if(ans >= INF)
	{
		ans = -1;
	}
	cout<<ans;



return 0;
}