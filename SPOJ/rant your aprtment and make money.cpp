//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
struct v
{
	ll s,d,w;
};
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

ll binarySearch(v v1[], ll n)
{
	// ll low=0,high=i-1;
	// while(low<=high)
	// {
	// 	ll mid=(low+high)/2;
	// 	if(v1[mid].d<=v1[high].s)
	// 	{
	// 		if(v1[mid+1].d<= v1[i].s)
	// 		{
	// 			low = mid+1;
	// 		}
	// 		else
	// 		{
	// 			return mid;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		high = mid-1;
	// 	}
	// }
	// return -1;
	rep(i, 0, n)
	{
		if(v1[i].d<v1[n].s)
		{
			
		}
	}
}
bool myFunc(v s1, v s2)
{
	return s1.s<s2.s;
}
int main()
{
	ll t,n;
	t = readInt();
	while(t--)
	{
		n = readInt();
		v v1[n];
		rep(i,0,n)
		{
			cin>>v1[i].s>>v1[i].d>>v1[i].w;
			v1[i].d+=(v1[i].s);
		}
		sort(v1,v1+n,myFunc);
		ll t1[n];
		t1[0] = v1[0].w;
		rep(i,1,n)
		{
			ll p = v1[i].w;
			ll l = binarySearch(v1,i);
			if(l!=-1)
			{
				p+=t1[l];
			}
			t1[i] = max(p,t1[i-1]);
		}
		cout<<t1[n-1]<<endl;
	}
    return 0;
}
