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
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


/*-------------------------------------------------------- */

set<ll> min_heap;
set<ll, greater<ll> > max_heap;



int main()
{
	fastread
	ll n;
	cin >> n;
	vecpair arr(n);
	map<ll, ll> lMap;
	map<ll, ll> gMap;
	rep(i,0,n)
	{
		cin >> arr[i].f >> arr[i].s;
		min_heap.insert(arr[i].s);
		max_heap.insert(arr[i].f);
		lMap[arr[i].f]++;
		gMap[arr[i].s]++;
	}
	ll maximum = 0;
	rep(i,0,n)
	{
		ll u = arr[i].f;
		ll v = arr[i].s;
		ll minE = INF;
		ll maxE = 0;
		bool isMax = false;
		bool isMin = true;
		if(lMap[u] == 1)
		{
			max_heap.erase(max_heap.find(u));
			maxE = *max_heap.begin();
			isMax = true;
		}
		else
		{
			maxE = *max_heap.begin();
		}
		if(gMap[v] == 1)
		{
			min_heap.erase(min_heap.find(v));
			minE = *min_heap.begin();
			isMin = true;
		}
		else
		{
			minE = *min_heap.begin();
		}
		if(maxE < minE)
		maximum = max(maximum, abs(minE - maxE));
		if(isMax)
		{	
			max_heap.insert(u);
		}
		if(isMin)
		{
			min_heap.insert(v);
		}
	}
	cout << maximum;
	return 0;
}