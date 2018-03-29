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

const ll maxn = 4e5 + 100;
vec arr(maxn);

struct trie{
	ll counter;
	trie *next[5];
	trie(){
		counter = 0;
		rep(m,0,5)
		{
			next[m] = NULL;
		}
	}
};

trie *root = new trie();

void insert(string str)
{
	trie *current = root;
	rep(i,0,str.length())
	{
		if(current -> next[str[i] - '0'] == NULL)
		{
			current -> next[str[i] - '0'] = new trie();
		}
		current = current -> next[str[i] - '0'];
		current -> counter++;
	}
}

ll searchString(string str)
{
	ll ans = 0;
	trie *current = root;
	rep(i,0,str.length())
	{
		if(current -> next[str[i] - '0'] != NULL && current -> next[str[i] - '0'] -> counter > 0)
		{
			current = current -> next[str[i] - '0'];
		}
		else
		{
			current = current -> next[1 - (str[i] - '0')];
			ans += (1 << (31 - i));
		}
		current -> counter--;
	}
	return ans;
}

string getBinaryString(ll currVal)
{
	string binaryString = "";
	rep(j,0,32)
	{
		binaryString += (char((currVal % 2) + '0'));
		currVal /= 2;
	}
	reverse(binaryString.begin(), binaryString.end());
	return binaryString;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	rep(k,0,n)
	{
		ll val;
		cin >> val;
		insert(getBinaryString(val));
	}
	rep(k,0,n)
	{
		cout << searchString(getBinaryString(arr[k])) << ' ' ;
	}
	return 0;
}