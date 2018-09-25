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
	ll total = (n * (n + 1))/2;
	rep(i,1,n+1)
	{
		ll a = i;
		ll b = total - a;
		if(__gcd(a, b) > 1)
		{
			cout << "Yes\n";
			cout << 1 << ' ' << i << '\n';
			cout << n - 1 << ' ';
			rep(j,1,n+1)
			{
				if(j != i)
				{
					cout << j << ' ';
				}
			}
			return 0;
		}
	}
	cout << "No";
	return 0;
}