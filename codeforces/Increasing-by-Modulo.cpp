//template by chamow
//After a long time, I <3 you CF lol :P
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

ll binarySearch(ll low, ll high, ll n, ll m, vec &arr)
{
	if(high == low)
	{
		return low;
	}
	ll mid = (low + high) / 2;
	bool notPossible = false;
	ll prevValue = 0;
	// Search whether current value is within range, range here means, well you know lol
	rep(i,0,n)
	{
		// if prevValue is within currMin and currMax, then its fine, as we can choose some value
		// another case like lets say m = 20, we have arr[i] = 18, mid = 3 and prev value = 1, we can make it (18 + 3) % 20
		// which is still >= prevValue so done
		if((prevValue >= arr[i] and prevValue <= arr[i] + mid) or ((arr[i] + mid) >= (prevValue + m)))
		{
			// do nothing, its already set
		}
		else
		{
			if(arr[i] < prevValue) {
				notPossible = true;
				break;
			}
			else
			{
				prevValue = arr[i];
			}
		}
	}
	if(notPossible)
	{
		// give me more
		low = mid + 1;
	}
	else
	{
		high = mid;
	}
	return binarySearch(low, high, n, m, arr);

}

int main()
{
	ll n, m;
	cin >> n >> m;
	vec arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll low = 0, high = m;
	// why high is m? well you can just replicate the array itself if you can do m ops
	cout << binarySearch(low, high, n, m, arr) << '\n';
	return 0;
}