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

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, m;
		cin>>n>>m;
		vec minSal(n,0);
		rep(i,0,n)
		{
			cin>>minSal[i];
		}
		vector< pair<ll, ll> > v;
		rep(i,0,m)
		{
			ll a, b;
			cin>>a>>b;
			v.pb(mp(a,b));
		}
		ll totalSal = 0;
		boolean candidate(n+10,false);
		boolean company(m+10,false);
		char allowed[n+10][m+10];
		rep(i,0,n)
		{
			cin>>allowed[i];
		}
		rep(i,0,n)
		{
			ll maximum = minSal[i], pos = -1;
			rep(j,0,m)
			{
				if(allowed[i][j] == '1')
				{
					if(v[j].first >= maximum && v[j].second > 0)
					{
						maximum = v[j].first;
						pos = j;
					}
				}
			}
			if(pos != -1)
			{
				v[pos].second--;
				company[pos] = true;
				candidate[i] = true;
				totalSal += maximum;
			}
		}
		ll totalCandidates = 0;
		ll totalCompanies = 0;
		rep(i,0,n)
		{
			if(candidate[i] == true)
			{
				++totalCandidates;
			}
		}
		rep(i,0,m)
		{
			if(company[i] == false)
			{
				++totalCompanies;
			}
		}
		cout<<totalCandidates<<" "<<totalSal<<" "<<totalCompanies<<'\n';
	}
	return 0;
}