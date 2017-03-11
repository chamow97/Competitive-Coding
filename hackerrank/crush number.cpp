//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
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
bool f(ll n)
{
    ll t;
    while(n)
    {
        t = n%10;
        n /= 10;
        if(t == 0 || t == 2 || t == 7)
        {

        }
        else
        {
            return false;
        }

    }
    return true;
}
int main()
{
    ll t,n,l;
    t = readInt();
    while(t--)
    {
        n = readInt();
        for(l=n ; ; l+=n)
        {
            if(f(l) == true)
            {
                cout<<l<<endl;
                break;
            }
        }
    }

    return 0;
}
