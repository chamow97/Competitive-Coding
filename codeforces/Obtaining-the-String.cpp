//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	ll n;
	cin >> n;
	string s, t;
	vec ans;
	cin >> s >> t;
	map<ll, ll> m1, m2;
	rep(i,0,n)
	{
		m1[s[i] - 'a']++;
	}
	rep(i,0,n)
	{
		m2[t[i] - 'a']++;
	}
	rep(i,0,26)
	{
		if(m1[i] != m2[i])
		{
			cout << -1;
			return 0;
		}
	}
	rep(i,0,n)
	{
		rep(j,i,n)
		{
			if(t[i] == s[j])
			{
				per(k,j - 1,i)
				{
					ans.pb(k);
					swap(s[k], s[k+1]);
				}
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i] + 1 << ' ';
	}
	return 0;
}