//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
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
ll noOfWays = 0, counter = 0,b[100000];
ll n,m,temp,u,w;
	bool a[100001],visited[100001];
	vector<int> *v;
void dfs(ll s)
{
    counter = 0;
	visited[s] = true;
	if(b[s] > m)
    {
        return;
    }
	//cout<<s+1;
	vector<int>::iterator it;
	for(it = v[s].begin(); it!=v[s].end(); it++)
		{
			if(visited[*it] == true)
			{
			    continue;
			}
				b[*it] = 1+b[s];
                if(a[*it] == 0)
                {
                    b[*it] = 0;
                }
				dfs(*it);
				counter++;
		}
		if(counter == 0)
		noOfWays++;
}
int main()
{

	n = readInt();
	m = readInt();
	rep(i,0,n)
	{
		a[i] = readInt();
	}
	v = new vector<int>[n+1];
	rep(i,0,n-1)
	{
		u = readInt();
		w = readInt();
        u -= 1;
        w -= 1;
		v[u].pb(w);
		v[w].pb(u);
	}
	b[0] = a[0];
	dfs(0);
	cout<<noOfWays;
    return 0;
}
