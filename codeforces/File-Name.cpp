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
	string str;
	cin >> str;
	ll tempCtr = 0, ans = 0;
	rep(i,2,n)
	{
		if(str[i] == 'x')
		{
			if(str[i-1] == 'x' && str[i-2] == 'x')
			{
				tempCtr++;	
			}
		}
		else
		{
			ans += tempCtr;
			tempCtr = 0;
		}
	}
	ans += tempCtr;
	cout << ans;

	return 0;
}