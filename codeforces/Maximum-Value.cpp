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

const int maxn = 1e6 + 10;

int main()
{
	fastread;
	int n;
	cin >> n;
	set<int> s;
	vec arr;
	rep(i,0,n)
	{
		int val;
		cin >> val;
		s.insert(val);
	}
	for(auto i : s)
	{
		arr.pb(i);
	}
	n = arr.size();
	int maximum = 0;
	rep(i,0,n)
	{
		int curr = arr[i];
		curr += arr[i];
		while(1)
		{
			int pos = lower_bound(arr.begin(), arr.end(), curr) - arr.begin();
			--pos;
			if(pos >= 0 && arr[pos] > arr[i])
			{
				maximum = max(maximum, arr[pos] % arr[i]);
			}
			if(curr > arr[n-1])
			{
				break;
			}
			curr += arr[i];
		}
	}
	cout << maximum;
	return 0;
}