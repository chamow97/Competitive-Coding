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
vector<string> dictionary;
vector<string> newDictionary;
bool icompare_pred(unsigned char a, unsigned char b)
{
    return std::tolower(a) == std::tolower(b);
}

bool icompare(std::string const& a, std::string const& b)
{
    if (a.length()==b.length()) {
        return std::equal(b.begin(), b.end(),
                           a.begin(), icompare_pred);
    }
    else {
        return false;
    }
}
void cleanDictionary()
{
	rep(i,0,3)
	{
		string newString = "";
		rep(j,0,dictionary[i].length())
		{
			if(dictionary[i][j] != ';' && dictionary[i][j] != '-' && dictionary[i][j] != '_')
			{
				newString += dictionary[i][j];
			}
		}
		newDictionary.pb(newString);
	}
}	
string cleanString(string current)
{
	string newString = "";
	rep(i,0,current.length())
	{
		if(current[i] != ';' && current[i] != '-' && current[i] != '_')
		{
			newString += current[i];
		}
	}
	return newString;
}
void checkString(string current)
{
	vector<string> allCombo;
	allCombo.pb(newDictionary[0] + newDictionary[1] + newDictionary[2]);
	allCombo.pb(newDictionary[0] + newDictionary[2] + newDictionary[1]);
	allCombo.pb(newDictionary[1] + newDictionary[0] + newDictionary[2]);
	allCombo.pb(newDictionary[1] + newDictionary[2] + newDictionary[0]);
	allCombo.pb(newDictionary[2] + newDictionary[0] + newDictionary[1]);
	allCombo.pb(newDictionary[2] + newDictionary[1] + newDictionary[0]);
	// rep(i,0,allCombo.size())
	// {
	// 	cout << allCombo[i]<<'\n';
	// }
	rep(i,0,allCombo.size())
	{
		if(icompare(current, allCombo[i]))
		{
			cout << "ACC\n";
			return;
		}
	}
	cout << "WA\n";
	return;

}

int main()
{
	fastread;
	rep(i,0,3)
	{
		string str;
		cin >> str;
		dictionary.pb(str);
	}
	cleanDictionary();
	ll q;
	cin >> q;
	while(q--)
	{
		string current;
		cin >> current;
		current = cleanString(current);
		checkString(current);
	}
	return 0;
}
