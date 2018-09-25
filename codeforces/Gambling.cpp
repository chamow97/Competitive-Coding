//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	fastread
	priority_queue< ll, vec> ms1;
	priority_queue< ll, vec> ms2;
	ll n;
	cin >> n;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		ms1.push(val);
	}
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		ms2.push(val);
	}
	ll ptr = 0;
	ll aVal = 0;
	ll bVal = 0;
	while(!ms1.empty() || !ms2.empty())
	{
		if(ptr % 2 == 0)
		{
			//first case
			if(ms1.empty())
			{
				ms2.pop();
			}
			else if(ms2.empty())
			{
				aVal += ms1.top();
				ms1.pop();
			}
			else
			{
				ll f1 = ms1.top();
				ll f2 = ms2.top();
				if(f1 >= f2)
				{
					aVal += f1;
					ms1.pop();
				}
				else
				{
					ms2.pop();
				}
			}
		}
		else
		{
			if(ms2.empty())
			{
				ms1.pop();
			}
			else if(ms1.empty())
			{
				bVal += ms2.top();
				ms2.pop();
			}
			else
			{
				ll f1 = ms2.top();
				ll f2 = ms1.top();
				if(f1 >= f2)
				{
					bVal += f1;
					ms2.pop();
				}
				else
				{
					ms1.pop();
				}
			}
		}
		ptr++;
	}
	cout << aVal - bVal;
	return 0;
}