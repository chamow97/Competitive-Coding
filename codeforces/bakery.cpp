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
#define vecpair vector<pair<ll, ll>>
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

int main()
{
    ll n, m, k, u, v, w;
    ll minimum = INF;
    n = read_int();
    m = read_int();
    k = read_int();
    vec arr(k,0);
    ll adj[m+1][3];
    if(k == 0)
    {
        cout<<-1;
        return 0;
    }
    rep(i,0,m)
    {
        adj[i][0] = read_int();
        adj[i][1] = read_int();
        adj[i][2] = read_int();
    }
    rep(i,0,k)
    {
        arr[i] = read_int();
    }
    sort(arr.begin(), arr.end());
    rep(i,0,m)
    {
        bool a = binary_search(arr.begin(), arr.end(), adj[i][0]);

        bool b = binary_search(arr.begin(), arr.end(), adj[i][1]);
        ll val = (a^b);
        if(val == 1)
        {
            minimum = min(minimum, adj[i][2]);
        }
    }
    if(minimum == INF)
    {
        cout<<-1;
        return 0;
    }
    cout<<minimum;
	return 0;
}
