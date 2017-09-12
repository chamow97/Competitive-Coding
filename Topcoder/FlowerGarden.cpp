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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;


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

class FlowerGarden{
public:
	vec getOrdering(vec height, vec bloom, vec wilt){
		ll adj[51][51]; //for storing edge info
		boolean visited(51,false); //to keep track of visited nodes
		ll n = height.size();
		vec degree(n,0); //to store degree of each node
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				adj[i][j] = 0;
			}
		}
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				//if 2 flowers overlap, and one is smaller than other, keep a dependency
				if(height[i] < height[j] && ((bloom[i] >= bloom[j] && bloom[i] <= wilt[j]) || (bloom[j] >= bloom[i] && bloom[j] <= wilt[i])))
				{
					adj[i][j] = 1;
					degree[j]++;
				}
			}
		}
		vec ans;
		rep(i,0,n)
		{
			ll maximum = 0;
			ll pos = -1;
			rep(j,0,n)
			{
				//find the max vertex which satisfies the condition
				if(degree[j] == 0 && visited[j] == false && height[j] > maximum)
				{
					maximum = height[j];
					pos = j;
				}
			}
			visited[pos] = true;
			ans.pb(maximum);
			//to adjust the degree and adj matrix after the removal of edge
			rep(j,0,n)
			{
				if(adj[pos][j] == 1)
				{
					degree[j]--;
				}
			}
		}
		return ans;
		
	}	
};

// int main()
// {
// 	fastread;
// 	ll n;
// 	cin>>n;
// 	vec height(n,0);
// 	vec bloom(n,0);
// 	vec wilt(n,0);
// 	rep(i,0,n)
// 	{
// 		cin>>height[i];
// 	}
// 	rep(i,0,n)
// 	{
// 		cin>>bloom[i];
// 	}
// 	rep(i,0,n)
// 	{
// 		cin>>wilt[i];
// 	}
// 	FlowerGarden F;
// 	vec ans = F.getOrdering(height, bloom, wilt);
// 	rep(i,0,n)
// 	{
// 		cout<<ans[i]<<" ";
// 	}
// 	return 0;
// }