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
	fastread
	ll n;
	cin >> n;
	string str, str1;
	cin >> str >> str1;
	ll ans = 0;
	rep(i,0,n)
	{
		if(i < n - 1)
		{
			if(str[i] == str1[i+1] && str1[i] == str[i+1] && str[i] != str1[i])
			{
				swap(str[i], str[i+1]);
				ans++;
			}
		}
		if(str[i] == str1[i])
		{
			continue;
		}
		if(str[i] == '0')
		{
			str[i] = '1';
		}
		else
		{
			str[i] = '0';
		}
		ans++;
	}
	cout << ans;
	return 0;
}