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
int main()
{
    ll t,n,maximum = 0,pos=-1;
    ll a[100000],b[100000];
    t = readInt();
    while(t--)
    {
        n = readInt();
        pos = -1;
        maximum = 0;

        rep(i,0,n)
        {
            a[i] = readInt();
        }
        rep(i,0,n)
        {
            b[i] = readInt();
        }
        
        rep(i,0,n)
        {
            ll low = 0, high = n-1, mid, pos = -1;
            while(low <= high)
            {
                mid = (low+high)/2;
                if(b[mid] >= a[i])
                {
                    low = mid+1;
                    pos = mid;
                }
                else
                {
                    high = mid-1;
                }
                
            }
            maximum = max(maximum, pos - i);       


        }



        printf("%lld\n",maximum);


    }

    return 0;
}
