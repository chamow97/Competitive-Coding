
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
ll parent[int(1e5 + 10)];
ll rankOfNode[int(1e5 + 10)];
void initialize()
{
    rep(i,0,1e5+10)
    {
        parent[i] = i;
    }
}
int find(ll val)
{
    if(parent[val] != val)
    {
        return find(parent[val]);
    }
    return parent[val];
}
int main()
{
	fastread;
    ll n, q;
    cin>>n>>q;
    initialize();
    while(q--)
    {
        ll x, y, cases;
        cin>>cases;
        if(cases == 1)
        {
            cin>>x>>y;
        }
        else
        {
            cin>>x;
        }
        switch(cases){
        case 1:
            {
                int x1 = find(x);
                int y1 = find(y);
                parent[x1] = y1;
                break;
            }

        case 2:{
            ll u = find(x);
            parent[x] = x;
            parent[u] = x;
            break;
        }
        case 3:
            cout<<find(x)<<'\n';
            break;
        }
    }
    return 0;
}
