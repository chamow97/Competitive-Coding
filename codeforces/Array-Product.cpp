//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;

/*-------------------------------------------------------- */

/*
No one values your skills. All you want is luck.
Accept it and live this shitty life, else try to fight
it and die more shittier.
*/

int main()
{
	fastread
	set<ll> full;
	set<ll> pos;
	set<ll> neg;
	set<ll> zero;
	ll n;
	ll counter = 0;
	bool isOver = false;
	cin >> n;
	vec arr(n + 1);
	rep(i,1,n+1)
	{
		ll val;
		cin >> val;
		arr[i] = val;
		full.insert(i);
		if(val == 0)
		{
			zero.insert(i);
		}
		else if(val < 0)
		{
			neg.insert(i);
		}
		else
		{
			pos.insert(i);
		}
	}

	// Negative is more evil
	ll maximum = -INF;
	ll position = -1;
	if(neg.size() % 2 == 1)
	{
		for(auto it : neg)
		{
			if(maximum < arr[it])
			{
				maximum = arr[it];
				position = it;
			}
		} 
		// remove that negative
		if(zero.size() == 0)
		{
			++counter;
			cout << "2 " << position << '\n';
			full.erase(full.find(position));
			isOver = true;
		}
		else
		{
			zero.insert(position);
		}
	}
	if(zero.size() > 0 && (!isOver))
	{
		vec temp;
		for(auto it : zero)
		{
			temp.pb(it);
		}
		rep(i,0,temp.size() - 1)
		{
			if(counter == n - 1)
			{
				break;
			}
			cout << "1 " << temp[i] << ' ' << temp[i+1] << '\n';
			counter++;
		}
		if(counter < n - 1)
		{
			counter++;
			cout << "2 " << temp[temp.size() - 1] << '\n';
		}
		for(auto it : zero)
		{
			full.erase(full.find(it));
		}
	}
	vec temp;
	for(auto it : full)
	{
		temp.pb(it);
	}
	if(temp.size() == 0)
	{
		return 0;
	}
	rep(i,0,temp.size() - 1)
	{
		if(counter == n - 1)
		{
			break;
		}
		cout << "1 " << temp[i] << ' ' << temp[i + 1] << '\n';
		++counter;
	}
	return 0;
}