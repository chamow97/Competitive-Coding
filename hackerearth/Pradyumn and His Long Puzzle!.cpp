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
#define vecpair vector< pair< ll, ll > >


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

void dijkstras(vecpair *adj, vec &distance, ll s)
{
    priority_queue< pair<ll, ll>, vecpair, greater< pair<ll, ll> > > min_heap;
    min_heap.push(mp(0,s));
    distance[s] = 0;
    while(!min_heap.empty())
    {
        ll u = min_heap.top().second;
        min_heap.pop();
        vecpair :: iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++)
        {
            ll v = (*i).first;
            ll w = (*i).second;
            if(distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                min_heap.push(mp(distance[v], v));
            }
        }
    }
}

int main()
{
	fastread;
    ll n, m;
    cin>>n>>m;
    vector<string> s;
    rep(i,0,n)
    {
        string dummy;
        cin>>dummy;
        s.pb(dummy);
    }
    vecpair *adj = new vecpair[(n*m)+1];
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            ll current = (n*i)+(j+1);
            if((current-m) > 0)
            {
                adj[current].pb(mp(current-m, abs(s[i][j] - s[i-1][j])));
//                adj[current-m].mp(current, abs(s[i][j] - s[i-1][j]));
            }
            if((current - 1) > (n*i))
            {
                adj[current].pb(mp(current-1, abs(s[i][j] - s[i][j-1])));
//                adj[current-1].mp(current, abs(s[i][j] - s[i][j-1]));
            }
            if((current + 1) < ((n*i)+m+1))
            {
                adj[current].pb(mp(current+1, abs(s[i][j] - s[i][j+1])));
//                adj[current+1].mp(current, abs(s[i][j] - s[i][j+1]));
            }
            if((current + m) <= (n*m))
            {
                adj[current].pb(mp(current+m, abs(s[i][j] - s[i+1][j])));
//                adj[current+m].mp(current, abs(s[i][j] - s[i+1][j]));
            }
        }
    }

    ll s1, s2, d1, d2;
    cin>>s1>>s2>>d1>>d2;
    ll source = (n*(s1-1))+(s2);
    vec distance((n*m)+1, INF);
    ll destination = (n*(d1-1))+d2;
    dijkstras(adj, distance, source);
//    rep(i,1,(m*n)+1)
//    {
//        cout<<adj[i].size()<<" "<<distance[i]<<"\n";
//    }
    cout<<distance[destination];
	return 0;
}
