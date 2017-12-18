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
const ll maxn = 2e6+200;
ll n, m, k, l, r;
vector<ll> arr(maxn, 0);
vector<ll> segTree(5*maxn, 0);
void constructTree(ll low, ll high, ll position)
{
	if(low == high)
	{
		segTree[position] = arr[low];
	}
	else
	{
		ll mid = (low + high)/2;
		constructTree(low, mid, (2*position));
		constructTree(mid+1, high, (2*position)+1);
		segTree[position] = (segTree[(2*position)] + segTree[(2*position)+1]);
	}
}

ll query(ll a, ll b, ll current)
{
    if(a > b)
    {
        return 0;
    }
    if(a > r || b < l)
    {
        return 0;
    }
    if(a >= l && b <= r)
    {
        return segTree[current];
    }
    ll mid = (a+b)/2;
    return query(a, mid, (2*current)) + query(mid+1, b, (2*current)+1);
}

void update(ll a, ll b, ll current, ll pos)
{
	if(a > pos || b < pos)
	{
		return;
	}
	if(a >= pos && b <= pos)
	{
		segTree[current] = 0;
		return;
	}
	ll mid = (a + b)/2;
	update(a, mid, 2*current, pos);
	update(mid + 1, b, 2*current + 1, pos);
	segTree[current] = segTree[2*current] + segTree[2*current + 1];
}

int main()
{
	fastread;
	//thx to murugappan_s for the logic 
	//pro level thinking /m\
	
	cin >> n >> m >> k;
	vec ip;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		ip.pb(val);
		arr[val] = 1;
	}
	sort(ip.begin(), ip.end());
	constructTree(1, 2e6+1, 1);
	ll ans = 0;
	rep(i,0,n)
	{
		if(arr[ip[i]] == 0)
		{
			continue;
		}
		l = ip[i];
		r = l + m - 1;
		int curr = query(1, 2e6+1, 1);
		// cout << curr;
		if(curr < k)
		{
			continue;
		}
		curr -= (k-1);
		ans += curr;

		ll posi = upper_bound(ip.begin(), ip.end(), r) - ip.begin();
		per(j,posi-1, posi - curr)
		{
			arr[ip[j]] = 1;
			update(1, 2e6+1, 1, ip[j]);
		}

	}
	cout << ans;
	return 0;
}
