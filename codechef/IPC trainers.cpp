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

struct num{
	ll start, days, sadness;
};
bool operator<(const num &a, const num &b)
{
	
	return a.sadness < b.sadness;
}

bool myFunc(num &a, num &b)
{
	return a.start < b.start;
}
int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, d;
		ll sum = 0;
		cin>>n>>d;
		priority_queue<num> p;
		vector< num > arr;
		rep(i,0,n)
		{
			num temp;
			cin>>temp.start>>temp.days>>temp.sadness;
			arr.pb(temp);
			sum += (temp.sadness * temp.days);
		}
		sort(arr.begin(), arr.end(), myFunc);
		ll curr = arr[0].start;
		p.push(arr[0]);
		ll i = 1;
		ll ans = 0;
		while(curr <= d && i < n)
		{
			while(arr[i].start <= curr)
			{
				p.push(arr[i]);
				i++;
				if(i >= n)
				{
					break;
				}
			}	
			if(!p.empty())
			{
				num temp = p.top();
				p.pop();
				ans += (temp.sadness);
				// cout<<ans<<'\n';
				temp.days--;
				if(temp.days > 0)
				{
					p.push(temp);
				}
			}		
			
			++curr;
			// cout<<"SAD";
		}
		while(curr <= d)
		{
			// cout<<"MA";
			if(!p.empty())
			{
				num temp = p.top();
				p.pop();
				ans += (temp.sadness);
				// cout<<ans<<'\n';
				temp.days--;
				if(temp.days > 0)
				{
					p.push(temp);
				}
			}	
			++curr;
		}
		cout<<sum - ans<<'\n';

		
	}
	
	return 0;
}