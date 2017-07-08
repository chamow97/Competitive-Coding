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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
	char maze[101][101];
	rep(i,0,10)
	{
		cin>>maze[i];
	}
	rep(i,0,10)
	{
		rep(j,0,10)
		{
			if(maze[i][j] == '.')
			{
				ll left = 0, right = 0, top = 0, down = 0, ld = 0, rd = 0, td = 0, dd = 0;
				ll ptr = j-1;
				while(ptr >= 0 && maze[i][ptr] == 'X')
				{
					--ptr;
					++left;
				}
				ptr = j+1;
				while(ptr < 10 && maze[i][ptr] == 'X')
				{
					++ptr;
					++right;
				}
				ptr = i-1;
				while(ptr >= 0 && maze[ptr][j] == 'X')
				{
					--ptr;
					++top;
				}
				ptr = i+1;
				while(ptr < 10 && maze[ptr][j] == 'X')
				{
					++ptr;
					++down;
				}
				ll ptr1 = i-1, ptr2 = j-1;
				while(ptr1 >= 0 && ptr2 >= 0 && maze[ptr1][ptr2] == 'X')
 				{
					ld++;
					ptr1--;
					ptr2--;
				}
				ptr1 = i+1; ptr2 = j+1;
				while(ptr1 < 10  && ptr2 < 10 && maze[ptr1][ptr2] == 'X')
				{
					rd++;
					ptr1++;
					ptr2++;
				}
				ptr1 = i-1;
				ptr2 = j+1;
				while(ptr1 >= 0 && ptr2 < 10 && maze[ptr1][ptr2] == 'X')
				{
					td++;
					ptr1--;
					ptr2++;
				}
				ptr1 = i+1;
				ptr2 = j-1;
				while(ptr1 < 10 && ptr2 >= 0 && maze[ptr1][ptr2] == 'X')
				{
					dd++;
					ptr1++;
					ptr2--;
				}
				if((left + right ) >= 4 || (top + down) >= 4 || (ld + rd) >= 4 || (td + dd) >= 4)
				{
					cout<<"YES";
					return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}