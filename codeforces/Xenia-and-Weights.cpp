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

vec ans;
string str;
ll m;
vec previous(1011, 0);
bool solve(ll current, ll diff)
{
	if(current > m)
	{
		return true;
	}
	rep(i,diff + 1, 11)
	{
		if(str[i] == '1' && previous[current-1] != i)
		{
			previous[current] = i;
			if(solve(current + 1, i - diff) == true)
			{
				return true;
			}
			
		}
	}
	return false;
}

int main()
{
	previous[0] = 0;
	fastread;
	cin >> str;
	str = '#' + str;
	cin >> m;
	//saw editorial for ideas
	//its just starting at (0,0,1) to (x,y,m)
	//ie initially we have no weights and we
	//are at the first step, we habe to go somewhere
	//(x,y) in m steps and weight diff should not exceed 10
	//in any step
	if(solve(1, 0))
	{
		cout << "YES\n";
		rep(i,1,m+1)
		{
			cout << previous[i] << " ";
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
