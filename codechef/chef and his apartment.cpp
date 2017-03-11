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
	ll counter=0,t,result=0,n,a[100000],pos=0;
	t = readInt();
	while(t--)
	{
	    n = readInt();
	    pos = n;
	    counter = 0;
	    result = 0;

	rep(i,0,n)
	{
		a[i] = readInt();
	}
	rep(i,0,n)
	{
		if(a[i] == 0)
		{

			if(counter == 0)
            {
                pos = i;
            }
            ++counter;
		}
	}
	//adding remaining due ie. if at last there are some due months
	result += ((counter*1000) + ((n-pos)*100));
	cout<<result<<'\n';

	}

    return 0;
}
