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
 

char a[2][600];

bool func(ll row, ll col, ll counter, ll n, ll snake_counter)
{
	// cout<<row<<" "<<col<<endl;
	bool visited[2][n];
	++counter;
	rep(i,0,2)
	{
		rep(j,0,n)
		{
			visited[i][j] = false;
		}
	}
	// cout<<"A";
	visited[row][col] = true;
	while(1)
	{
		// cout<<"ada";
		if(row == 0)
		{
			if(a[row+1][col] == '#' && visited[row+1][col] == false)
			{
				// cout<<"asda";
				
				row = row+1;
				++counter;
				visited[row][col] = true;
			}
			else if(a[row][col+1] == '#' && visited[row][col+1] == false && col != n-1)
			{
				
				col = col + 1;
				++counter;
				visited[row][col] = true;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(a[row-1][col] == '#' && visited[row-1][col] == false)
			{
				
				row = row - 1;
				++counter;
				visited[row][col] = true;
			} 
			else if(a[row][col+1] == '#' && visited[row][col+1] == false && col != (n-1))
			{
				
				col = col + 1;
				++counter;
				visited[row][col] = true;
			}
			else
			{
				break;
			}
		}
	// cout<<"A1";
	}
	

	// cout<<"A2";
	// cout<<counter<<" "<<snake_counter<<endl;
	if(counter == snake_counter)
	{
		return true;
	}
	return false;
} 

int main()
{
	ll t, n;
	t = read_int();
	while(t--)
	{
		ll snake_counter = 0;
		n = read_int();
		
		
		rep(i,0,2)
		{
			rep(j,0,n)
			{
				cin>>a[i][j];
				if(a[i][j] == '#')
				{
					snake_counter++;
				}
			}
		}
		if(n == 1)
		{
			cout<<"yes\n";
			continue;
		}
		ll row = -1, col = -1;
		rep(j,0,n)
		{
			if(a[0][j] == '#')
			{
				row = 0;
				col = j;
				break;
			}
		}
		ll counter = 0;
		bool flag1 = false, flag2 = false;
		if(row != -1)
		flag1 = func(row, col, counter, n, snake_counter);
		ll counter1 = 0;
		row = -1;
		col = -1;
		rep(j,0,n)
		{
			if(a[1][j] == '#')
			{
				row = 1;
				col = j;
				break;
			}
		}
		if(row != -1)
		flag2 = func(row, col, counter1, n, snake_counter);
		if(flag1 == false && flag2 == false)
		{
			cout<<"no\n";
		}
		else
		{
			cout<<"yes\n";
		}
		
	}
	return 0;
} 