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
	ll n;
	cin >> n;
	vec arr(n);
	string winner[] = {"BitLGM", "BitAryo"};
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	if(n == 1)
	{
		if(arr[0] == 0)
		{
			cout << winner[1];
		}
		else
		{
			cout << winner[0];
		}
	}
	else if(n == 2)
	{
		bool table[arr[0] + 1][arr[1] + 1];
		ll n = arr[0];
		ll m = arr[1];
		rep(i,0,n+1)
		{
			table[i][0] = true;
		}
		rep(i,0,m+1)
		{
			table[0][i] = true;
		}
		table[0][0] = false;
		rep(i,1,n+1)
		{
			rep(j,1,m+1)
			{
				bool curr = true;
				// case 1: reduce minimum of those
				ll minimum = min(i, j);
				rep(k,1,minimum + 1)
				{
					curr = (curr && table[i - k][j - k]);
				}
				rep(k,1,i+1)
				{
					curr = (curr && table[i - k][j]);
				}
				rep(k,1,j+1)
				{
					curr = (curr && table[i][j - k]);
				}
				table[i][j] = !curr;
			}
		}
		cout << winner[1 - table[n][m]];
	}
	else
	{
		ll xorVal = (arr[0] ^ arr[1] ^ arr[2]);
		if(xorVal == 0)
		{
			cout << winner[1 - xorVal];
		}
		else
		{
			cout << winner[xorVal == 0];
		}
	}
	return 0;
}