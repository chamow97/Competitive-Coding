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
	ll k, n;
	cin >> n >> k;
	string str;
	cin >> str;
	ll ptr1 = k / 2;
	ll ptr2 = ptr1;
	ll sum = 0;
	string ans = "";
	rep(i,0,n)
	{
		if(str[i] == '(' && sum >= 0 && ptr1 > 0)
		{
			ptr1--;
			sum++;
			ans += '(';
		}
		else if(str[i] == ')' && sum >= 0 && ptr2 > 0)
		{
			ptr2--;
			sum--;
			ans += ')';
		}
	}
	cout << ans;
	return 0;
}