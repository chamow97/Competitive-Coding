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
	ll t,n,floor,sum,temp;
	t = readInt();
	while(t--)
	{
		n = readInt();
		temp = n;
		floor = 1;
		sum = 0;
		if(n==1)
        {
            cout<<"1"<<endl;
        }
        else
        {
           while(1)
           {
               if(floor<=(n-sum-floor))
               {

                   sum+=floor;
                   ++floor;
               }
               else
               {
                   //cout<<sum<<endl;
                   --floor;
                   sum+=(n-sum-floor);
                   sum+=(n-floor);
                   break;
               }
           }
           cout<<sum<<endl;
        }
	}
    return 0;
}
