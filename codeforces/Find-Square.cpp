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
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n+1);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	pair<int, int> ptr;
	bool found = false;
	rep(i,0,n)
	{
		if(found)
		{
			break;
		}
		rep(j,0,m)
		{
			if(arr[i][j] == 'B')
			{
				ptr = mp(i, j);
				found = true;
				break;
			}
		}
	}
	ll i = ptr.f;
	ll j = ptr.s;
	ll counter  = 0;
	while(arr[i][j] == 'B' && i < n && j < m)
	{
		counter++;
		i++;
		j++;
	}
	counter /= 2;
	cout << ptr.f + counter + 1 << ' ' << ptr.s + counter + 1;
	return 0;
}
