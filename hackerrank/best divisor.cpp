#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll findsum(int t)
{
    ll sum=0,temp;
    while(t)
    {
        temp=t%10;
        t/=10;
        sum+=(temp);
    }
    return sum;
}
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
    ll temp,temp1,n,pos,maxi=-10000000;
    n=readInt();
    rep(i,1,sqrt(n)+1)
    {
        if(n%i==0)
        {
            temp=findsum(i);
            temp1=findsum(n/i);
            if(temp>=maxi)
            {
                if(temp==maxi && pos<i)
                    continue;
                maxi=temp;
                pos=i;
            }
            if(temp1>=maxi)
            {
                if(temp1==maxi && pos<(n/i))
                    continue;
                maxi=temp1;
                pos=n/i;
            }
        }
    }
    cout<<pos;
    return 0;
}
