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

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
/*-------------------------------------------------------- */


struct Trie {
	ll count;
	Trie *next[10];
	Trie()
	{
		count = 0;
		rep(i,0,10)
		{
			next[i] = NULL;
		}
	}
};
void insertString(string s, Trie *root)
{
	Trie *current = root;
	current = root;
	ll i;
	rep(i,0,s.length())
	{
		if(current->next[s[i] - '0'] == NULL)
		{
			current->next[s[i] - '0'] = new Trie();
		}
		++current->count;
		current = current->next[s[i] - '0'];
	}
}
ll searchString(string s, Trie *root)
{
	Trie *current = root;
	rep(i,0,s.length())
	{
		if(current->next[s[i] - '0'] == NULL)
		{
			return 0;
		}
		current = current->next[s[i] - '0'];
	}
	return current->count;

}

int main()
{
	ll t, n;
	t = read_int();
	while(t--)
	{
		string temp;
		bool isOkay = true;
		vector<string> s;
		n = read_int();
		Trie *root = new Trie();
		rep(i,0,n)
		{
			cin>>temp;
			s.pb(temp);
			insertString(temp, root);
		}
		rep(i,0,n)
		{
			//cout<<searchString(s[i], root);
			if(searchString(s[i], root) > 0)
			{
				isOkay = false;
				cout<<"NO\n";
				break;
			}
		}
		if(isOkay == true)
		{
			cout<<"YES\n";
		}

	}



	return 0;
}