//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define MAX 10000001
typedef long long ll;
ll i,j;
//fast IO
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

int main()
{
    ll t,n,maximum=0;
    vector<ll> prime(MAX),a(MAX),maxLen(MAX);
     vector<bool> isPrime(MAX,true);
    rep(i,0,MAX)
    {
        prime[i] = i;
    }
    for(i=2; i<= sqrt(MAX); i++)
    {
        if(isPrime[i] == true)
        {
            for(j=i*2; j<MAX; j+=i)
            {
                isPrime[j] = false;
                prime[j] = i;
            }
        }
    }
    t = readInt();
    while(t--)
    {
        maximum = 0;
        n = readInt();
        rep(i,0,n)
        {
            a[i] = readInt();
        }
        rep(i,0,MAX)
        {
           maxLen[i] = 0;
        }
        rep(i,0,n)
        {
            vector<ll> factor;
            ll temp = a[i];
            while(temp > 1)
            {
                factor.pb(prime[temp]);
                temp /= prime[temp];
            }
            maximum = 0;
            for(j=0; j<factor.size(); j++)
            {
                maximum = max(maximum, maxLen[factor[j]]);
            }
            for(j=0; j<factor.size(); j++)
            {
                maxLen[factor[j]] = maximum + 1;
                //cout<<maxLen[factor[j]]<<" ";
            }
        }
        maximum = 0;
        rep(i,0,MAX)
        {
            maximum = max(maximum,maxLen[i]);
        }
        //as we can always select the last element
        if(maximum == 0)
        {
            maximum = 1;
        }
        cout<<maximum<<endl;
    }

    return 0;
}

