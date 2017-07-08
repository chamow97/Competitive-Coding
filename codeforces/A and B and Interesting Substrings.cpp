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

bool myFunc(pair<ll, ll> &a, pair<ll, ll> &b)
{
	return a.second < b.second;
}
int main()
{
	fastread;
	vec alpha(26,0);
	string str;
	rep(i,0,26)
	{
		cin>>alpha[i];
	}
	cin>>str;
	ll len = str.length();
	vec prefix(len,0);
	rep(i,0,len)
	{
		prefix[i] = alpha[str[i] - 'a'];
	}
	rep(i,1,len)
	{
		prefix[i] += prefix[i-1];
		// cout<<prefix[i]<<" ";
	}
	vector< pair<ll, ll> > v;
	vec *occurence = new vec[26];
	rep(i,0,len)
	{
		v.pb(mp(str[i] - 'a',prefix[i]));
	}
	sort(v.begin(), v.end(), myFunc);
	rep(i,0,len)
	{
		occurence[v[i].first].pb(v[i].second);
	}
	ll ans = 0;
	rep(i,0,26)
	{
		rep(j,0,occurence[i].size())
		{
			ll isSame = *lower_bound(occurence[i].begin()+j, occurence[i].end(), occurence[i][j]+alpha[i]);
			// cout<<i<<" "<<occurence[i][j]<<" "<<isSame<<"\n";
			if(isSame == occurence[i][j]+alpha[i])
			{
				ll pos1 = (lower_bound(occurence[i].begin()+j, occurence[i].end(), occurence[i][j]+alpha[i])) - occurence[i].begin();
				ll pos2 = (upper_bound(occurence[i].begin()+j, occurence[i].end(), occurence[i][j]+alpha[i])) - occurence[i].begin();
				ans += abs(pos2 - pos1);
			}
			// cout<<occurence[i][j]<<" ";
			
		}
		// cout<<'\n';
	}
	cout<<ans;
	return 0;
}