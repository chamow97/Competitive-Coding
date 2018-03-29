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
	ll counter;
	Trie *next[4];
	Trie(){
		counter = 0;
		rep(i,0,4)
		{
			next[i] = NULL;
		}
	}
};

Trie *root = new Trie();

string getBinary(ll val)
{
	string binaryVal = "";
	rep(i,0,32)
	{
		binaryVal += (char((val % 2) + '0'));
		val /= 2;
	}
	return binaryVal;
}

void addOrDelete(ll val, ll type)
{
	Trie *current = root;
	string value = getBinary(val);
	per(i,value.length() - 1, 0)
	{
		if(current -> next[value[i] - '0'] == NULL)
		{
			current -> next[value[i] - '0'] = new Trie();
		}
		current = current -> next[value[i] - '0'];
		if(type == 0)
		{
			++current -> counter;
		}
		if(type == 1)
		{
			--current -> counter;
		}
	}
}

ll search(ll val)
{
	string value = getBinary(val);
	ll ans = 0;
	Trie *current = root;
	per(i, value.length() - 1, 0)
	{
		ll reqdBit = 1 - (value[i] - '0');
		if(current -> next[reqdBit] == NULL || current -> next[reqdBit] -> counter == 0)
		{
			reqdBit = 1 - reqdBit;
		}
		ans += (reqdBit * pow(2, i));
		current = current -> next[reqdBit];
	}
	return ans;
}

int main()
{
	fastread;
	ll q;
	cin >> q;
	addOrDelete(pow(2, 32), 0);
	while(q--)
	{
		char c;
		ll val;
		cin >> c >> val;
		if(c == '+')
		{
			addOrDelete(val, 0);
		}
		else if(c == '-')
		{
			addOrDelete(val, 1);
		}
		else
		{
			ll temp = val;
			cout << (temp xor search(val)) << '\n';
		}
	}
	return 0;
}