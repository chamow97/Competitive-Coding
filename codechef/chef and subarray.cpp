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
vec maxi;
	

/*-------------------------------------------------------- */

void findMax(vec &frame, ll k)
{
	deque<ll> Q;
	ll i = 0;
	for(i = 0; i < k; i++)
	{
		while((!Q.empty()) && frame[i] >= frame[Q.back()])
		{
			Q.pop_back();
		}
		Q.pb(i);
	}
	for(; i < frame.size(); i++)
	{
		maxi.pb(frame[Q.front()]);
		while((!Q.empty()) && Q.front() <= (i-k))
		{
			Q.pop_front();
		}
		while((!Q.empty()) && frame[i] >= frame[Q.back()])
		{
			Q.pop_back();
		}
		Q.pb(i);
	}
	maxi.pb(frame[Q.front()]);
}

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
	ll n, k, p, ans = 0;
	vec frame;
	n = read_int();
	k = read_int();
	p = read_int();
	vec arr((2*n)+1, 0);
	rep(i,1,n+1)
	{

		arr[i] = read_int();
		ans += arr[i];
		arr[n+i] = arr[i];
	}
	rep(i,1,(2*n)+1)
	{
		arr[i] += arr[i-1];
	}
	rep(i,k,(2*n)+1)
	{
		frame.pb(arr[i] - arr[i-k]);
	}
	ll frame_len = frame.size();
	if(n > k)
	{
		findMax(frame, (n-k+1));
	}
	
	ll pointer = maxi.size();
	// rep(i,0,frame_len)
	// {
	// 	cout<<frame[i]<<" ";
	// }
	//cout<<endl;
	// rep(i,0,pointer)
	// {
	// 	cout<<maxi[i]<<" ";
	// }
	string s;
	--pointer;
	cin>>s;
	ll case_len = s.length();
	rep(i,0,case_len)
	{
		if(pointer == 0)
		{
			pointer = (maxi.size()-1);
		}
		if(s[i] == '!')
		{
			--pointer;
		}
		else
		{
			if(k >= n)
			{
				cout<<ans<<endl;
			}
			else
			{
				cout<<maxi[pointer]<<endl;
			}
			
		}
		
	}
	
	return 0;
}