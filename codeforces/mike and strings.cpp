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

ll findNum(string &st1, string &st2)
{
    string s1 = "", s2 = "";
    ll len = st1.length();
    rep(i,0,st1.length())
    {
        s1 = s1 + st1[len-1-i];
        s2 = s2 + st2[len-1-i];
    }
    ll counter = 0;
    if(s1 == s2)
    {
        return 0;
    }
    while(counter < len)
    {
        bool isContinue = false;
        s2 = s2[len-1] + s2;
        s2[len] = '\0';
        rep(j,0,len)
        {
            if(s1[j] != s2[j])
            {
                isContinue = true;
            }
        }
        ++counter;
        if(isContinue == false)
        {
            break;
        }
    }
    if(counter == len)
    {
        return -1;
    }
    return counter;
}

int main()
{
    ll n, minimum = INF;
    n = read_int();
    vector<string> a;
    string temp;
    rep(i,0,n)
    {
        cin>>temp;
        a.pb(temp);
    }
    vector<string> :: iterator it, jt;
    ll i = 0, j = 0;
    for(it = a.begin(); it != a.end(); it++)
    {
        j = 0;
        ll value = 0;
        for(jt = a.begin(); jt != a.end(); jt++)
        {
            if(i != j)
            {
                string temp1 = *it;
                string temp2 = *jt;
                ll val = findNum(temp1, temp2);
                if(val == -1)
                {
                    cout<<-1;
                    return 0;
                }
                value += min(minimum, val);

            }

            ++j;
        }
        minimum = min(minimum, value);
        ++i;
    }
    cout<<minimum;
	return 0;
}
