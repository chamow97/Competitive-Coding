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
const ll maxn = 1e6;

ll prefix[maxn+10][10];
vec ans(maxn+10, -1);
int main()
{
	fastread;
	rep(i,1,1e6+1)
	{
		ll product = i;
		ll temp = i;
		bool isDone = false;
		while(product > 9)
		{
			product = 1;
			while(temp)
			{
				if(temp % 10 != 0)
				product *= (temp % 10);
				temp /= 10;
			}
			temp = product;
			if(ans[temp] != -1)
			{
				ans[i] = ans[temp];
				isDone = true;
				break;
			}
		}
		if(!isDone)
		{
			ans[i] = product;
		}

	}
	rep(i,1,1e6+1)
	{
		rep(j,0,10)
		{
			prefix[i][j] = 0;
		}
		prefix[i][ans[i]]++;
		rep(j,0,10)
		{
			prefix[i][j] += prefix[i-1][j]; 
		}
	}
	ll q;
	cin >> q;
	while(q--)
	{
		ll l, r, k;
		cin >> l >> r >> k;
		cout << prefix[r][k] - prefix[l-1][k] << '\n'; 
	}
	return 0;
}