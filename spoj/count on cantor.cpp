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
    ll t,n,a=0,b=1,i,c=0;
    t=readInt();
    while(t--)
    {
        i=-1;
        n=readInt();
        a=n;
        b=1;
        c=0;
        while(n-b>=0)
        {
            ++c;
            n-=b;
            b+=1;
        }
        if(n>0)
            ++c;
       // cout<<a<<" "<<c;
        i=pow(-1,c);
        if(n==0)
            n=c;
        if(i==1)
        {
            cout<<"TERM "<<a<<" IS "<<n<<"/"<<c-n+1;
        }
        else
        {
            cout<<"TERM "<<a<<" IS "<<c-n+1<<"/"<<n;
        }
        cout<<endl;
    }
    return 0;
}

