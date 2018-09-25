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
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		bool possible = true;
		cin >> n;
		string str;
		cin >> str;
		rep(i,0,n/2)
		{
			char a = str[i] + 1;
			char b = str[i] - 1;
			char c = str[n-i-1] + 1;
			char d = str[n-i-1] - 1;
			if(a == d && a >= 'a' && a <= 'z')
			{
				str[i] = str[i] + 1;
				str[n-i-1] = str[n-1-i] - 1;
			}
			else if(a == c && a >= 'a' && a <= 'z')
			{
				str[i] = str[i] + 1;
				str[n-1-i] = str[n-1-i] + 1;
			}
			else if(b == d && b >= 'a' && b <= 'z')
			{
				str[i] = str[i] - 1;
				str[n-i-1] = str[n-1-i] - 1;
			}
			else if(b == c && b >= 'a' && b <= 'z')
			{
				str[i] = str[i] - 1;
				str[n-1-i] = str[n-i-1] + 1;
			}
			else
			{
				possible = false;
				break;
			}
		}
		// cout << str;
		rep(i,0,n)
		{
			if(str[i] < 'a' || str[i] > 'z')
			{
				possible = false;
				break;
			}
		}
		if(possible)
		cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}
	return 0;
}