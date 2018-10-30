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
#define INF 100000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second

/*-------------------------------------------------------- */

typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

const int MAXN = 2001;
int maze[MAXN][MAXN];

void bfs(int x, int y)
{
	queue< pair<int, int> > q;
	q.push(mp(x, y));
	while(!q.empty())
	{
		pair<int, int> now = q.front();
		int x1 = now.f;
		int y1 = now.s;
		q.pop();
		int pos[] = {-1, 0, 1};
		rep(i,0,3)
		{
			rep(j,0,3)
			{
				if(x1 - pos[i] < 0 || x1 - pos[i] > 2000)
				{
					continue;
				}
				if(y1 - pos[j] < 0 || y1 - pos[j] > 2000)
				{
					continue;
				}
				if(abs(pos[i]) + abs(pos[j]) == 2)
				{
					continue;
				}
				if(maze[x1 - pos[i]][y1 - pos[j]] > maze[x1][y1] + 1)
				{
					maze[x1 - pos[i]][y1 - pos[j]] = maze[x1][y1] + 1;
					q.push(mp(x1 - pos[i], y1 - pos[j]));
				}
			}
		}
	}
}

int main()
{
	fastread;
	int n, m;
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	rep(i,0,n+1)
	{
		rep(j,0,m+1)
		{
			maze[i][j] = 100000000;
		}
	}
	int k;
	cin >> k;
	while(k--)
	{
		int x, y;
		cin >> x >> y;
		maze[x][y] = 0;
		bfs(x, y);
	}
	int maximum = 0;
	pair<int, int> lastPoint;
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(maze[i][j] >= maximum)
			{
				maximum = maze[i][j];
				lastPoint = mp(i, j);
			}
		}
	}
	cout << lastPoint.f << ' ' << lastPoint.s;
	return 0;
}