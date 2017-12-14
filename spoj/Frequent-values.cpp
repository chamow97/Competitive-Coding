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

void constructTree(ll low, ll high, ll position, vector<ll> &array, vector<ll> &segmentArray)
{
	if(low == high)
	{
		segmentArray[position] = array[low];
	}
	else
	{
		ll mid = (low + high)/2;
		constructTree(low, mid, (2*position)+1, array, segmentArray);
		constructTree(mid+1, high, (2*position)+2, array, segmentArray);
		segmentArray[position] = max(segmentArray[(2*position)+1], segmentArray[(2*position)+2]);
	}
}

ll rangeMinimumQuery(ll lowerBound, ll upperBound, ll low, ll high, ll position, vector<ll> &segmentArray)
{
	if(lowerBound <= low && upperBound >= high) //complete overlap
	{
		return segmentArray[position];
	}
	else if(upperBound < low || lowerBound > high) // no overlap
	{
		return -INF;
	}
	else //partial overlap
	{
		ll mid = (low + high)/2;
		return max(rangeMinimumQuery(lowerBound, upperBound, low, mid, (2*position)+1, segmentArray),
		rangeMinimumQuery(lowerBound, upperBound, mid + 1, high, (2*position)+2, segmentArray));
	}
}
int main()
{
	fastread;
	while(true)
	{
		ll n, q;
		cin >> n;
		if(n == 0)
		{
			return 0;
		}
		cin >> q;
		vec arr(n, 0);
		rep(i,0,n)
		{
			cin >> arr[i];
		}
		vec suffix(n, 0);
		vec segmentArray(4*n, 0);
		suffix[n-1] = 1;
		per(j, n-2, 0)
		{
			if(arr[j] == arr[j+1])
			{
				suffix[j] = suffix[j+1] + 1;
			}
			else
			{
				suffix[j] = 1;
			}
		}
		constructTree(0, n-1, 0, suffix, segmentArray);
		while(q--)
		{
			ll l, r;
			cin >> l >> r;
			--l;
			--r;
			cout << rangeMinimumQuery(l, r, 0, n-1, 0, segmentArray) << '\n';
		}

	}
	return 0;
}
