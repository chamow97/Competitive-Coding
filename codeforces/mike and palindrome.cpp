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

void palindrome(string &s)
{
    ll len = s.length();
    rep(i,0,(len/2) + 1)
    {
        s[i] = s[len-1-i];
    }
}
void palindrome1(string &s)
{
    ll len = s.length();
    rep(i,0,(len/2) + 1)
    {
        s[len-1-i] = s[i];
    }
}

int main()
{
    string s;
    cin>>s;
    ll len = s.length();
    string temp = s;
    string temp1 = s;
    palindrome(temp);
    palindrome1(temp1);
    ll counter = 0;
    rep(i,0,len)
    {
        if(s[i] != temp[i])
        {
            ++counter;
        }
    }
    if(counter == 1|| (counter == 0 && (len % 2 == 1)))
    {
        cout<<"YES";
        return 0;
    }
    counter = 0;
    rep(i,0,len)
    {
        if(s[i] != temp1[i])
        {
            ++counter;
        }
    }
    if(counter == 1 || (counter == 0 && (len % 2 == 1)))
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
	return 0;
}
