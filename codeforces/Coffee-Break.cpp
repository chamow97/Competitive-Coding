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
	ll n, m1, d;
	cin >> n >> m1 >> d;
	set<ll> s;
	map<int, int> m;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		s.insert(val);
		m[val] = i;
	}
	vec answer(n, 0);
	ll counter = 0;
	ll now = 1;
	while(counter < n)
	{
		auto ptr = s.begin();
		while(ptr != s.end())
		{
			ll curr = *ptr;
			answer[m[curr]] = now;
			++counter;
			auto temp = s.lower_bound(curr + d + 1);
			s.erase(ptr);
			ptr = temp;
		}
		++now;
	}
	cout << now - 1 << '\n';
	rep(i,0,n)
	{
		cout << answer[i] << ' ';
	}
	return 0;

}