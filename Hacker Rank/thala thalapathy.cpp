//template by chamow
//template
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
    ll pos=-1,m,d,a[100000],connected=0,connected1=0;
    m = readInt();
    d = readInt();
    rep(i,0,m)
    {
        a[i] = readInt();
    }
    bool isPossible = true,isPossible1 = true;
    rep(i,0,m)
    {
        if(a[i] == 0)
        {
            pos = i;
        }
        else
        {
            if(pos != -1)
            {
                if((i-pos) < d)
                {
                    ++connected;
                    pos = -1;
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }
    }
    if(pos != -1)
    {
        for(ll j=pos-1;j>=0;j--)
        {
            if((pos-j) >= d)
            {
                break;
            }
            if(a[j] == 1)
            {
                if((pos-j) < d)
                {
                    ++connected;
                    break;
                }
            }

        }
    }
    per(i,m-1,0)
    {
        if(a[i] == 0)
        {
            pos = i;
        }
        else
        {
            if(pos != -1)
            {
                if((pos-i) < d)
                {
                    ++connected1;
                    pos = -1;
                }
                else
                {
                    isPossible1 = false;
                    break;
                }
            }
        }
    }
    if(pos != -1)
    {
        for(ll j=pos+1;j<m;j++)
        {
            if((pos-j) >= d)
            {
                break;
            }
            if(a[j] == 1)
            {
                if((pos - j) < d)
                {
                    ++connected1;
                    break;
                }
            }

        }
    }
    if(isPossible == false && isPossible1 == false)
    {
        cout<<"-1";
    }
    else
    {
        cout<<min(connected,connected1);
    }
    return 0;
}
