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

typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

int main()
{
	fastread;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		map<int, int> m;
		rep(i,0,n)
		{
			int val;
			cin >> val;
			m[val]++;
		}
		vec v;
		long double minimum = INF;
		int fst, scnd = -1;
		for(auto i : m)
		{
			if(i.s >= 2)
			{
				v.pb(i.f);
			}
			if(i.s >= 4)
			{
				minimum = 1;
				fst = scnd = i.f;
			}
		}
		rep(i,1,v.size())
		{
			long double a = v[i];
			long double b = v[i - 1];
			long double now = a / b + b / a;
			if(now < minimum)
			{
				minimum = now;
				fst = a;
				scnd = b;
			}
		}
		cout << fst << ' ' << fst << ' ' << scnd << ' ' << scnd << '\n';

	}
	return 0;
}