		//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

int getDistinct(map<char, int> &m1)
{
	int currDistinct = 0;
	for(char now = 'A'; now <= 'Z'; now++)
	{
		if(m1[now] > 0)
		{
			currDistinct++;
		}
	}
	for(char now = 'a'; now <= 'z'; now++)
	{
		if(m1[now] > 0)
		{
			currDistinct++;
		}
	}
	return currDistinct;
}

int main()
{
	// write modular code!! if you cannot, don't worry, it doesn't make a diff here lmao!
	int n;
	cin >> n;
	string str;
	cin >> str;
	map<char, int> m;
	rep(i,0,n)
	{
		m[str[i]]++;
	}
	int distinct = m.size();
	if(n == 1)
	{
		cout << n;
		return 0;
	}
	int ptr1 = 0, ptr2 = 1;
	map<char, int> m1;
	m1[str[ptr1]]++;
	m1[str[ptr2]]++;
	int ans = n;
	while(ptr1 < ptr2 && ptr2 < n)
	{
		if(ptr1 == ptr2)
		{
			ptr2++;
			if(ptr2 < n)
			{
				m1[str[ptr2]]++;
			}
		}
		int currDistinct = getDistinct(m1);
		if(currDistinct < distinct) {
			ptr2++;
			if(ptr2 < n)
			{
				m1[str[ptr2]]++;
			}
		}
		else {
			ans = min(ans, ptr2 - ptr1 + 1);
			m1[str[ptr1]]--;
			ptr1++;
		}
	}
	if(getDistinct(m1) >= distinct) {
		ans = min(ans, ptr2 - ptr1 + 1);
	}
	cout << ans;
	return 0;
}