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

/*-------------------------------------------------------- */

void solve()
{
	string str;
	cin >> str;
	vec freq(30, 0);
	ll n = str.length();
	rep(i,0,n)
	{
		freq[str[i] - 'a']++;
	}
	ll ptr = 0, i = 0, found = 0;
	ll fst = -1, scnd = -1;
	while(ptr < 26 && i < n)
	{
		if(freq[ptr] == 0)
		{
			++ptr;
			continue;
		}
		if(str[i] - 'a' == ptr)
		{
			ptr++;
		}
		else
		{
			if(ptr  > (str[i] - 'a'))
			{
				i++;
				continue;
			}
			fst = ptr;
			scnd = str[i] - 'a';
			break;
		}
	}
	ll now = ptr;
	rep(i,0,n)
	{
		if(str[i] - 'a' == fst && fst != -1)
		{	
			cout << char('a' + scnd);
		}
		else if(str[i] - 'a' == scnd && scnd != -1)
		{
			cout << char('a' + fst);
		}
		else
		{
			cout << str[i];
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