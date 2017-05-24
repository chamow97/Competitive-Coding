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
#define f first
#define s second

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


bool myFunc(pair<ll, ll> &a, pair<ll, ll> &b)
{
	return a.first < b.first;
}
bool myFunc1(pair<ll, ll> &a, pair<ll, ll> &b)
{
	return a.second < b.second;
}

int main()
{
	ll t;
	t = read_int();
	while(t--)
	{
		vector<pair<ll, ll> >v1;
		vector<pair<ll, ll> >v2;
		
		rep(i,0,2)
		{
			ll u, v;
			u = read_int();
			v = read_int();
			v1.pb(mp(u,v));
		}

		rep(i,0,2)
		{
			ll u, v;
			u = read_int();
			v = read_int();
			v2.pb(mp(u,v));
		}
		ll max1 = max(v1[0].f, v1[1].f);
		ll min1 = min(v1[0].f, v1[1].f);
		ll max2 = max(v2[0].f, v2[1].f);
		ll min2 = min(v2[0].f, v2[1].f);
		ll max3 = max(v1[0].s, v1[1].s);
		ll min3 = min(v1[0].s, v1[1].s);
		ll max4 = max(v2[0].s, v2[1].s);
		ll min4 = min(v2[0].s, v2[1].s);
		//storing all the values of edges pssible for second snake
		ll k1 = v2[0].f;
		ll k2 = v2[0].s;
		ll k3 = v2[1].f;
		ll k4 = v2[1].s;
		ll k5 = v1[0].f;
		ll k6 = v1[0].s;
		ll k7 = v1[1].f;
		ll k8 = v1[1].s;
		

		//when both the snakes are aligned horizontal
		//horizontal means y is same

		bool flag = false;
		// if((v1[0].f == v1[1].f && v1[0].s == v1[1].s && v2[0].f == v2[1].f && v2[0].s == v2[1].s))
		// {
		// 	if((min1 == min2 && max1 == max2 && min3 == min4 && max3 == max4))
		// 	{
		// 		flag = true;
		// 	}
		// }
		if(k6 == k8 && k2 == k4 && k6 == k4)
		{
			if((min1 >= min2 && min1 <= max2) && (max1 >= min2 && max1 <= max2))
			{
				flag = true;
			}

			else if(min2 >= min1 & min2 <= max1)
			{
				flag = true;
			}
			else if(max2 >= min1 && max2 <= max1)
			{
				flag = true;
			}
		}
		//when both the snakes are aligned vertical ie. x is same
		else if(k5 == k7 && k1 == k3 && k1 == k5)
		{
			if((min3 >= min4 && min3 <= max4) && (max3 >= min4 && max3 <= max4))
			{
				flag = true;
			}
			else if(min4 >= min3 && min4 <= max3)
			{
				flag = true;
			}
			else if(max4 >= min3 && max4 <= max3)
			{
				flag = true;
			}
		}
		// when one is aligned horizontal
		else if((k6 == k8 && k1 == k3)|| (k2 == k4 && k5 == k7))
		{

			if((k1 == k5 && k2 == k6) || (k1 == k7 && k2 == k8) || (k3 == k5 && k4 == k6) || (k3 == k7 && k4 == k8))
			{
				flag = true;
			}
		}
		//when one is alone aligned vertical
		// else if(v1[0].f == v1[1].f)
		// {
		// 	if((k1 == k5 && k2 == k6) || (k1 == k7 && k2 == k8) || (k3 == k5 && k4 == k6) || (k3 == k7 && k4 == k8))
		// 	{
		// 		flag = true;
		// 	}
		// }
		if(flag == true)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
	}
	return 0;
		
}