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
	ll h;
	cin >> h;
	h = h + 1;
	vec height(h+1, 0);
	ll total = 0;
	rep(i,0,h)
	{
		cin >> height[i];
		total += height[i];
	}
	bool possible = true;
	ll currPos = -1;
	rep(i,1,h)
	{
		if(height[i] != 1 && height[i-1] != 1)
		{
			currPos = i;
			possible = false;
			break;
		}
	}
	if(possible)
	{
		cout << "perfect";
	}
	else
	{
		cout << "ambiguous\n";
		vec possibility1(1e6, 0), possibility2(1e6, 0);
		//1
		ll pos = 0, curr = 1;
		rep(i,1,h)
		{
			rep(j,0,height[i])
			{
				possibility1[++pos] = curr;
			}
			curr = pos + 1;
		}
		pos = 0, curr = 1;
		//2
		rep(i,1,h)
		{
			if(i == currPos)
			{
				possibility2[++pos] = curr;
				rep(j,1,height[i])
				{
					possibility2[++pos] = curr - 1;
				}
			}
			else
			{
				rep(j,0,height[i])
				{
					possibility2[++pos] = curr;
				}
			}
			curr = pos + 1;
		}
		rep(i,0,total)
		{
			cout << possibility1[i] << ' ';
		}
		cout << '\n';
		rep(i,0,total)
		{
			cout << possibility2[i] << ' ';	
		}
	}

	return 0;
}
