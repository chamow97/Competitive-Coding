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

int main()
{
	fastread;
	ll n;
	ll ans = 0;
	cin >> n;
	vec arr(n,0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	boolean visited(n,false);
	ll length = 0;
	while(length < n)
	{
		ll possible = 0;
		rep(i,0,n)
		{
			if(arr[i] >= possible && visited[i] == false)
			{
				visited[i] = true;
				++possible;
				++length;
			}
		}
		++ans;
	}
	cout << ans;
	return 0;
}
