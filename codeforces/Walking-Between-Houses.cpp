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
	ll n, k, s;
	cin >> n >> k >> s;
	if(s < k || s > ((n - 1) * k))
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	ll now = 1;
	ll sign = 1;
	ll quo, rem = 1;
	while(s > 0)
	{
		quo = s / k;
		if(s % k != 0)
		{
			quo++;
		}
		rem = rem + (quo * sign);
		cout << rem << ' ';
		sign *= (-1);
		s -= quo;
		k--;
	}
	return 0;
}