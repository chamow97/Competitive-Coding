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

int main()
{
	fastread;
	char str[100][100];
	rep(i,0,8)
	{
		cin >> str[i];
	}
	ll white = 0;
	ll black = 0;
	rep(i,0,8)
	{
		rep(j,0,8)
		{
			if(str[i][j] >= 'a' && str[i][j] <= 'z')
			{
				if(str[i][j] == 'q')
				{
					black += 9;
				}
				if(str[i][j] == 'r')
				{
					black += 5;
				}
				if(str[i][j] == 'b')
				{
					black += 3;
				}
				if(str[i][j] == 'n')
				{
					black += 3;
				}
				if(str[i][j] == 'p')
				{
					black += 1;
				}
			}
			if(str[i][j] >= 'A' && str[i][j] <= 'Z')
			{
				if(str[i][j] == 'Q')
				{
					white += 9;
				}
				if(str[i][j] == 'R')
				{
					white += 5;
				}
				if(str[i][j] == 'B')
				{
					white += 3;
				}
				if(str[i][j] == 'N')
				{
					white += 3;
				}
				if(str[i][j] == 'P')
				{
					white += 1;
				}
			}
		}
	}
	if(white > black)
	{
		cout << "White";
	}
	else if(black > white)
	{
		cout << "Black";
	}
	else
	{
		cout << "Draw";
	}
	return 0;
}