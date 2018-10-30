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
	ll n, m;
	cin >> n >> m;
	ll arr[m + 1][n + 1];
	ll pos[m + 1][n + 1];
	rep(i,0,m)
	{
		rep(j,0,n)
		{
			cin >> arr[i][j];
			pos[i][arr[i][j]] = j;
		}
	}
	ll ans = n;
	ll ptr1 = 0, ptr2 = 0;
	ll counter = 0;
	while(ptr1 <= ptr2 && ptr2 < n)
	{
		ll val1 = arr[0][ptr1];
		ll val2 = arr[0][ptr2];
		counter = 0;
		rep(i,1,m)
		{
			if(pos[i][val2] - pos[i][val1] == (ptr2 - ptr1))
			{
				++counter;
			}
			else
			{
				break;
			}
		}
		if(counter == m - 1)
		{
			// cout << ptr1 << ' ' << ptr2 << '\n';
			ptr2++;
		}
		else
		{
			ll diff = ptr2 - ptr1;
			ll curr = (diff * (diff + 1)) / 2;
			curr -= diff;
			ans += curr;
			ptr1 = ptr2;
		}
	}
	ll diff = ptr2 - ptr1;
	ll curr = (diff * (diff + 1)) / 2;
	curr -= diff;
	ans += curr;
	cout << ans;
	return 0;
}