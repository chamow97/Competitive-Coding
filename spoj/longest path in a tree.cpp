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

pair<ll, ll> bfs(vec *adj, vec &distance, ll s, ll n)
{
	ll maximum = 0;
	ll pos = -1;
	queue<ll> q;
	q.push(s);
	distance[s] = 0;
	while(!q.empty())
	{
		ll top = q.front();
		q.pop();
		vec :: iterator it;
		for(it = adj[top].begin(); it != adj[top].end(); it++)
		{
			ll v = (*it);
			if(distance[v] == -1)
			{
				q.push(v);
				distance[v] = 1 + distance[top];
			}
		}
	}
	rep(i,0,n)
	{
		if(maximum < distance[i])
		{
			maximum = distance[i];
			pos = i;
		}
	}
	return mp(pos, maximum);
}

int main()
{
	ll n, u, v;
	n = read_int();
	vec distance(n,-1);
	pair<ll, ll> v1, v2;
	vec *adj = new vec[n];
	rep(i, 0, n-1)
	{
		u = read_int();
		v = read_int();
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	v1 = bfs(adj, distance, 0ll, n);
	vec distance1(n, -1);
	v2 = bfs(adj, distance1, v1.first, n);
	cout<<v2.second<<endl;
	
	return 0;
}