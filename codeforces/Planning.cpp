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

bool myFunc(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
	if(p1.first == p2.first)
	{
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}
//saw editorial
int main()
{
	fastread;
	ll n, k;
	cin>>n>>k;
	vec arr(n,0);
	ll cost = 0;
	priority_queue< pair<ll, ll> > p;
	--k;
	rep(i,0,n)
	{
		cin>>arr[i];
	}
	vec ans(n+1,0);
	for(ll i = 0; i < n || !(p.empty()); i++)
	{

		if(i < n)
		{
			p.push(mp(arr[i], i));
		}
		if(i > k)
		{
			pair<ll, ll> front = p.top();
			p.pop();
			cost += ((front.first)*(i - front.second));
			ans[front.second] = i+1;
		}
		
	}
	cout<<cost<<'\n';
	rep(i,0,n)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}