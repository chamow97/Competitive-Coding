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

void bfs(ll adj[401][401], vec &path, boolean &visited, ll s, ll n)
{

	path[s] = -1;
	visited[s] = true;
	queue<ll> q;
	q.push(s);
	while(!q.empty())
	{
		ll temp = q.front();
		q.pop();
		for(ll j = 0; j < n; j++)
		{
			if(visited[j] == false && adj[temp][j] == 1)
			{
				q.push(j);
				visited[j] = true;
				path[j] = temp;
			}
		}
	}

}

int main()
{
	ll n, m, u, v;
	n = read_int();
	ll train[401][401] = {0};
	ll bus[401][401] = {0};
	m = read_int();
	rep(i,0,m)
	{
		u = read_int();
		v = read_int();
		u--;
		v--;
		train[u][v] = 1;
		train[v][u] = 1;
	}
	rep(i,0,n)
	{
		rep(j,i+1,n)
		{
			if(train[i][j] == 0)
			{
				bus[i][j] = 1;
				bus[j][i] = 1;
			}
		}
	}
	vec trainPath(401, -1);

	vec busPath(401, -1);

	boolean visitedTrain(401, false);
	boolean visitedBus(401, false);

	bfs(train, trainPath, visitedTrain, 0, n);
	bfs(bus, busPath, visitedBus, 0, n);

	ll pointer = n-1;
	ll counterTrain = 0, counterBus = 0;
	bool isPossible = true;
	while(pointer != 0)
	{
		pointer = trainPath[pointer];
		++counterTrain;
		if(pointer == -1)
		{
			isPossible = false;
			break;
		}
	}
	if(isPossible == false)
	{
		cout<<-1;
		return 0;
	}
	pointer = n-1;
	while(pointer != 0)
	{
		pointer = busPath[pointer];
		++counterBus;
		if(pointer == -1)
		{
			isPossible = false;
			break;
		}
	}
	if(isPossible == false)
	{
		cout<<-1;
		
		return 0;
	}
	cout<<max(counterTrain, counterBus);
	return 0;
}