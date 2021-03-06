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

bool isPalindrome(string &s)
{
	ll len = s.length();
	rep(i,0,(len/2) + 1)
	{
		if(s[i] != s[len-1-i])
		{
			return false;
		}
	}
	return true;
}
ll solve(string &str, ll len)
{
	rep(i,0,(len/2))
	{
        if(str[i] < str[len-1-i])
        {
            ll j = len-1-i;
            str[j] = '0';
            --j;
            while(str[j] == '9' && j >= i )
            {
                str[j] = '0';
                --j;
            }
            str[j] = str[j] + 1;
            //cout<<str<<endl;
        }
	}



	rep(i,0,(len/2)+1)
	{
		if(str[i] >= str[len-1-i])
		{
			str[len-1-i] = str[i];
		}
	}

	return -1;
}

int main()
{
	ll t;
	t = read_int();
	while(t--)
	{
		string s;
		cin>>s;
		ll len = s.length();
		if(isPalindrome(s) == true)
		{
			if(s[len-1] < '9')
			{
				s[len - 1] = 1 + s[len - 1];
			}
			else
			{
				s[len - 1] = '0';
				ll j = len - 2;
				while(s[j] == '9' && j >= 0)
				{
					s[j] = '0';
					--j;
				}
				if(j >= 0)
				{
					s[j] += 1;
				}
				else
				{
					s = "1" + s;
				}
			}
		}
		len = s.length();
		solve(s, len);
		cout<<s<<"\n";
	}
	return 0;
}
