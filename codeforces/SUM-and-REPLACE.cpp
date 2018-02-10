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

struct Node{
	ll sum;
	bool can;
	Node(){
		sum = 0;
		can = false;
	}
	void merge(Node l, Node r){
		sum = l.sum + r.sum;
		can = (l.can) && (r.can) ? true : false;
	}
};

/*-------------------------------------------------------- */
ll n, m;
const ll maxn = 4e5;
const ll maxNumber = 2e6;
vec arr(maxn);
vector<Node> segTree(5*maxn);
vec preCompute(maxNumber+10, 0);
ll prime[maxNumber+10];
void generatePrime()
{
	rep(i,0,maxNumber)
	{
		prime[i] = i;
	}
	for(ll i = 2; i < maxNumber; i += 2)
	{
		prime[i] = 2;
	}
	for(ll i = 3; i <= sqrt(maxNumber); i += 2)
	{
		if(prime[i] == i)
		{
			for(ll j = i * i; j < maxNumber; j += (2*i))
			{
				if(prime[j] == j)
				{
					prime[j] = i;
				}
			}
		}
	}
}

void giveFactorCount()
{
	generatePrime();
	preCompute[1] = 1;
	preCompute[2] = 2;
	preCompute[3] = 2;
	ll t, fact, counter = 0;
	rep(i,4,maxNumber)
	{
		preCompute[i] = 1;
		t = i;
		while(t > 1){
			fact = prime[t];
			counter = 0;
			while(t % fact == 0)
			{
				t /= fact;
				++counter;
			}
			preCompute[i] *= (counter + 1);
		}
	}
}

void build(ll pos, ll l, ll r)
{
	if(l == r)
	{
		segTree[pos].sum = arr[l];
		if(segTree[pos].sum <= 2)
		{
			segTree[pos].can = true;
		}
		return;
	}
	ll mid = (l + r)/2;
	build(2*pos, l, mid);
	build(2*pos+1, mid + 1, r);
	segTree[pos].merge(segTree[2*pos], segTree[2*pos + 1]);
}

void update(ll pos, ll a, ll b, ll l, ll r)
{
	if(l > b || r < a)
	{
		return;
	}
	if(l == r)
	{
		segTree[pos].sum = preCompute[segTree[pos].sum];
		if(segTree[pos].sum <= 2)
		{
			segTree[pos].can = true;
		}
		return;
	}
	if(segTree[pos].can == true)
	{
		return;
	}
	if(a >= l && b <= r)
	{
		if(segTree[pos].can == true)
		{
			return;
		}
	}
	ll mid = (l + r)/2;
	update(2*pos , a, b, l, mid);
	update(2*pos + 1, a, b, mid + 1, r);
	segTree[pos].merge(segTree[2*pos], segTree[2*pos + 1]);
	
}

ll query(ll pos, ll a, ll b, ll l, ll r)
{
	 if(l > b || r < a)
	 {
	 	return 0;
	 }
	 if(l >= a && r <= b)
	 {
	 	return segTree[pos].sum;
	 }
	 ll mid = (l + r)/2;
	 ll ans = query(2*pos, a, b, l, mid);
	 ans += query(2*pos + 1, a, b, mid + 1, r);
	 return ans;
}

int main()
{
	fastread;
	giveFactorCount();
	cin >> n >> m;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	build(1ll, 1ll, n);
	ll cases, l, r;
	while(m--)
	{
		cin >> cases >> l >> r;
		if(cases == 1)
		{
			update(1ll, l, r, 1ll, n);
		}
		else
		{
			cout << query(1ll, l, r, 1ll, n) << '\n';
		}
	}
	return 0;
}