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
	string s; 
	ll len = 0, l = 0, r = 0, l1 = 0, r1 = 0, sp = 0, pos = -1;
	vec a;
	cin>>s;
	len = s.length();
	rep(i,0,len)
	{
		if(s[i] == '(')
		{
			++l;
		}
		else if(s[i] == ')')
		{
			++r;
		}
		else
		{
			++sp;
			pos = i;
		}
	}
	if(r > l || ((r + sp) > l))
	{
		cout<<-1;
		return 0;
	}
	rep(i,0,len)
	{
		if(r1 > l1)
		{
			cout<<-1;
			return 0;
		}
		if(s[i] == '(')
		{
			++l1;
		}
		else if(s[i] == ')')
		{
			++r1;
		}
		else
		{
			if(r1 == l1)
			{
				cout<<-1;
				return 0;
			}
			if(i == pos)
			{
				a.pb(l-r);
				r1 += (l-r);
				r = l;
				
			}
			else
			{
				a.pb(1);
				r++;
				r1++;
			}

		}
	}
	
		rep(i,0,a.size())
		{
			cout<<a[i]<<endl;
		}
	return 0;
}