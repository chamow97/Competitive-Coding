//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readll () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
    
bool visited[150001];
void dfs(ll s, ll &verticesCount, ll &edgesCount, vector<ll> *arr)
{
	verticesCount += (1);
	edgesCount += (arr[s].size());
	visited[s] = true;
	//cout<<s<<" ";
	vector<ll>::iterator i;
	for(i = arr[s].begin(); i != arr[s].end(); i++)
	{
		if(!visited[*i])
		{
			dfs(*i, verticesCount, edgesCount, arr);
		}
	}
}
int main()
{
	ll n,m,u,v;
	n = readll();
	m = readll();
	vector<ll> *arr = new vector<ll>[n];

	rep(i,0,m)
    {
    	u = readll();
    	v = readll();
    	u -= 1;
    	v -= 1;
    	arr[u].pb(v);
    	arr[v].pb(u);
    }
    rep(i,0,n)
    {
    	if(!visited[i])
    	{
    		ll verticesCount = 0, edgesCount = 0;
	
    		dfs(i, verticesCount, edgesCount, arr);

    		if(edgesCount != (verticesCount*(verticesCount - 1)))
    		{
    			printf("NO");
    			return 0;
    		}
    	}
    }    
    printf("YES");

    return 0;
}