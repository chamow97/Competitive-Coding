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
    ll ans1 = 0, ans2 = 0,n,m;
     n = readInt();
    m = readInt();
    vector<int> a(n),b(m);

    rep(i,0,n)
    {
        cin>>a[i];
    }
    rep(i,0,m)
    {
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    rep(i,0,n)
    {
        long long a1 = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
        long long a2 = m - (upper_bound(b.begin(),b.end(),a[i]) - b.begin());
        ans1 += (a1 * a2);
        //cout<<a1<<" "<<a2<<endl;

    }
    rep(i,0,m)
    {
        long long a1 = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        long long a2 = n - (upper_bound(a.begin(),a.end(),b[i]) - a.begin());
        ans2 += (a1 * a2);
                //cout<<a1<<" "<<a2<<endl;
//
//        cout<<ans2<<endl;

    }
    //cout<<ans1<<" "<<ans2<<endl;
    if(ans1 > ans2)
    {
        cout<<"Monk "<<ans1 - ans2;
    }
    else if(ans1 < ans2)
    {
        cout<<"!Monk "<<ans2 - ans1;
    }
    else
    {
        cout<<"Tie";
    }
    //cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
