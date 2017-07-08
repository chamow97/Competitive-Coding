//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
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
    ll n,a[100001];
    vector<bool> prime(1000001,true);
    vector<ll> numbers;
    prime[1] = false;
    rep(i,2,sqrt(100000)+1)
    {
        if(prime[i] == true)
        {
            for(ll j = (i*i); j <= 100000; j += i)
            {
                prime[j] = false;
            }
        }
    }
    n = readInt();
    rep(i,0,n)
    {
        a[i] = readInt();
        ll val = pow(a[i],0.5);
        ll check = pow(val,2);
        if(a[i] == check)
        {
            if(prime[val] == true)
            {
                printf("YES\n");
                continue;
            }
        }
        printf("NO\n");

    }
    return 0;
}
