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
	map< string, ll >m;
	ll n;
	n = read_int();
	rep(i,0,n)
	{
		string s;
		cin>>s;
		map<string, ll> :: iterator it = m.find(s);
		if(it != m.end())
		{
			ll val = m.find(s)->second + 1ll;
			m[s] = val;
			//cout<<val;
			ll temp;
			string value = "";
			while(val)
			{
				temp = val % 10;
				value = char(temp + 48 ) + value;
				val /= 10; 
			}
			//cout<<value;
			s = s + value;
			cout<<s<<endl;
			m.insert(pair<string, ll>(s, 0ll));
		}
		else
		{
			m.insert(pair<string, ll>(s, 0ll));
			cout<<"OK\n";
		}
	}
	
	return 0;
}
