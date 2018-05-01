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

vec squareNumbers;

ll check(ll a, ll b)
{
	ll matches = 0;
	string sqNumber = to_string(a);
	string givenNumber = to_string(b);
	reverse(sqNumber.begin(), sqNumber.end());
	reverse(givenNumber.begin(), givenNumber.end());
	ll ptr = givenNumber.length() - 1;
	ll ptr1 = sqNumber.length() - 1;
	while(ptr >= 0 && ptr1 >= 0)
	{
		while(sqNumber[ptr1] != givenNumber[ptr] && ptr >= 0)
		{
			ptr--;
		}
		if(ptr < 0)
		{
			break;
		}
		ptr1--;
		ptr--;
		matches++;
	}
	if(ptr1 >= 0)
	{
		return INF;
	}
	else
	{
		return (givenNumber.length() - matches);
	}
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	ll minimum = INF;
	rep(i,1,70001)
	{
		ll now = i * i;
		if(now > n)
		{
			break;
		}
		minimum = min(minimum, check(now, n));
	}
	if(minimum == INF)
	{
		minimum = -1;
	}
	cout << minimum;
	return 0;
}