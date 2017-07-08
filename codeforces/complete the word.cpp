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
    boolean isAvailable(26,false);
    bool isPossible = true;
    vec arr(26,0);
    ll unknown = 0;
    cin>>s;
    ll len = s.length();
    rep(i,0,len)
    {
        if(s[i] == '?')
        {
            unknown++;
            continue;
        }

        arr[s[i] - 'A']++;
        isAvailable[s[i] - 'A'] = true;
    }
    rep(i,0,len)
    {
        if(s[i] == '?')
        {
            rep(j,0,26)
            {
                if(isAvailable[j] == false)
                {
                    s[i] = j + 'A';
                    isAvailable[j] = true;
                    arr[j]++;
                    break;
                }
            }
        }
    }
    ll pos = -1;
    rep(j,0,26)
    {
        if(isAvailable[j] == true)
        {
            pos = j;
            break;
        }
    }
    rep(i,0,len)
    {
        if(s[i] == '?')
        {
            s[i] = pos + 'A';
        }
    }
    rep(i,0,26)
    {
        if(isAvailable[i] == false)
        {
            isPossible = false;
            break;
        }
    }
    if(isPossible == false)
    {
        cout<<-1;
        return 0;
    }
    cout<<s;
	return 0;
}
