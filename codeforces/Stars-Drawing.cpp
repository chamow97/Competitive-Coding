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

const ll maxn = 1001;
ll n, m;
vector<string> brr(maxn);
vector<string> arr(maxn);

ll up(ll i, ll j)
{
	ll counter = 0;
	i--;
	while(i >= 1 && arr[i][j] == '*')
	{	
		i--;
		++counter;
	}	
	return counter;
}

ll down(ll i, ll j)
{
	ll counter = 0;
	i++;
	while(i <= n && arr[i][j] == '*')
	{	
		i++;
		++counter;
	}	
	return counter;
}

ll left(ll i, ll j)
{
	ll counter = 0;
	j--;
	while(j >= 1 && arr[i][j] == '*')
	{	
		j--;
		++counter;
	}	
	return counter;
}

ll right(ll i, ll j)
{
	ll counter = 0;
	j++;
	while(j <= m && arr[i][j] == '*')
	{	
		j++;
		++counter;
	}	
	return counter;
}

void fillStar(ll i, ll j, ll minimum)
{
	//up
	ll temp = minimum;
	brr[i][j] = '*';
	ll r = i, c = j;
	while(temp--)
	{
		r--;
		brr[r][c] = '*';
	}
	temp = minimum;
	r = i, c = j;
	while(temp--)
	{
		r++;
		brr[r][c] = '*';
	}
	temp = minimum;
	r = i, c = j;
	while(temp--)
	{
		c++;
		brr[r][c] = '*';
	}

	temp = minimum;
	r = i, c = j;
	while(temp--)
	{
		c--;
		brr[r][c] = '*';
	}

}

int main()
{
	vector< pair< pair<ll, ll>, ll> > ans;
	rep(i,0,maxn)
	{
		string str(maxn, '.');
		brr[i] = str;
		arr[i] = str;
	}
	cin >> n >> m;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] = '.' + arr[i];
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(arr[i][j] == '*')
			{
				ll minimum = min(up(i, j), min(down(i, j), min(left(i, j), right(i, j))));
				if(minimum == 0)
				{
					continue;
				}
				fillStar(i, j, minimum);
				ans.pb(mp(mp(i, j), minimum));
			}
		}
	}
	// rep(i,1,n+1)
	// {
	// 	rep(j,1,m+1)
	// 	{
	// 		cout << arr[i][j];
	// 	}
	// 	cout << '\n';
	// }
	// rep(i,1,n+1)
	// {
	// 	rep(j,1,m+1)
	// 	{
	// 		cout << brr[i][j];
	// 	}
	// 	cout << '\n';
	// }
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(arr[i][j] != brr[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i].f.f << ' ' << ans[i].f.s << ' ' << ans[i].s << '\n';
	}
	return 0;
}