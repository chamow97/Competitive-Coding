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
    ll n,k,i,j;
    bool found=false;
    bool found1=false;
    char str[101];
    n=readInt();
    k=readInt();
    cin>>str;
    for(i=0;i<n;i++)
    {
        if(str[i]!='G')
            continue;
        else
        {
            for(j=i;j<n;j+=k)
            {
                if(str[j]=='#')
                {
                    found=false;
                    break;
                }
                else if(str[j]=='.')
                {
                    continue;
                }
                else if(str[j]=='T')
                {
                    found=true;
                    break;
                }
            }
            break;
        }

    }
    for(i=n-1;i>=0;i--)
    {
        if(str[i]!='G')
            continue;
        else
        {
            for(j=i;j>=0;j-=k)
            {
                if(str[j]=='#')
                {
                    found1=false;
                    break;
                }
                else if(str[j]=='.')
                {
                    continue;
                }
                else if(str[j]=='T')
                {
                    found1=true;
                    break;
                }
            }
            break;
        }

    }
    if(found==false && found1==false)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }


    return 0;
}
