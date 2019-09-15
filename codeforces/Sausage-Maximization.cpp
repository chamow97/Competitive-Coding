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
 
struct trie {
	trie *next[3];
	ll count;
	trie()
	{
		count = 0;
		next[0] = next[1] = next[2] = NULL;
	}
};

trie *root = new trie();

string decToBin(ll n)
{
	string str = "";
	rep(i,0,50)
	{
		str += char((n % 2) + '0');
		n /= 2;
	}
	reverse(str.begin(), str.end());
	return str;
}

void insertString(string str)
{
	trie *temp = root;
	rep(i,0,str.length())
	{
		if(temp -> next[str[i] - '0'] == NULL)
		{
			temp -> next[str[i] - '0'] = new trie();
		}
		temp = temp -> next[str[i] - '0'];
		temp -> count++;
	}
}

ll queryVal(ll val)
{
	trie *temp = root;
	string curr = decToBin(val);
	ll ans = 0;
	rep(i,0,curr.length())
	{
		if(temp -> next[1 - (curr[i] - '0')] != NULL && temp -> next[1 - (curr[i] - '0')] -> count > 0)
		{
			temp = temp -> next[1 - (curr[i] - '0')];
			ans *= 2;
			ans += 1;
		}
		else if(temp -> next[(curr[i] - '0')] != NULL && temp -> next[(curr[i] - '0')] -> count > 0)
		{
			temp = temp -> next[(curr[i] - '0')];
			ans *= 2;
		}
		else
		{
			break;
		}
	}
	return ans;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	vec prefix(n + 1, 0);
	insertString(decToBin(0));
	ll maximum = 0;
	rep(i,1,n+1)
	{
		prefix[i] = (prefix[i - 1] ^ arr[i]);
		maximum = max(maximum, prefix[i]);
	}
	vec suffix(n + 2, 0);
	per(j,n,1)
	{
		suffix[j] = (suffix[j + 1] ^ arr[j]);
		maximum = max(maximum, suffix[j]);
	}
	rep(i,1,n+1)
	{
		insertString(decToBin(prefix[i]));
		maximum = max(maximum, queryVal(suffix[i + 1]));

	}
	cout << maximum;
	return 0;
}