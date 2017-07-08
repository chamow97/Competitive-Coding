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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

struct Trie{
	ll count;
	Trie *next[26];
	Trie()
	{
		count = 0;
		rep(i,0,26)
		{
			next[i] = NULL;
		}
	}
};
Trie *root;
void insert(vector<string> &s)
{
	rep(i,0,s.size())
	{
		Trie *current = root;
		rep(j,0,s[i].length())
		{
			if(current->next[s[i][j] - 'a'] == NULL)
			{
				current->next[s[i][j] - 'a'] = new Trie();
			}
			current = current->next[s[i][j] - 'a'];
			++current->count;
			
		}
		
	}
}
ll searchQuery(string s)
{
	Trie *current = root;
	ll previous = INF, counter = 0;
	rep(i,0,s.length())
	{
		if(current->next[s[i] - 'a'] == NULL)
		{
			return counter;
		}
		++counter;
		current = current->next[s[i] - 'a'];
		//getting previous results
		ll temp = min(previous, current->count);
		//we have already used one string at this instant
		--temp;
		if(temp == 0)
		{
			return counter;
		}
		previous = temp;

	}
	return counter;
}
int main()
{
	fastread;
	ll n, m, ans = 0;
	root = new Trie();
	cin>>n>>m;
	vector<string> a;
	vector<string> b;
	rep(i,0,n)
	{
		string t;
		cin>>t;
		a.pb(t);
	}
	rep(i,0,m)
	{
		string t;
		cin>>t;
		b.pb(t);
	}
	insert(b);
	rep(i,0,n)
	{
		ans += searchQuery(a[i]);
	}
	cout<<ans;

	return 0;
}