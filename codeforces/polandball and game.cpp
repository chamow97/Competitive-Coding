//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

int main()
{
	ll n,m;
	cin>>n>>m;
	set<string> s;
	ll repeating = 0;
	rep(i,0,m+n)
	{
		string temp;
		cin>>temp;
		if(s.find(temp) != s.end())
		{
			++repeating;
		}
		s.insert(temp);
	}
	if((repeating & 1) == 1)
	{
		m -= 1;
	}

		if(n > m)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
	return 0;
}