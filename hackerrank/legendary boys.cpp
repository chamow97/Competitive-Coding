//template by chamow

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
    ll t,n,counter=0,temp=1;
    t = readInt();
    while(t--)
    {
        counter = 0;
        temp = 1;
        n = readInt();
        while(temp<=sqrt(n))
        {
            if(n%temp == 0)
            {
              ++counter;
            }

            temp *= 2;
        }
        if(n%temp == 0)
        {
            ++counter;
        }
        cout<<counter<<endl;

    }
    return 0;
}
