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

int main()
{
	fastread;
	string str;
	cin>>str;
	string sub; // str is string to search, sub is the substring to search for
	sub = "Nikita";
	vector<size_t> positions1; // holds all the positions that sub occurs within str
	bool isP = false;
	size_t pos = str.find(sub, 0);
	while(pos != string::npos)
	{
	    positions1.push_back(pos);
	    pos = str.find(sub,pos+1);
	}
	sub = "Danil";
	vector<size_t> positions2; // holds all the positions that sub occurs within str

	pos = str.find(sub, 0);
	while(pos != string::npos)
	{
	    positions2.push_back(pos);
	    pos = str.find(sub,pos+1);
	}
	sub = "Ann";
	vector<size_t> positions3; // holds all the positions that sub occurs within str

	 pos = str.find(sub, 0);
	while(pos != string::npos)
	{
	    positions3.push_back(pos);
	    pos = str.find(sub,pos+1);
	}
	sub = "Olya";
	vector<size_t> positions4; // holds all the positions that sub occurs within str

	 pos = str.find(sub, 0);
	while(pos != string::npos)
	{
	    positions4.push_back(pos);
	    pos = str.find(sub,pos+1);
	}
	sub = "Slava";
	vector<size_t> positions5; // holds all the positions that sub occurs within str

	 pos = str.find(sub, 0);
	while(pos != string::npos)
	{
	    positions5.push_back(pos);
	    pos = str.find(sub,pos+1);
	}

	ll aS = positions1.size();
	ll bS = positions2.size();
	ll cS = positions3.size();
	ll dS = positions4.size();
	ll eS = positions5.size();
	if(aS == 1 && bS == 0 && cS == 0 && dS == 0 && eS == 0)
	{
		isP = true;
	}
	else if(aS == 0 && bS == 1 && cS == 0 && dS == 0 && eS == 0)
	{
		isP = true;
	}
	else if(aS == 0 && bS == 0 && cS == 1 && dS == 0 && eS == 0)
	{
		isP = true;
	}
	else if(aS == 0 && bS == 0 && cS == 0 && dS == 1 && eS == 0)
	{
		isP = true;
	}
	else if(aS == 0 && bS == 0 && cS == 0 && dS == 0 && eS == 1)
	{
		isP = true;
	}
	else
	{
		isP = false;
	}
	if(isP)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
