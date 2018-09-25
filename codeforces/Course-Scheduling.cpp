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
	map<string, set<string> > m;
	map<string, ll> m1;
	rep(i,0,n)
	{
		string fName, lName;
		cin >> fName >> lName;
		string course;
		cin >> course;
		string fullName = fName + " " + lName;
		if(m[fullName].find(course) != m[fullName].end())
		{
			continue;
		}
		m[fullName].insert(course);
		m1[course]++;
	} 
	vector< pair<string, ll> > p;
	for(map<string,ll>::iterator it=m1.begin(); it!=m1.end(); ++it)
	{
		p.pb(mp(it -> first, it -> second));
	}
	sort(p.begin(), p.end());
	for(auto i : p)
	{
		cout << i.f << ' ' << i.s << '\n';
	}
	return 0;
}