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
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	ll n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	if(s == "*")
	{
		cout << "YES";
		return 0;
	}
	if(n > m + 1)
	{
		cout << "NO";
		return 0;
	}
	if(s == t)
	{
		cout << "YES";
	}
	else
	{
		bool isStar = false;
		rep(i,0,n)
		{
			if(s[i] == '*')
			{
				isStar = true;
				break;
			}
		}
		if(!isStar)
		{
			if(s != t)
			{
				cout << "NO";
				return 0;
			}
			cout << "YES";
			return 0;
		}
		ll ptr1 = 0, ptr2 = 0;
		while(s[ptr1] != '*' && ptr1 < n && ptr2 < m)
		{
			if(s[ptr1] != t[ptr2])
			{
				cout << "NO";
				return 0;
			}
			ptr1++;
			ptr2++;
		}
		ll ptr3 = n - 1, ptr4 = m - 1;
		while(ptr3 > ptr1 && ptr3 >= 0 && ptr4 >= 0)
		{
			if(s[ptr3] != t[ptr4])
			{
				cout << "NO";
				return 0;
			}
			ptr3--;
			ptr4--;
		}
		if(ptr3 > ptr1)
		{
			cout << "NO";
		}
		else
		{
			cout << "YES";
		}
	}
	return 0;
}