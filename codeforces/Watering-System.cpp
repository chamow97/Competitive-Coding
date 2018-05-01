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
	ll n, a, b;
	cin >> n >> a >> b;
	ll firstHole;
	cin >> firstHole;
	ll totalSize = 0;
	vec arr(n-1, 0);
	rep(i,0,n-1)
	{
		cin >> arr[i];
		totalSize += arr[i];
	}
	totalSize += firstHole;
	float possible = (1.00 * firstHole * a)/(1.00 * totalSize);
	ll blocked = 0;
	sort(arr.begin(), arr.end(), greater<ll>());
	rep(i,0,n-1)
	{
		if(possible >= b)
		{
			break;
		}
		totalSize -= arr[i];
		possible = (1.00 * firstHole * a)/(1.00 * totalSize);
		++blocked;
	}
	cout << blocked;
	return 0;
}
