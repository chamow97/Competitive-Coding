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
	cin >> str;
	ll n = str.length();
	set<ll> zeroes, ones;
	rep(i,0,n)
	{
		if(str[i] == '0')
		{
			zeroes.insert(i);
		}
		else
		{
			ones.insert(i);
		}
	}
	vector< vector<ll> > ans;
	ll totalSize = 0;
	ll ptr = zeroes.size();
	while(ptr > 0)
	{
		//forming sequences take as much as you can
		ll pos = 0;
		vec currAns;
		while(zeroes.lower_bound(pos) != zeroes.end())
		{
			auto position = zeroes.lower_bound(pos);
			currAns.pb(*position);
			pos = *position;
			zeroes.erase(position);
			if(ones.lower_bound(pos) == ones.end())
			{
				break;
			}
			auto position1 = ones.lower_bound(pos);
			if(zeroes.lower_bound(*position1) == zeroes.end())
			{
				break;
			}
			else
			{
				currAns.pb(*position1);
				pos = *position1;
				ones.erase(position1);
			}
		}
		totalSize += ll(currAns.size());
		sort(currAns.begin(), currAns.end());
		ans.pb(currAns);
		ptr = zeroes.size();
	}

	for(auto i : zeroes)
	{
		vec currAns;
		currAns.pb(i);
		ans.pb(currAns);
		totalSize++;
	}
	if(totalSize == n)
	{
		cout << ans.size() << '\n';
		rep(i,0,ans.size())
		{
			cout << ans[i].size() << ' ';
			rep(j,0,ans[i].size())
			{
				cout << ans[i][j] + 1 << ' ';
			}
			cout << '\n';
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}