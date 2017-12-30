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

ll n, m;
char arr[200][200];
string seq;
ll counter = 0;
ll check()
{
	ll brr[] = {0, 1, 2, 3, 
					0, 1, 3, 2, 
					0, 2, 1, 3, 
					0, 2, 3 ,1, 
					0, 3, 1, 2, 
					0, 3, 2, 1, 
					1, 0, 2, 3, 
					1, 0, 3, 2, 
					1, 2, 3, 0, 
					1, 2, 0, 3, 
					1, 3, 2, 0, 
					1, 3, 0, 2, 
					2, 0, 1, 3, 
					2, 0, 3, 1, 
					2, 1, 3, 0, 
					2, 1, 0, 3, 
					2, 3, 1, 0, 
					2, 3, 0, 1, 
					3, 0, 1, 2, 
					3, 0, 2, 1, 
					3, 1, 2, 0, 
					3, 1, 0, 2, 
					3, 2, 1, 0, 
					3, 2, 0, 1};
	ll si = 0, sj = 0, ei = 0, ej = 0;
	
	rep(i,0,24)
	{
		ll now = i*4;
		// cout << now;
		ll m1[100] = {0};
		ll ctr = 0;
		rep(j,now,now+4)
		{
			m1[brr[j]] = ctr++;
		}
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				if(arr[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				if(arr[i][j] == 'E')
				{
					ei = i;
					ej = j;
				}
			}
		}
		
		bool poss = true;
		ll ptr = 0;
		// cout << si << ei << sj << ej;
		while(ptr < seq.length())
		{
			// cout << seq[ptr];
			// cout << m1[seq[ptr]];
			ll val = m1[seq[ptr] - '0'];
			// cout << '\n';
			if(val == 0)
			{
				si--;
			}
			else if(val == 1)
			{
				si++;
			}
			else if(val == 2)
			{
				sj--;
			}
			else if(val == 3)
			{
				sj++;
			}
			ptr++;
			// cout << si << sj << '\n';
			if(si == ei && sj == ej)
			{
				break;
			}
			if(si < 0 || si >= n || sj < 0 || sj >= m || arr[si][sj] == '#')
			{ 	
				poss = false;
				break;
			}
		}
		// cout << si << sj;
		if(poss == true && arr[si][sj] == 'E')
		{
			// cout << now << '\n';
			++counter;
		}

	}
	return counter;
}

int main()
{
	fastread;
	cin >> n >> m;
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	cin >> seq;
	cout << check();
	return 0;
}
