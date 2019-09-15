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

ll getLargest(ll ptr1, ll ptr2, vec &arr, ll k)
{
	ll n = ptr2 - ptr1 + 1;
	ll largestSum = 0, previousSum = 0;
	rep(i,ptr1,ptr1+n-k+1)
	{
		if(i == ptr1)
		{
			rep(j,ptr1,ptr1 + k)
			{
				largestSum += arr[j];
			}
			previousSum = largestSum;
		}
		else
		{
			ll currSum = previousSum - arr[i - 1] + arr[i + k - 1];
			if(currSum > largestSum)
			{
				largestSum = currSum;
			}
			previousSum = currSum;
		}
	}
	return largestSum;
}

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	vec prefix(n + 1, 0);
	rep(i,1,n+1)
	{
		prefix[i] = prefix[i - 1] + arr[i];
	}
	string str;
	cin >> str;
	ll ans = 0;
	str = '0' + str;
	ll ptr1 = 1, ptr2 = 2;
	while(ptr2 <= n)
	{
		while(str[ptr2] == str[ptr1] && ptr2 <= n)
		{
			ptr2++;
		}
		if((ptr2 - ptr1) <= k)
		{
			ans += (prefix[ptr2 - 1] - prefix[ptr1 - 1]);
		}
		else
		{
			multiset<ll, greater<ll>> ms;
			rep(i,ptr1,ptr2)
			{
				ms.insert(arr[i]);
			}
			ll ptr = 0;
			for(auto i : ms)
			{
				if(ptr >= k)
				{
					break;
				}
				ptr++;
				ans += i;
			}
		}
		// cout << ans << ' ';
		ptr1 = ptr2;
		ptr2 = ptr1 + 1;
	}
	if(ptr1 <= n)
	{
		multiset<ll> ms1;
		rep(i,ptr1,ptr2)
		{
			ms1.insert(arr[i]);
		}
		ll ptr = 0;
		for(auto i : ms1)
		{
			if(ptr >= k)
			{
				break;
			}
			ptr++;
			ans += i;
		}
	}
	cout << ans;
	return 0;
}