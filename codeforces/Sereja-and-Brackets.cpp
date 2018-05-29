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

struct subset{
	ll o, left, right;
	subset(){
		o = left = right = 0;
	}
};
ll n, q;
const ll MAXN = 1e6 + 100;
vector<subset> segTree(5 * MAXN);
string str;

void getInput()
{
	cin >> str;
	str = '0' + str;
	n = str.length();
}

void build(ll pos, ll l, ll r)
{
	if(r < l)
	{
		return;
	}
	if(l == r)
	{
		if(str[l] == '(')
		{
			segTree[pos].left += 1;
		}
		else
		{
			segTree[pos].right += 1;
		}
		return;
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	build(lptr, l, mid);
	build(rptr, mid + 1, r);
	ll minVal = min(segTree[lptr].left, segTree[rptr].right);
	segTree[pos].o = segTree[lptr].o + segTree[rptr].o + minVal;
	segTree[pos].left = segTree[lptr].left + segTree[rptr].left - minVal;
	segTree[pos].right = segTree[lptr].right + segTree[rptr].right - minVal;
}

subset query(ll pos, ll l, ll r, ll a, ll b)
{
	if(a > r || b < l || r < l)
	{
		subset dummy;
		return dummy;
	}
	if(a <= l && b >= r)
	{
		return segTree[pos];
	}
	ll mid = (l + r)/2;
	ll lptr = 2 * pos;
	ll rptr = lptr + 1;
	subset firstNode = query(lptr, l, mid, a, b);
	subset secondNode = query(rptr, mid + 1, r, a, b);
	subset answer;
	ll minVal = min(firstNode.left, secondNode.right);
	answer.o = firstNode.o + secondNode.o + minVal;
	answer.left = firstNode.left + secondNode.left - minVal;
	answer.right = firstNode.right + secondNode.right - minVal;
	return answer;
}

void getOutput()
{
	ll q;
	cin >> q;
	rep(i,0,q)
	{
		ll l, r;
		cin >> l >> r;
		subset ans = query(1, 1, n, l, r);
		cout << 2 * ans.o << '\n';
	}
}

int main()
{
	fastread;
	getInput();
	build(1, 1, n);
	getOutput();
	return 0;
}