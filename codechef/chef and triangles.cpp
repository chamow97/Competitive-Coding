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
	ll counter=0,n,l,r,a[1000000];
	n = readInt();
	l = readInt();
	r = readInt();
	bool isFound = false;
	rep(i,0,n)
	{
		a[i] = readInt();
	}
	ll maxi=0;
	sort(a,a+n);
	ll temp = r;
	rep(i,0,n-1)
    {
        ll l1 = l;
        ll r2 = min(r,a[i]+a[i+1]-1);
        ll r1 = r2;
        ll mid  =r2+1;
        
        while(l1<=r1)
        {
            mid = ((r1-l1)/2) + l1;
             
            if((a[i] + a[i+1] <= mid) || (a[i] + mid <= a[i+1]) || (a[i+1] + mid <= a[i]))
            {
                l1 = mid+1;
            }
            else
            {
            	r1 = mid-1;
            	
            }
            // if((a[i] + a[i+1] <= mid-1) || (a[i] + mid-1 <= a[i+1]) || (a[i+1] + mid-1 <= a[i]))
            	// {
            	// 	break;
            	// }

        }
        maxi = max(maxi, r2-mid+1);
        //cout<<maxi<<endl;
    }
    cout<<maxi;
    return 0;
}
