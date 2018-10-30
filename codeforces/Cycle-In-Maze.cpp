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
ll dist[1010][1010];
ll dy[] = {0, -1, 1, 0};
ll dx[] = {1, 0, 0, -1};
string move = "DLRU";


void printImpossible()
{
	cout << "IMPOSSIBLE";
}

int main()
{
	fastread;
	string answer = "";
	cin >> n >> m >> k;
	memset(dist, -1, sizeof(dist));
	if(k % 2 != 0)
	{
		printImpossible();
		return 0;
	}
	rep(i,0,n)
	{
		cin >> maze[i];
	}
	ll X, Y;
	rep(i,0,n)
	{
		rep(j,0,m)
		{
			if(maze[i][j] == 'X')
			{
				maze[i][j] = '.';
				X = i;
				Y = j;
			}
		}
	}
	dist[X][Y] = 0;
	//BFS
	queue< pair<ll, ll> > q;
	q.push(mp(X, Y));
	while(!q.empty())
	{
		auto now = q.front();
		q.pop();
		ll x = now.f;
		ll y = now.s;
		rep(i,0,4)
		{
			ll xd = x + dx[i];
			ll yd = y + dy[i];
			if(xd >= 0 && yd >= 0 && xd < n && yd < m && maze[xd][yd] != '*' && dist[xd][yd] == -1)
			{
				dist[xd][yd] = dist[x][y] + 1;
				q.push(mp(xd, yd));
			}
		}
	}
	//Print Path if exists
	rep(i,0,k)
	{
		bool possible = false;
		rep(j,0,4)
		{
			ll xd = X + dx[j];
			ll yd = Y + dy[j];
			if(xd >= 0 && yd >= 0 && xd < n && yd < m && maze[xd][yd] != '*' && dist[xd][yd] + 1 + i <= k)
			{
				X += dx[j];
				Y += dy[j];
				possible = true;
				answer += "DLRU"[j];
				break;
			}
		}
		if(!possible)
		{
			printImpossible();
			return 0;
		}
	}
	cout << answer;
	return 0;
}