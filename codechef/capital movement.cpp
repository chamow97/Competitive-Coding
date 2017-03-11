#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
typedef long long ll;

ll temp,u,v,t,n,a[50002];
vector<int> *vec;
vector<int>::iterator it;
bool myFunc(const pair<int, int>&a1, const pair<int, int>&b1)
{
    return a1.second > b1.second;
}
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll maximum = -100000, pos1=-1,pos = -1;
		vec = new vector<int>[n+1];
		pair<int ,int> p[n+1];
		rep(i,0,n)
		{
		    scanf("%llu",&a[i]);
            p[i].first = i;
            p[i].second =  a[i];
		}
		rep(i,0,n-1)
		{
			scanf("%lld",&u);
			scanf("%lld",&v);
			u--;
			v--;
			vec[u].pb(v);
			vec[v].pb(u);
		}

		sort(p,p+n,myFunc);

        rep(i,0,n)
        {
            ll maxPos = -1;
             bool flag[100001];
             rep(m,0,n)
             {
                 flag[m] = false;
             }
            for(it = vec[i].begin(); it != vec[i].end(); it++)
            {
                flag[*it] = true;
            }
            flag[i] = true;
            rep(k,0,n)
            {
                if(flag[p[k].first] == true)
                {
                    continue;
                }
                else
                {
                    maxPos = p[k].first;
                    break;
                }
            }
           printf("%lld ",maxPos+1);
        }
        printf("\n");
	}
    return 0;
}
