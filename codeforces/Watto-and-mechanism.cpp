//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;
//thanks to murugappan for teaching
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

ll hashGenerator(string &str , ll mod, ll prime)
{
	ll hashVal = 0;
	ll temp = 1;
	rep(i,0,str.length())
	{
		hashVal = (hashVal + (str[i] - 'a' + 1) * temp) % mod;
		temp = (temp * prime) % mod;
	}
//	cout<<hashVal<<'\n';
	return hashVal;
}

int main()
{
	fastread;
	ll n, m;
	vec hashValue;
	cin>>n>>m;
	rep(i,0,n)
	{
		string str;
		cin>>str;

		hashValue.pb(hashGenerator(str, 1e9 + 7, 31));
		hashValue.pb(hashGenerator(str, 1e9 + 9, 41));
	}
	sort(hashValue.begin(), hashValue.end());
	rep(i,0,m)
	{
		bool isMatch = false;
		string str;
		cin>>str;
		ll temp1 = 1;
		ll temp2 = 1;
		ll hashVal = hashGenerator(str, 1e9 + 7, 31);
		ll hashVal2 = hashGenerator(str, 1e9 + 9, 41);
		ll MODULO1 = 1e9 + 7;
		ll MODULO2 = 1e9 + 9;
		rep(j,0,str.length())
		{
			rep(k,0,3)
			{
			    ll counter = 0;
				if(str[j] - 'a' == k)
				{
					continue;
				}
				ll currentHash1 = ((hashVal + ((k - (str[j] - 'a'))* temp1)) % MODULO1 + MODULO1) % MODULO1;
				ll currentHash2 = ((hashVal2 + ((k - (str[j] - 'a')) * temp2)) % MODULO2 + MODULO2) % MODULO2;

				if(*lower_bound(hashValue.begin(), hashValue.end(), currentHash1) == currentHash1)
				{
					++counter;
				}
				if(*lower_bound(hashValue.begin(), hashValue.end(), currentHash2) == currentHash2)
				{
					++counter;
				}
				if(counter == 2)
				{
					isMatch = true;
				}
			}
            if(isMatch)
            {
                break;
            }
			temp1 = (temp1 * 31) % MODULO1;
			temp2 = (temp2 * 41) % MODULO2;

		}
		if(isMatch)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		cout<<'\n';
	}
	return 0;
}
