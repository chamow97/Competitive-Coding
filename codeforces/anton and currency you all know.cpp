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
	string n;
	cin>>n;
	ll len = n.length();
	bool isPossible = false;
	bool isFound = false;
	rep(i,0,len)
	{
		if((n[i] - '0') % 2 == 0)
		{
			isPossible=true;
			break;
		}
	}

	if(isPossible == false)
	{
		cout<<"-1";
		return 0;
	}
	rep(i,0,len-1)
	{
		if((n[i] - '0')%2 == 0 && ((n[i] - '0') < (n[len-1] - '0')))
		{
			swap(n[i], n[len-1]);
			isFound = true;
			cout<<n;
			return 0;
		}
	}
	if(isFound == false)
	{
		per(i,len-1,0)
		{
			if((n[i] - '0') % 2 == 0)
			{
				swap(n[i], n[len-1]);
				isFound = true;
				cout<<n;
				break;
			}
		}
	}

	return 0;
}