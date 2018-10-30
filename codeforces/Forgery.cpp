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

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	ll sharp = 0;
	vector<string> str(n);
	rep(i,0,n)
	{
		cin >> str[i];
	}
	bool visited[n][m];
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			visited[i][j] = false;
		}
	}
	ll dx[] = {-1, 0, 1};
	ll dy[] = {-1, 0, 1};

	rep(i,0,n - 1)
	{
		rep(j,0,m - 1)
		{
			bool possible = true;
			rep(k,0,3)
			{
				rep(l,0,3)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[l];
					if(nx < 0 || ny < 0 || nx >= n || ny >= m)
					{
						possible = false;
						break;
					}
					if(nx == i && ny == j)
					{
						continue;
					}
					possible &= (str[nx][ny] == '#');

				}
			}
			if(possible)
			{
				rep(k,0,3)
				{
					rep(l,0,3)
					{
						ll nx = i + dx[k];
						ll ny = j + dy[l];
						if(nx == i && ny == j)
						{
							continue;
						}
						visited[nx][ny] = true;

					}
				}	
			}
		}
	}
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(str[i][j] == '#' && !visited[i][j])
			{
				cout << "NO";
				return 0;	
			}
		}
	}
	cout << "YES";	
	return 0;
}