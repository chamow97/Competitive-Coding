
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
typedef vector<pair<ll, ll>> vecpair;

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



int main()
{
    ll n;
    n = read_int();
    vec distance(n,INF);
    vec *adj = new vec[n];
    vec arr(n,0);

    rep(i,0,n)
    {
        arr[i] = read_int();
    }
     rep(i,0,n)
    {
        if(i>0)
        adj[i].pb(i-1);
        if(i<(n-1))
        adj[i].pb(i+1);
        adj[i].pb(arr[i] - 1);
    }
    distance[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty())
    {
        ll top = q.front();
        q.pop();
        vec :: iterator it;
        for(it = adj[top].begin(); it != adj[top].end(); it++)
        {
            if(distance[*it] > distance[top] + 1)
            {
                distance[*it] = distance[top] + 1;
                q.push(*it);
            }
        }
    }
    rep(i,0,n)
    {
        printf("%d ", distance[i]);
    }
	return 0;
}
