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
	ll n, q;
	cin >> n >> q;
	vec arr(n, 0);
	vec temp(n+2, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	while(q--)
	{
		ll l, r;
		cin >> l >> r;
		temp[l]++;
		temp[r+1]--;
	}
	rep(i,1,n+1)
	{
		temp[i] += temp[i-1];
	}
	temp.resize(n+1);
	sort(temp.begin(), temp.end());
	ll sum = 0;
	per(j,n-1,0)
	{
		sum += (temp[j+1] * arr[j]);
	}
	cout << sum;
	return 0;
}