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
	ll n, m;
	cin >> n >> m;
	vec arr(n, 0);
	vec brr(m, 0);
	ll haha = 0;
	rep(i,0,n)
	{
		cin >> arr[i];
		haha ^= arr[i];
	}
	rep(i,0,m)
	{
		cin >> brr[i];
		haha ^= brr[i];
	}
	if(haha != 0)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";
		rep(i,1,m)
		{
			haha ^= brr[i];
		}
		haha ^= arr[0];
		cout << haha << ' ';
		rep(i,1,m)
		{
			cout << brr[i] << ' ';
		}
		cout << '\n';
		rep(i,1,n)
		{
			cout << arr[i] << ' ';
			rep(j,1,m)
			{
				cout << 0 << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}