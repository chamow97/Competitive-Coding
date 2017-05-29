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

int main()
{
	ll t, a, b;
	t = read_int();
	while(t--)
	{
		a = read_int();
		b = read_int(); 
		ll minimum_people = INF;
		ll position = 0;
		vec arr(a, 0), prefix(a, 0);
		rep(i,0,a)
		{
			arr[i] = read_int();
		}
		prefix[0] = arr[0];
		rep(i,1,a)
		{
			prefix[i] = arr[i] + prefix[i-1];
		}
		ll i = 0, j = 0;
		while(i <= j && j <= a-1)
		{
			ll val = prefix[j] - prefix[i] + arr[i];
			if(val <= b)
			{
				if(position < (j-i+1))
				{
					minimum_people = val;
					position = (j-i+1);
				}
				else if(position == (j-i+1))
				{
					minimum_people = min(minimum_people, val);
				}
				j++;
			}
			else
			{
				i++;
			}
		}
		if(minimum_people == INF)
		{
			minimum_people = 0;
		}
		cout<<minimum_people<<" "<<position<<"\n";
	}
	return 0;
}