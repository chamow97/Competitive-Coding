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
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


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

int main()
{
	fastread;
	string str;
	cin>>str;
	ll a, b;
	cin>>a>>b;
	ll len = str.length();
	boolean arr(len+1,false);
	boolean brr(len+1,false);
	ll curr = 0;
	rep(i,0,len)
	{
		curr = (curr * 10) + (str[i] - '0');
		if(curr % a == 0)
		{
			arr[i] = true;
		}
		curr %= a;
	}
	curr = 0;
	ll mul = 1;
	per(j,len-1,0)
	{
		curr += mul * (str[j] - '0');
		mul *= 10;
		mul %= b;
		if(curr % b == 0)
		{
			brr[j] = true;
		}
		curr %= b;
	}
	ll pos = -1;
	rep(i,1,len)
	{
		if(arr[i-1] == true && brr[i] == true && str[i] != '0')
		{
			pos = i;
			break;
		}
	}
	if(pos == -1)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES\n";
		rep(i,0,pos)
		{
			cout<<str[i];
		}
		cout<<'\n';
		rep(i,pos,len)
		{
			cout<<str[i];
		}
	}
	return 0;
}
