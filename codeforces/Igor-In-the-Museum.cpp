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

ll n, m, k;
char maze[1010][1010];
bool visited[1010][1010];
ll ans[1010][1010];

ll dx[] = {-1, 0, 1};
ll dy[] = {-1, 0, 1};
ll curr = 0;
ll comp = 0;

void processMaze(ll x, ll y, ll comp)
{
	visited[x][y] = true;
	rep(i,0,3)
	{
		rep(j,0,3)
		{
			ll rx = x + dx[i];
			ll ry = y + dy[j];
			if(abs(dx[i]) == abs(dy[j]))
			{
				continue;
			}
			if(rx <= n && rx >= 1 && ry <= m && ry >= 1)
			{	
				if(maze[rx][ry] == '.' && !visited[rx][ry])
				{
					processMaze(rx, ry, comp);
				}
				else if(maze[rx][ry] == '*' && !visited[rx][ry])
				{
					++curr;
				}
			}
		}
	}
	ans[x][y] = comp;
}

int main()
{
	fastread;
	cin >> n >> m >> k;
	map< ll, ll > answer;
	rep(i,1,n+1)
	{
		cin >> maze[i] + 1;
	}
	memset(visited, false, sizeof(visited));
	memset(ans, 0, sizeof(ans));
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(!visited[i][j] && maze[i][j] == '.')
			{
				curr = 0;
				++comp;
				processMaze(i, j, comp);
				answer[comp] = curr;
			}
		}
	}
	// rep(i,1,n+1)
	// {
	// 	rep(j,1,m+1)
	// 	{
	// 		cout << maze[i][j];
	// 	}
	// 	cout << '\n';
	// }
	// rep(i,1,n+1)
	// {
	// 	rep(j,1,m+1)
	// 	{
	// 		cout << ans[i][j];
	// 	}
	// 	cout << '\n';

	// }
	while(k--)
	{
		ll x, y;
		cin >> x >> y;
		cout << answer[ans[x][y]] << '\n';
	}
	return 0;
}