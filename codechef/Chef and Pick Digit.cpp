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

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		map<ll,ll> m;
		string str;
		cin>>str;
		string ans = "";
		rep(i,0,str.length())
		{
			m[str[i] - '0']++;
			// cout<<(str[i] - 'A')<<" ";
		}
		ll counter = 65;
		while(counter <= 90)
		{
			ll first = counter;
			ll second = counter % 10;
			first /= 10;
			if(first == second)
			{
				if(m[first] >= 2)
				{
					ans = ans + char(counter);
				}
			}
			else
			{
				// cout<<first<<" "<<second<<'\n';
				if(m[first] >= 1 && m[second] >= 1)
				{
					ans = ans + char(counter);
				}
			}
			++counter;
		}
		sort(ans.begin(), ans.end());
		cout<<ans<<'\n';
	}
	return 0;
}