//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */
typedef long long ll;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 10000000000

/*-------------------------------------------------------- */


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

void construct(ll low, ll high, ll pos, vec &arr, vec &seg)
{
	if(low == high)
	{
		seg[pos] = arr[low];
	}
	else
	{
		ll mid = (low + high)/2;
		construct(low, mid, (2*pos)+1, arr, seg);
		construct(mid+1, high, (2*pos)+2, arr, seg);
		seg[pos] = min(seg[(2*pos)+1], seg[(2*pos)+2]);
	}

}

ll rangeMin(ll lowb, ll uppb, ll low, ll high, ll pos, vec &seg)
{
	if(uppb < low || lowb > high)
	{
		return 2000000000;
	}
	else if(lowb <= low && uppb >= high)
	{
		return seg[pos];
	}
	else
	{
		ll mid = (low + high)/2;
		return min(rangeMin(lowb, uppb, low, mid, (2*pos)+1, seg) , rangeMin(lowb, uppb, mid+1, high, (2*pos)+2, seg));
	}
}


int main()
{
	ll t, n, q, lowb, uppb;
	t  = read_int();
	rep(l,0,t)
	{
		n = read_int();
		q = read_int();
		vec arr(n,0);
		rep(i,0,n)
		{
			arr[i] = read_int();
		}
		vec seg(4*n,2000000000ll);
		construct(0ll, n-1, 0ll, arr, seg);
		cout<<"Scenario #"<<l+1<<":\n";
		rep(i,0,q)
		{
			lowb = read_int();
			uppb = read_int();
			cout<<rangeMin(lowb-1, uppb-1, 0ll, n-1, 0ll, seg)<<endl;
		}
	
	}

	return 0;
}