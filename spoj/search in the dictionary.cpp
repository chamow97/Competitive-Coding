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
	ll counter;
	node* next[26];
	Trie()
	{
		counter = 0;
		rep(i,0,26)
		{
			next[i] = NULL;
		}
	}
};
node *root = new node();
void insertQuery(string &s)
{
	node *current = root;
	rep(i,0,s.length())
	{
		if(current->next[s[i] - 'a'] == NULL)
		{
			current->next[s[i] - 'a'] = new node();
		}
		++current->counter;
	}
}

int main()
{
	set<string> s;
	ll n, k;
	string temp;
	n = read_int();
	rep(i,0,n)
	{
		cin>>temp;
		s.insert(temp);
	}
	set<string>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
	{
		insertQuery(*it);
	}
	return 0;
}