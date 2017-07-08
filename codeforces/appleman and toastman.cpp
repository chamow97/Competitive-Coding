#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
long long readInt () {
	bool minus = false;
	long long result = 0;
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
    long long sum=0,n,a[300000],i;
    n=readInt();
    for(i=0;i<n;i++)
    {
        a[i]=readInt();
        sum+=a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        sum+=(a[i]*(i+1));
    }
    sum+=((a[n-1])*(n-1));
    cout<<sum;
}
