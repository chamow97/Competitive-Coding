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

void solve()
{
	ll n;
	cin >> n;
	vec arr(n,0);
	vec frequency(1e5+100, 0);
	vec ans(1e5+100,0);
	rep(i,0,n)
	{
		cin >> arr[i];
		frequency[arr[i]]++;
	}
	vec totalOnes, totalTwos;
	ll oneCount = 0, twoCount = 0;
	ll extra1, extra2, extra3;
	rep(i,1,1e5+10)
	{
		if(frequency[i] == 1)
		{
			++oneCount;
			// one[i] = 1;
			totalOnes.pb(i);
			frequency[i] = 0;
		}
		else if(frequency[i] == 2)
		{
			++twoCount;
			// two[i] = 1;
			totalTwos.pb(i);
			frequency[i] = 0;
		}
	}
	if(oneCount == 1 && twoCount == 1)
	{
		ll extra1 = totalTwos[0];
		ll extra2 = totalOnes[0];
		// ll oneCounter = 0, two
		ll extra3 = totalTwos[0];
		cout << n-1 << '\n';
		rep(i,0,n)
		{
			if(arr[i] == totalTwos[0])
			{
				if(extra2 == -1)
				{
					cout << extra3 << ' ';
				}
				else
				{
					cout << extra2 << ' ';
					extra2 = -1;
				}
			}
			else if(arr[i] == totalOnes[0])
			{
				cout << extra1 << ' ';
			}
		}
		cout << '\n';

	}
	else if(oneCount == 0)
	{
		if(twoCount == 1)
		{
			cout << 0 << '\n';
			cout << totalTwos[0] << ' ' << totalTwos[0] << '\n';
		}
		else
		{
			rep(i,1,twoCount)
			{
				ans[totalTwos[i-1]] = totalTwos[i];
			}
			ans[totalTwos[twoCount - 1]] = totalTwos[0];
			cout << n << '\n';
			rep(i,0,n)
			{
				cout << ans[arr[i]] << ' ';
			}
			cout << '\n';
		}
	}
	else if(twoCount == 0)
	{
		if(oneCount == 1)
		{
			cout << 0 << '\n';
			cout << totalOnes[0] << '\n';
		}
		else
		{
			rep(i,1,oneCount)
			{
				ans[totalOnes[i-1]] = totalOnes[i];
			}
			ans[totalOnes[oneCount-1]] = totalOnes[0];
			cout << n << '\n';
			rep(i,0,n)
			{
				cout << ans[arr[i]] << ' ';
			}
			cout << '\n';
		}
	}
	else if(oneCount == 1)
	{
		rep(i,1,twoCount)
		{
			ans[totalTwos[i-1]] = totalTwos[i];
		}
		ans[totalTwos[twoCount - 1]] = totalTwos[0];
		ll extra1 = ans[totalTwos[0]];
		// ll extra2 = ans[totalTwos[1]];
		ll extra3 = totalOnes[0];
		// ll extra4 = ans[totalTwos[1]];
		// ll extra5 = ans[totalTwos[1]];
		cout << n << '\n';
		ll pos1 = 0;
		ll pos2 = 0;
		rep(i,0,n)
		{
			if(arr[i] == totalOnes[0])
			{
				pos1 = i;
			}
			else if(ans[arr[i]] == extra1)
			{
				pos2 = i;
			}
		}
		rep(i,0,n)
		{
			if(i == pos1)
			{
				cout << extra1 << ' ';
				pos1 = -1;
			}
			else if(i == pos2)
			{
				cout << extra3 << ' ';
				pos2 = -1;
			}
			else
			{
				cout << ans[arr[i]] << ' ';
			}
		}
		cout << '\n';

	}
	else if(twoCount == 1)
	{
		rep(i,1,oneCount)
		{
			ans[totalOnes[i-1]] = totalOnes[i];
		}		
		ans[totalOnes[oneCount - 1]] = totalOnes[0];
		cout << n << '\n';
		ll extra1 = ans[totalOnes[0]];
		ll extra2 = ans[totalOnes[1]];
		ll extra3 = totalTwos[0];
		rep(i,0,n)
		{
			if(arr[i] == totalTwos[0])
			{
				if(extra1 == -1)
				{
					cout << extra2 << ' ';
				}
				else
				{
					cout << extra1 << ' ';
					extra1 = -1;
				}
			}
			else if(arr[i] == totalOnes[0] || arr[i] == totalOnes[1])
			{
				cout << extra3 << ' ';
			}
			else
			{
				cout << ans[arr[i]] << ' ';
			}
		}
		cout << '\n';
	}
	else
	{
		rep(i,1,oneCount)
		{
			ans[totalOnes[i-1]] = totalOnes[i];
		}
		ans[totalOnes[oneCount-1]] = totalOnes[0];
		rep(i,1,twoCount)
		{
			ans[totalTwos[i-1]] = totalTwos[i];
		}
		ans[totalTwos[twoCount - 1]] = totalTwos[0];
		cout << n << '\n';
		rep(i,0,n)
		{
			cout << ans[arr[i]] << ' ';
		}
		cout << '\n';
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
	}
	return 0;
}
