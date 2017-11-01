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

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		set<ll> arr;
		ll maximum = 0;
		rep(i,0,n)
		{
			ll temp;
			cin>>temp;
			arr.insert(temp);
		}
		ll ptr = 0;
		set<ll> :: iterator it;
		it = arr.begin();
		bool isFound = false;
		rep(i,0,2e5+1)
		{
			if(it == arr.end())
			{
				break;
			}
			if(k < 0)
			{
				cout<<i-1<<"\n";
				isFound = true;
				break;
			}
			if(*it != i)
			{
				--k;
			}
			else
			{
				it++;
			}
		}		
		if(!isFound)
		{
			--it;
			cout<<*(it)+k+1<<'\n';
		}
	}
	return 0;

}
