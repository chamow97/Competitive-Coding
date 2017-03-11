//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
int counter = 0;
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
vector<int> *adj;
int longest[51];
void dfs(int s, bool visited[], int n)
{
vector<int>::iterator it;
//cout<<s<<" ";
visited[s] = true;
for(it = adj[s].begin(); it != adj[s].end(); it++)
{
if(visited[*it] == false )
{
if(*it == n)
break;
++counter;
dfs(*it, visited, n);
}
}
}
int main()
{
int j,n,m,u,v,i,maxi=-1;
bool visited[51];
for(i=0;i<50;i++)
{
visited[i] = false;
}
adj = new vector<int>[51];
cin>>n>>m;
for(i=0;i<m;i++)
{
cin>>u>>v;
adj[u-1].pb(v-1);
adj[v-1].pb(u-1);
}
for(i=0;i<n;i++)
{
    counter = 0;
    for(j=0;j<50;j++)
{
visited[j] = false;
}
    dfs(i,visited,n-1);
maxi = max(maxi,counter);
//cout<<endl;
}
//cout<<maxi;
if(m == 0)
{
cout<<"1";
}
else
{

cout<<pow(2,maxi);
}
return 0;
}
