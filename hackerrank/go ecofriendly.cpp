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
    ll t,n,pos;
    t = readInt();
    while(t--)
    {
        pos = 0;
        n = readInt();
        if(n<3)
        {
            cout<<"1\n";
        }
        else
        {
            rep(i,1,sqrt(n)+1)
        {
            if(((i*(i+1)*((2*i)+1))/6)>n)
            {
                pos = i;
                break;
            }
        }
        cout<<pos-1<<endl;
        }

    }

    return 0;
}
