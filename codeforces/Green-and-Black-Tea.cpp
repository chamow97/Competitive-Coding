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

ll n, k, a, b;
	
bool check(string answer)
{
	if(answer.length() != n)
	{
		return false;
	}
	ll maximum = 1, counter = 1;
	rep(i,1,answer.length())
	{
		if(answer[i] == answer[i - 1])
		{
			counter++;
		}
		else
		{
			maximum = max(maximum, counter);
			counter = 1;
		}
	}
	maximum = max(maximum, counter);
	if(maximum > k)
	{
		return false;
	}
	return true;
}

int main()
{
	fastread;
	cin >> n >> k >> a >> b;
	char fst = 'G';
	char scnd = 'B';
	string answer = "";
	if(a < b)
	{
		swap(a, b);
		swap(fst, scnd);
	}
	ll i = 0;
	for(i = 0; i < n; i++)
	{
		if(a == b)
		{
			break;
		}
		ll j = i;
		for(j = i; j < min(i + k, min(n, i + a - b)); j++)
		{
			answer += fst;
		}
		a -= (j - i);
		if(j == i + k)
		{
			if(b > 0)
			{
				b--;
				answer += scnd;
			}
		}
		i = j;
	}
	while(a--)
	{
		answer += fst;
		answer += scnd;
	}
	if(check(answer))
	{
		cout << answer;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}