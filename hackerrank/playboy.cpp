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
ll f(ll a)
{
    ll t,temp = a,sum=0;
    while(temp)
    {
        t = temp%10;
        temp/=10;
        sum += t;
    }
    return sum;
}
int main()
{
    ll x,n,i=0,a[100000];
    x = readInt();
    while(1)
    {
        a[i] = readInt();

        if(a[i] == 0)
        {
            break;
        }
        ++i;
    }
    n = i;
    ll low = 0, high = n-1,mid;
    while(low < high)
    {
        mid = (low+high)/2;
        if(f(a[mid]) > x )
        {
            high = mid-1;
        }
        else if(f(a[mid]) < x)
        {
            low = mid+1;
        }
        else
        {
            break;
        }
    }
    cout<<a[mid]<<endl;
    return 0;
}
