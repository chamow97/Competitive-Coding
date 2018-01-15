//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;
 
/*-------------------------------------------------------- */
 
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define eb emplace_back
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
 
void solve()
{
	ll x, n;
	cin >> x >> n;
	if(n == 2 || n == 3)
	{
		cout << "impossible";
		return;
	}
	ll sum = (n * (n + 1))/2;
	sum -= x;
	ll currentSum = 0;
	if(sum % 2 != 0)
	{
		cout << "impossible";
	}
	else
	{
		
		ll sumOfFirst = 0, sumOfSecond = 0;
		vec pos(n+1, 0);
		sumOfFirst = sum/2;
		pos[x] = 2;
		ll position = -1;
		per(j,n,0)
		{
			if(pos[j] != 2)
			{
				pos[j] = 1;
				currentSum += j;
			}
			if(currentSum > sumOfFirst)
			{
				currentSum -= j;
				pos[j] = 0;
				position = j;
				break;
			}
		}
		ll extra = sumOfFirst - currentSum;
		if((extra == 2 && x == 2) || (extra == 1 && x == 1))
		{
			currentSum -= (position+1);
			sumOfFirst += position;
			pos[position+1] = 0;
			pos[position] = 1;
			++extra;
		}
		if(pos[extra] != 2)
		{
			pos[extra] = 1;
		}
		else
		{
			pos[1] = 1;
			pos[extra - 1] = 1;
		}
		sumOfFirst = 0, sumOfSecond = 0;
		rep(i,1,n+1)
		{
			if(pos[i] == 0)
			{
				sumOfFirst += i;
			}
			else if(pos[i] == 1)
			{
				sumOfSecond += i;
			}
		}
		if(sumOfFirst != sumOfSecond)
		{
			cout << "impossible";
		}
		else
		{
			rep(i,1,n+1)
			{
				cout << pos[i];
			}
		}
	}
}
 
int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}
 