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

char arr[510][510];
bool visited[510][510];
int n, m;
int r1, c1, r2, c2;
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};
bool possible = false;
int counter = 0;

void dfs(int u, int v)
{
	++counter;
	// cout << u << ' ' << v << '\n';	
	if(u == r2 && v == c2 && arr[u][v] == 'X' && counter > 1)
	{
		possible = true;
		return;
	}
	arr[u][v] = 'X';
	visited[u][v] = true;
	rep(i,0,3)
	{
		rep(j,0,3)
		{
			if(abs(dx[i]) + abs(dy[j]) == 1)
			{
				int rx = u + dx[i];
				int ry = v + dy[j];
				if(rx == r2 && ry == c2 && arr[rx][ry] == 'X')
				{
					dfs(rx, ry);
				}
				if(rx >= 1 && rx <= n && ry >= 1 && ry <= m && visited[rx][ry] == false && arr[rx][ry] == '.')
				{
					dfs(rx, ry);
				}
			}
		}
	}
}

int main()
{
	fastread;
	cin >> n >> m;
	memset(visited, false, sizeof visited);
	rep(i,1,n+1)
	{
		cin >> 1 + arr[i];
	}
	cin >> r1 >> c1 >> r2 >> c2;
	if(r1 == r2 && c1 == c2)
	{
		rep(i,0,3)
		{
			rep(j,0,3)
			{
				if(abs(dx[i]) + abs(dy[j]) == 1)
				{
					int rx = r1 + dx[i];
					int ry = c1 + dy[j];
					if(rx >= 1 && rx <= n && ry >= 1 && ry <= m && arr[rx][ry] == '.')
					{
						cout << "YES";
						return 0;
					}
				}
			}
		}
		cout << "NO";
		return 0;
	}
	dfs(r1, c1);
	if(!possible)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	return 0;
}