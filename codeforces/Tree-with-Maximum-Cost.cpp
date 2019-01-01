#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll result = 0, n;
const ll MAXN = 2e5 + 20;
vector<ll> adj[MAXN];
vector<ll> sum(MAXN, 0);
vector<ll> arr(MAXN, 0);
ll ans = 0;

void dfs(ll s, ll p, ll depth)
{
    sum[s] = arr[s];
    result = (result + (depth * arr[s]));
    for(auto i : adj[s])
    {
        if(i == p)
        {
            continue;
        }
        dfs(i, s, depth + 1);
        sum[s] += sum[i];
    }
}

void dfs1(ll s, ll p)
{
    ans = max(ans, result);
    for(auto i : adj[s])
    {
        if(i == p)
        {
            continue;
        }
        result -= sum[i];
        sum[s] -= sum[i];
        result += sum[s];
        sum[i] += sum[s];
        dfs1(i, s);
        sum[i] -= sum[s];
        result -= sum[s];
        sum[s] += sum[i];
        result += sum[i];
    }
}

int main() {
    //saw editorial :(
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    dfs1(1, 0);
    cout << ans;
	return 0;
}