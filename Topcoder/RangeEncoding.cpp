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

class RangeEncoding
{
public:

	int minRanges(std::vector<int> v)
	{
		ll n = v.size();
		ll range = 0;
		ll counter = 1;
		if(n == 1)
		{
			return 1;
		}
		rep(i,1,n)
		{
			if(v[i] == (v[i-1] + 1))
			{
				++counter;
			}
			else
			{
				range++;
				counter = 1;
			}
		}
		if(counter >= 1)
        {
            ++range;
        }
		return range;

	}

};

//int main()
//{
//	fastread;
//	RangeEncoding R;
//	ll n;
//	cin>>n;
//	std::vector<int> v(n);
//	rep(i,0,n)
//	{
//		cin>>v[i];
//	}
//	cout<<R.minRanges(v);
//	return 0;
//}
