#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
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
    ll n;
    n = readInt();
    if(n == 2)
    {
        cout<<1;
        return 0;
    }
    if(n % 2 == 0)
    {
        cout<<2;
        return 0;
    }
    if(n % 2 == 1)
    {
        bool prime = true;
        rep(i,2,sqrt(n)+1)
        {
            if(n%i == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime == true)
        {
            cout<<1;
            return 0;
        }
        prime = true;
        rep(i,2,sqrt(n)+1)
        {
            if((n-2)%i == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime == true)
        {
            cout<<2;
            return 0;
        }
        cout<<3;
        return 0;
    }



    return 0;
}
