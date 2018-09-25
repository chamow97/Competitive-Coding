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
	fastread
	ll n;
	cin >> n;
	map<string, ll> m;
	m["A"] = INF;
	m["B"] = INF;
	m["C"] = INF;
	m["AB"] = INF;
	m["BC"] = INF;
	m["ABC"] = INF;
	m["AC"] = INF;
	rep(i,0,n)
	{
		ll val;
		string str;
		cin >> val >> str;
		sort(str.begin(), str.end());
		m[str] = min(m[str], val);
	}
	ll ans = INF;
	if(m["ABC"] != 0)
	{
		ans = min(ans, m["ABC"]);
	}
	if(m["A"] != 0 && m["B"] != 0 && m["C"] != 0)
	{
		ans = min(ans, m["A"] + m["B"] + m["C"]);
	}
	string str1[] = {"A", "B", "C", "AB", "BC", "AC", "ABC"};
	rep(i,0,7)
	{
		rep(j,i+1,7)
		{
			string now = str1[i] + str1[j];
			set<char> s;
			rep(k,0,now.length())
			{
				s.insert(now[k]);
			}
			string now1 = "";
			for(auto it : s)
			{
				now1 += it;
			}
			if(now1 == "ABC" && m[str1[i]] != 0 && m[str1[j]] != 0)
			{
				ans = min(ans, m[str1[i]] + m[str1[j]]);
			}
		}
	}
	if(ans >= INF)
	{
		ans = -1;
	}
	cout << ans;
	return 0;
}