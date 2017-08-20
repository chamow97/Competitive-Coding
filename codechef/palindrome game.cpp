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
    ll t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;
        vec freq1(26,0);
        vec freq2(26,0);
        rep(i,0,a.length())
        {
            freq1[a[i] - 'a']++;
        }
        rep(i,0,b.length())
        {
            freq2[b[i] - 'a']++;
        }
        ll countA = 0;
        ll countB = 0;
        rep(i,0,26)
        {
            if(freq1[i] >= 1 && freq2[i] == 0)
            {
                ++countA;
            }
            if(freq2[i] >= 1 && freq1[i] == 0)
            {
                ++countB;
            }
        }
        if(countA == a.length() && countB == b.length())
        {
            cout<<"B\n";
        }
        else if(countA == a.length())
        {
            cout<<"B\n";
        }
        else if(countB == b.length())
        {
            cout<<"A\n";
        }
        else if(countA != a.length() && countB != b.length())
        {
            if(countA > countB)
            {
                cout<<"A\n";
            }
            else
            {
                cout<<"B\n";
            }

        }
    }


	return 0;
}
