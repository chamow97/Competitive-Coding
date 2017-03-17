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
    ll n, sum=0;
    n = readInt();
    rep(i,0,n)
    {
        string s;
        cin>>s;
        if(s[0] == 'T')
        {
            sum += 4;
        }
        else if(s[0] == 'C')
        {
            sum += 6;
        }
        else if(s[0] == 'O')
        {
            sum += 8;
        }
        else if(s[0] == 'D')
        {
            sum += 12;
        }
        else
        {
            sum += 20;
        }
    }

    cout<<sum;
    return 0;
}
