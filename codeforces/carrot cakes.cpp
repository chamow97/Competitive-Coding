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
	double a, b, c, d;
	cin>>a>>b>>c>>d;
	ll ans1 = 0, ans2 = 0;
	ans1 = ceil((a*b)/c);
	ans2 = ceil(((ceil(d/b)*c)) + (((a-(ceil(d/b)*c))*b)/(2*c)));
	cout<<ans1<<" "<<ans2;
	if(((1.00*(a-(ceil((d*1.00)/b)*c*1.00))*b)/c) < 0)
	{
		cout<<"NO";
		return 0;
	}
	if(ans1 > ans2)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}