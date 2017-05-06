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
	ll n, q;
	vector< string > v;
	n = read_int();
	rep(i,0,n)
	{
		string s;
		cin>>s;
		v.pb(s);
	}
	sort(v.begin(), v.end());
	q = read_int();
	while(q--)
	{
		string s;
		cin>>s;
		//vector<string> :: iterator it;
		ll pos = lower_bound(v.begin(), v.end(), s) - v.begin();
		if(pos == v.size())
		{
			cout<<0<<endl;
		}
		else
		{
			ll len = s.length();
			ll val = 0;
			rep(i,0,len)
			{
				val += (s[i] - 'A' + 1);
			}
			cout<<val*(pos+1)<<endl;
		}

	}
	return 0;
}