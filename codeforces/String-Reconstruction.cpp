//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb emplace_back
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

typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */


char answer[2000008];
vector< pair<int, int> > ms;
int main()
{
	fastread;
	int n;
	cin >> n;
	rep(i,0,2000008)
	{
		answer[i] = '?';
	}
	int maximum = 0;
	vector < string > nowS;
	rep(i,0,n)
	{
		string str;
		cin >> str;
		nowS.pb(str);
		int len;
		cin >> len;
		rep(j,0,len)
		{
			int val;
			cin >> val;
			maximum = max(maximum, int(val + str.length()));
			ms.pb(mp(val, i));
		}
	}
	sort(ms.begin(), ms.end());
	int now = 1;
	for(auto it : ms)
	{
		auto top = it;
		int pos = top.f;
		int extra = now - pos;
		extra = max(extra, 0);
		int ptr = pos + extra;
		rep(i,extra,nowS[top.s].length())
		{
			answer[ptr++] = nowS[top.s][i];
		}
		now = max(int(pos + nowS[top.s].length()), now);
		// cout << val << ' ' << now << '\n';
	}
	rep(i,1,maximum)
	{
		if(answer[i] != '?')
		{
			cout << answer[i];
		}
		else
		{
			cout << 'a';
		}
	}
	return 0;
}