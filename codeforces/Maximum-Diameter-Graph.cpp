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

bool possible(ll n, ll sum)
{
	ll curr = (2 * n) - 2;
	return (sum >= curr);
}

int main()
{
	fastread;
	ll n;
	ll sum = 0;
	cin >> n;
	vec arr(n + 1);
	rep(i,1,n+1)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	// Worst case we can have n - 2 with 2 degrees and 2 vertices
	// with degree as 1 => 2 * (n - 2) + 2 = 2n - 2
	if(possible(n, sum))
	{
		ll total = 0;
		vecpair ans;
		vec nonProblematicNodes;
		vec problematicNodes;
		rep(i,1,n+1)
		{
			if(arr[i] == 1)
			{
				problematicNodes.pb(i);
			}
			else
			{
				nonProblematicNodes.pb(i);
			}
		}
		rep(i,1,nonProblematicNodes.size())
		{
			++total;
			ans.pb(mp(nonProblematicNodes[i - 1], nonProblematicNodes[i]));
			arr[nonProblematicNodes[i - 1]]--;
			arr[nonProblematicNodes[i]]--;
		}
		ll ptr1 = 0;
		ll ptr2 = nonProblematicNodes.size() - 1;
		total += min(2ll, ll(problematicNodes.size()));
		ll curr = 1;
		rep(i,0,problematicNodes.size())
		{
			if(curr == 1)
			{
				while(ptr1 <= ptr2 && arr[nonProblematicNodes[ptr1]] == 0)
				{
					ptr1++;
				}
				ans.pb(mp(problematicNodes[i], nonProblematicNodes[ptr1]));
				arr[nonProblematicNodes[ptr1]]--;
			}
			else
			{
				while(ptr1 <= ptr2 && arr[nonProblematicNodes[ptr2]] == 0)
				{
					ptr2--;
				}
				ans.pb(mp(problematicNodes[i], nonProblematicNodes[ptr2]));
				arr[nonProblematicNodes[ptr2]]--;
			}
			curr *= (-1);
		}
		sort(ans.begin(), ans.end());
		cout << "YES " << total << '\n';
		cout << ans.size() << '\n';
		for(auto i : ans)
		{
			cout << i.f << ' ' << i.s << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}