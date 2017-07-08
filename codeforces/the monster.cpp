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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<bool> arr(1000000, false);
    rep(i,0,101)
    {
        arr[b + (i*a)] = true;
    }
    rep(i,0,101)
    {
        if(arr[d + (i*c)] == true)
        {
            cout<<d + (i*c);
            return 0;
        }
        arr[d + (i*c)] = true;

    }
    cout<<"-1";

    return 0;
}
