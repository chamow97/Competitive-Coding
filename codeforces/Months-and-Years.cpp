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

bool checker(vec check, vec arr)
{
	rep(i,0,check.size() - arr.size())
	{
		ll counter = 0;
		vec newV(check.begin()+i, check.begin()+i+arr.size());
		rep(i,0,newV.size())
		{
			if(arr[i] == newV[i])
			{
				++counter;
			}
		}
		if(counter == arr.size())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	fastread;
	ll n;
	vec possibility(12);
	vec possibility1(12);
	rep(i,0,12)
	{
		if(i == 0 or i == 2 or i == 4 or i == 6 or i == 7 or i == 9 or i == 11)
		{
			possibility[i] = 31;
		}
		else if(i == 1)
		{
			possibility[i] = 28;
		}
		else
		{
			possibility[i] = 30;
		}
	}
	rep(i,0,12)
	{
		if(i == 0 or i == 2 or i == 4 or i == 6 or i == 7 or i == 9 or i == 11)
		{
			possibility1[i] = 31;
		}
		else if(i == 1)
		{
			possibility1[i] = 29;
		}
		else
		{
			possibility1[i] = 30;
		}
	}
	vec check1, check2,check3, check4;
	rep(i,0,12)
	{
		check1.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check1.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check1.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check1.pb(possibility1[i]);
	}
	rep(i,0,12)
	{
		check2.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check2.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check2.pb(possibility1[i]);
	}
	rep(i,0,12)
	{
		check2.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check3.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check3.pb(possibility1[i]);
	}
	rep(i,0,12)
	{
		check3.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check3.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check4.pb(possibility1[i]);
	}
	rep(i,0,12)
	{
		check4.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check4.pb(possibility[i]);
	}
	rep(i,0,12)
	{
		check4.pb(possibility[i]);
	}
	cin >> n;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	bool possible = checker(check1, arr);
	possible = possible | (checker(check2, arr));
	possible = possible | (checker(check3, arr));
	possible = possible | (checker(check4, arr));
	if(possible)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
