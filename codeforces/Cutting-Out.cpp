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

vecpair lst;
ll maxi = 0;
int n, k;
vec ans;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	return p1.f > p2.f;
}

void binarySearch(ll low, ll high)
{
	if(low > high)
	{
		return;
	}
	ll mid = (low + high) / 2;
	ll now = 0;
	for(auto i : lst)
	{
		now += (i.f / mid);
	}
	if(now < k)
	{
		high = mid - 1;
	}
	else
	{
		maxi = mid;
		low = mid + 1;
	}
	binarySearch(low, high);
}

void generateAns()
{
	ll curr = k;
	for(auto i : lst)
	{
		ll now = min(curr, i.f / maxi);
		curr -= now;
		rep(j,0,now)
		{
			ans.pb(i.s);
		}
	}
}

int main()
{
	fastread;
	map<int, int> m;
	cin >> n >> k;
	vector<int> arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}
	for(auto i : m)
	{
		lst.pb(mp(i.s, i.f));
	}
	sort(lst.begin(), lst.end(), cmp);
	ll low = 1, high = n / k;
	binarySearch(low, high);
	generateAns();
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}