//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

//saw the editorial
//learn you creep

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
ll n;
const ll maxn = 4e5;
vec arr(maxn, 0);
vec helper(maxn, 0);
vec ans(maxn, 0);


void solve()
{
	ll ptr = n;
	rep(i,1,n)
	{
		helper[arr[i]] = 1;
		// cout<<ptr<<" ";
		while(helper[ptr] == 1)
		{
			--ptr;
			if(ptr == 0)
			{
				ptr = n;
			}
		}
		// cout<<ptr<<" "<<n<<" "<<i<<'\n';
		ans[i] = i - (n-ptr) + 1;
	}
	cout<<1<<" ";
	rep(i,1,n)
	{
		cout<<ans[i]<<" ";
	}
	cout<<1<<" ";
}
void input()
{
	cin>>n;
	rep(i,1,n+1)
	{
		cin>>arr[i];
	}
	solve();
}

int main()
{
	fastread;
	input();
	return 0;
}
