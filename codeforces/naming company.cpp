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
	string s1, s2, s3;
	cin>>s1>>s2;
	sort(s1.begin(), s1.end());
	sort(s2.rbegin(), s2.rend());
	//reverse(s2.begin(), s2.end());
	ll n = s1.length();

	// since both are sorted accordingly, start position for filling is same
	ll start1 = 0, start2 = 0;
	
	// if string size is odd, first player has one extra chance
	ll end1 = ((n+1)/2)-1;
	ll end2 = (n/2)-1;
	
	//counter for counting no of operations
	ll counter = 0;
	string ans(n, ' ');
	ll front = 0, back = n-1;
	while(1)
	{
		//first player
		// ie. intuitive case
		if(s1[start1] < s2[start2])
		{
			ans[front++] = s1[start1++];
		}
		else
		{
			ans[back--] = s1[end1--];
		}
		++counter;
		if(counter == n)
		{
			break;
		}

		//second player

		if(s2[start2] > s1[start1])
		{
			ans[front++] = s2[start2++];
		}
		else
		{
			ans[back--] = s2[end2--];
		}
		++counter;
		if(counter == n)
		{
			break;
		}
		//cout<<ans<<endl;
	}
	rep(i,0,n)
	{
		cout<<ans[i];
	}

	return 0;
}