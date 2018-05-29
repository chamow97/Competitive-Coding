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

int main()
{
	fastread;
	ll n;
	cin >> n;
	map<ll, ll> m;
	vector<string> arr(n);
	set<string> s;
	rep(i,0,n)
	{
		cin >> arr[i];
		string now = arr[i];
		vec freq(30, 0);
		rep(j,0,now.length())
		{
			freq[now[j] - 'a']++;
		}
		string newS = "";
		rep(j,0,26)
		{
			if(freq[j] >= 1)
			{
				newS += char(j + 'a');
			}
		}
		s.insert(newS);
	}
	cout << s.size();
	return 0;
}