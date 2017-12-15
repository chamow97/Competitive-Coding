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
	string str;
	while(cin >> str)
	{
		bool found = false;
		ll teama = 0, teamb = 0;
		rep(i,0,10)
		{
			ll otherRemaining = 0;
			ll currentRemaining = 0;
			if(i % 2 == 0)
			{
				if(str[i] == '1')
				{
					++teama;
				}
				otherRemaining = (10 - i)/2;
				if(teama > (teamb + otherRemaining))
				{
					cout << "TEAM-A " << i + 1<< '\n';
					found = true;
					break;
				}
				currentRemaining = (10 - i - 1)/2;
				if(teamb > (teama + currentRemaining))
				{
					cout << "TEAM-B " << i + 1<< '\n';
					found = true;
					break;
				}
			}
			else
			{
				if(str[i] == '1')
				{
					++teamb;
				}
				otherRemaining = (10 - i)/2;
				if(teamb > (teama + otherRemaining))
				{
					cout << "TEAM-B " << i + 1<< '\n';
					found = true;
					break;
				}
				currentRemaining = (10 - i - 1)/2;
				if(teama > (teamb + currentRemaining))
				{
					cout << "TEAM-A " << i + 1<< '\n';
					found = true;
					break;
				}
			}
		}	
		if(found == true)
		{
			continue;
		}
		teama = 0;
		teamb = 0;
		rep(i,10,20)
		{
			if(i % 2 == 0)
			{
				if(str[i] == '1')
				{
					++teama;
				}				
			}
			else
			{
				if(str[i] == '1')
				{
					++teamb;
				}
			}
			if(i % 2 == 1)
			{
				if(teama > teamb)
				{
					cout << "TEAM-A " << i + 1<< '\n';
					found = true;
					break;
				}
				else if(teamb > teama)
				{
					cout << "TEAM-B " << i + 1<< '\n';
					found = true;
					break;
				}
			}
		}
		if(!found)
			cout << "TIE\n";
	}
	return 0;
}
