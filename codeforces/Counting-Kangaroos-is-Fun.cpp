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

ll ind = -1;

void findItsPair(ll low, ll high, ll val, vec &arr)
{
	if(high < low)
	{
		return;
	}
	ll mid = (low + high) / 2;
	if(arr[mid] <= val)
	{
		ind = mid;
		high = mid - 1;
	}
	else
	{
		low = mid + 1;
	}
	findItsPair(low, high, val, arr);
}

int main()
{
	ll n;
	cin >> n;
	vec arr(n);
	boolean seen(n, false);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	ll right = n / 2;
	ll ans = n;
	rep(i,0,n/2)
	{
		bool found = false;
		while(right < n && !found)
		{
			if(arr[i] * 2 <= arr[right])
			{
				right++;
				ans--;
				found = true;
				break;
			}
			else
			{
				right++;
			}
		}
		if(right >= n)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}