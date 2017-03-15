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
	ll t,n,k,maxdiff=0,diff2,diff1,diff,maxsum=0;
	string s;
	t = readInt();
	while(t--)
	{
		maxdiff = 0;
		diff1=0;
		diff2=0;
        maxsum=0;
		n = readInt();
		k = readInt();
		vector<ll> temp;
		cin>>s;
		rep(i,0,n)
		{
			if(i % 2 == 1)
			{
				if(s[i] == '0')
				{
					++diff2;
				}
				else
				{
					++diff1;
				}
			}
			else
			{
				if(s[i] == '0')
				{
					++diff1;
				}
				else
				{
					++diff2;
				}
			}
		}
		diff = min(diff1,diff2);
        if(diff <= k)
        {
            cout<<"1"<<endl;
        }
        else
        {
           ll low,high,mid;
            maxsum = 1;
            rep(i,1,n)
            {
                if(s[i] != s[i-1])
                {
                    temp.pb(maxsum);
                    maxsum = 1;
                }
                else
                {
                    ++maxsum;
                }
            }
            temp.pb(maxsum);
            low = 2;
            high = n;
            ll ans = n;
            while(low <= high)
            {
                ll mid = (low + high)/2;
                ll sum = 0;
                for(int l : temp)
                {
                    sum += (l)/(mid + 1);
                }
                if(sum <= k)
                {
                    ans = min(ans, mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cout<<ans<<endl;
        }



	}

	return 0;
}
