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

/*-------------------------------------------------------- */

int main()
{
	fastread;
	string temp, s;
	vec good(26,0);
	cin>>s;
	rep(i,0,s.length())
	{
		good[s[i] - 'a']++;
	}
	cin>>temp;
	ll q, questions = 0;
	rep(i,0,temp.length())
	{
		if(temp[i] == '*')
		{
			++questions;
		}
	}
	cin>>q;
	while(q--)
	{
		string str = temp;
		string query;
		cin>>query;

		if(questions == 0)
		{
			if(query.length() == str.length())
			{
				bool isPossible = true;
				rep(i,0,query.length())
				{
					if(str[i] != query[i])
					{
						if(str[i] == '?')
						{
							if(good[query[i] - 'a'] >= 1)
							{
								str[i] = query[i];
							}
						}
					}
				}
				rep(i,0,query.length())
				{
					if(query[i] != str[i])
					{
						isPossible = false;
						break;
					}
				}
				if(isPossible == false)
				{
					cout<<"NO\n";
				}
				else
				{
					cout<<"YES\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else if(questions == 1)
		{
			if(query.length() < str.length())
			{
				ll i = 0, j = 0;
				bool isPossible = true;
				while(i < str.length() && j < query.length())
				{
					if(str[i] != query[j])
					{
						if(str[i] == '?')
						{
							if(good[query[j] - 'a'] >= 1)
							{
								str[i] = query[j];
							}
							else
							{
								isPossible = false;
								break;
							}
						}
						else if(str[i] == '*')
						{
							i++;
						}
						else
						{
							isPossible = false;
							break;
						}
					}
					i++;
					j++;
				}
				if(isPossible == true && (i <= j))
				{
					cout<<"YES\n";
				}
				else
				{
					cout<<"NO\n";
				}

			}
			else if(query.length() == str.length())
			{
				bool isPossible = true;
				rep(i,0,query.length())
				{
					if(str[i] != query[i])
					{
						if(str[i] == '?')
						{
							if(good[query[i] - 'a'] >= 1)
							{
								str[i] = query[i];
							}
						}
						else if(str[i] == '*')
						{
							if(good[query[i] - 'a'] == 0)
							{
								str[i] = query[i];
							}
						}
					}
				}
				rep(i,0,query.length())
				{
					if(query[i] != str[i])
					{
						isPossible = false;
						break;
					}
				}
				if(isPossible == true)
				{
					cout<<"YES\n";
				}
				else
				{
					cout<<"NO\n";
				}

			}
			else if(query.length() > str.length())
			{
				ll i = 0;
				ll j = 0;
				bool isPossible = true;
				while(i < str.length() && j < query.length())
				{
					if(str[i] != query[j])
					{
						if(str[i] == '?')
						{
							if(good[query[j] - 'a'] >= 1)
							{
								str[i] = query[j];
							}
							else
							{
								isPossible = false;
								break;
							}
						}
						else if(str[i] == '*')
						{
							ll val = query.length() - str.length() + 1;
							rep(k,0,val)
							{
								if(good[query[j] - 'a'] == 0)
								{
									//if(i != val-1)
									++j;
								}
								else
								{
									isPossible = false;
									break;
								}
							}
							--j;
						}
						else
						{
							isPossible = false;
						}

					}
					i++;
					j++;
				}
				if(isPossible == true  && i <= j)
				{
					cout<<"YES\n";
				}
				else
				{
					cout<<"NO\n";
				}
			}
			else
			{
				cout<<"NO\n";
			}
		}
		else
		{
			cout<<"NO\n";
		}

	}
	return 0;
}