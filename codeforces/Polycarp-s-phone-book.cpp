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


struct Trie{
	Trie *next[10];
	int count;
	int index;
	Trie()
	{
		rep(i,0,10)
		{
			next[i] = NULL;
		}
		index = -1;
		count = 0;
	}
};

Trie *root = new Trie();


void insert(string str, ll index)
{
	Trie *current = root;
	rep(i,0,str.length())
	{
		if(current -> next[str[i] - '0'] == NULL)
		{
			current -> next[str[i] - '0'] = new Trie();
		}
		current = current -> next[str[i] - '0'];
		if(current -> index != index)
		{
			current -> count++;
			current -> index = index;
		}
	}
}


int search(string str, ll index)
{
	Trie *current = root;
	rep(i,0,str.length())
	{
		if(current -> next[str[i] - '0'] == NULL)
		{
			return -1;
		}
		current = current -> next[str[i] - '0'];
		if(current -> count == 1)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	vector<string> arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
		rep(j,0,arr[i].length())
		{
			string t = arr[i].substr(j);
			insert(t, i);
		}
	}
	rep(i,0,n)
	{
		string answer = arr[i];
		ll minimum = 9;
		rep(j,0,arr[i].length())
		{
			string t = arr[i].substr(j);
			ll now = search(t, i);
			if(now != -1)
			{
				string curr = t.substr(0, now + 1);
				if(minimum > curr.length())
				{
					minimum = curr.length();
					answer = curr;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}