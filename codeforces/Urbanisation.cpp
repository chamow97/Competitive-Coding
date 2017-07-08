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
    ll n,n1,n2,a[100000],i,maxi=-100000,sum;
    float val=0.0,val1=0.0;
    n=readInt();
    n1=readInt();
    n2=readInt();
    for(i=0;i<n;i++)
    {
        a[i]=readInt();
    }
    sort(a,a+n,greater<int>());
    sum=0;
    for(i=0;i<n1;i++)
    {
        sum+=(a[i]);
    }
    val=float((sum*1.000000)/(n1*1.0));
    sum=0;
    for(i=n1;i<n1+n2;i++)
    {
        sum+=(a[i]);
    }
    val+=(float((sum*1.000000)/(n2*1.000000)));
    sum=0;
    for(i=0;i<n2;i++)
    {
        sum+=(a[i]);
    }
    val1=float((sum*1.000000)/(n2*1.0));
    sum=0;
    for(i=n2;i<n1+n2;i++)
    {
        sum+=(a[i]);
    }
    val1+=(float((sum*1.000000)/(n1*1.0)));
    //cout<<val<<endl<<val1;
    cout<<setprecision(8)<<std::fixed<<max(val,val1);

    return 0;
}
