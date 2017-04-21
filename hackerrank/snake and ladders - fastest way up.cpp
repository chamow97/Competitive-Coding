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
#define vecpair vector< pair<ll, ll> >
#define INF 10000000000000

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

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
/*-------------------------------------------------------- */

void dijkstras(vecpair *adj, vec &distance, ll s)
{
	distance[s] = 0;
	priority_queue< pair<ll, ll>, vecpair,  greater< pair<ll, ll> > > h;
	h.push(mp(0,s));
	while(!h.empty())
	{
		ll u = h.top().second;
		h.pop();
		vecpair :: iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++)
		{
			ll v = (*it).first;
			ll w = (*it).second;
			if(distance[v] > distance[u] + w)
			{
				distance[v] = distance[u] + w;
				h.push(mp(distance[v], v));
			}
		}
	}
}

int main()
{
	ll t, n, m, u, v;
	t = read_int();
	while(t--)
	{
		vecpair *adj = new vecpair[110];
		vec distance(110, INF);
		boolean visited(110, false);
		n = read_int();
		rep(i,0,n)
		{
			u = read_int();
			v = read_int();
			visited[u] = true;
			adj[u].pb(mp(v,0ll));
		}
		m = read_int();
		rep(i,0,m)
		{
			u = read_int();
			v = read_int();
			visited[u] = true;
			adj[u].pb(mp(v,0ll));
		}
		ll i,j;
		for(i = 1; i <= 99; i++)
		{ 
				if(visited[i] == false)
				{
					for(j = i + 1; j <= i + 6; j++)
					{
						if(j <= 100)
							adj[i].pb(mp(j,1ll));
					}
				}			
				visited[i] = true;
			
		}
		// rep(i,1,101)
		// {
		// 	vecpair :: iterator it;
		// 	cout<<i<<" : ";
		// 	for(it = adj[i].begin(); it != adj[i].end(); it++)
		// 	{
		// 		cout<<(*it).first<<" ";
		// 	}
		// 	cout<<endl;
		// }
		dijkstras(adj, distance, 1ll);
		// rep(i,1,101)
		if(distance[100] == INF)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<distance[100]<<"\n";
		}
		

	}
	return 0;
}