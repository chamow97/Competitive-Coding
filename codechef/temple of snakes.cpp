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

int main()
{
	ll t, n;
	t = read_int();
	while(t--)
	{
		n = read_int();
		ll maximum = 0;
		vec arr(n,0);
		// vec prefix(n,0);
		ll sum = 0;
		rep(i,0,n)
		{
			arr[i] = read_int();
			maximum = max(maximum, arr[i]);
			sum += arr[i];
		}
		// sort(arr.begin(), arr.end());
		ll low = 1;
		ll high = (n+1)/2;
		ll mid;
		while(low < high)
		{
			mid = (low+high+1)/2;
			ll current = 1;
			ll counter = 0;
			bool flag = false;
			ll i =0;
			while(i < n)
			{
				// cout<<i<<" ";
				if(counter < mid-1)
				{
					if(arr[i] >= current)
					{
						i++;
						++current;
						++counter;
					}
					else
					{
						current = arr[i]+1;
						counter = arr[i]; 
						i++;
					}
				}
				else if(counter >= mid-1)
				{
					if(arr[i] >= current)
					{
						i++;
						--current;
						++counter;
					}
					else
					{
						current = arr[i]+1;
						counter = (arr[i]);
						i++;
					}

				}
				if(counter == ((mid*2)-1))
				{
					flag = true;
					break;
				}
				
			}
			if(flag == true)
			{
				low = mid;
			}		
			else
			{
				high = mid-1;
			}
		}
		ll ans = (low);
		--low;
		ans += ((low*(low+1)));
		cout<<sum-ans<<"\n";

	}
	return 0;
}