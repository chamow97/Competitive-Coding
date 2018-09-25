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

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.s < p2.s;
}

int main()
{
	fastread
	ll n;
	string str;
	cin >> str;
	ll k;
	cin >> k;
	n = str.length();
	vecpair freq(26);
	rep(i,0,n)
	{
		freq[str[i] - 'a'].f++;
	}
	rep(i,0,26)
	{
		freq[i].s = i;
	}
	sort(freq.begin(), freq.end());
	rep(i,0,26)
	{
		k -= freq[i].f;
		if(k == 0)
		{
			freq[i].f = 0;
			break;
		}
		if(k < 0)
		{
			freq[i].f += (abs(k));
			break;
		}
		freq[i].f = 0;
	}
	ll distinct = 0;
	rep(i,0,26)
	{
		if(freq[i].f > 0)
		{
			++distinct;
		}
	}
	sort(freq.begin(), freq.end(), comp);
	cout << distinct << '\n';
	rep(i,0,n)
	{
		if(freq[str[i] - 'a'].f > 0)
		{
			cout << str[i];
			freq[str[i] - 'a'].f--;
		}
	}
	return 0;
}