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
	ll n;
	ll _25 = 0, _50 = 0, _100 = 0;
	cin>>n;
	bool isPossible = true;
	ll temp;
	rep(i,0,n)
	{
		cin>>temp;
		if(isPossible == true)
		{
			if(temp == 25)
			{
				++ _25;
			}
			else if(temp == 50)
			{
				++ _50;
				if(_25 >= 1)
				{
					-- _25;
				}
				else
				{
					isPossible = false;
				}
			}
			else
			{
				++ _100;
				if((_50 >=1 && _25 >=1))
				{
					-- _50;
					-- _25;
					++ _100;
				}
				else if(_25 >= 3)
				{
					_25 -= 3;
				}
				else
				{
					isPossible = false;
				}
			}
		}
		
	}
	if(isPossible == true)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}