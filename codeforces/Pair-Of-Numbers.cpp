//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;
 
/*-------------------------------------------------------- */

#define ll long long
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second
 
/*-------------------------------------------------------- */
 
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;
 
 
/*-------------------------------------------------------- */
 
int gcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}
 
int lcm(int a, int b)
{
	return ((a*b)/gcd(a,b));
}
 
/*-------------------------------------------------------- */
 
const int MAXN = 3e5 + 10;
int n;
vec arr(MAXN, 0);
vector< vector<ll> > sparseTableMin(MAXN, vector<ll> (20));
vector< vector<ll> > sparseTableGCD(MAXN, vector<ll> (20));
map<int, vec> ansMap;
int ans = 0;

void preprocessTable()
{
	for(int i = 0; i < n; i++)
	{
		sparseTableMin[i][0] = arr[i];
		sparseTableGCD[i][0] = arr[i];
	}
	for(int j = 1; 1 << j <= n; j++)
	{
		for(int i = 0; i + (1 << j) - 1 < n; i++)
		{
			sparseTableMin[i][j] = min(sparseTableMin[i][j - 1], sparseTableMin[i + (1 << (j - 1))][j - 1]);
			sparseTableGCD[i][j] = gcd(sparseTableGCD[i][j - 1], sparseTableGCD[i + (1 << (j - 1))][j - 1]);			
		}
	}
}

bool isPossible(ll low, ll high)
{
	ll total = high - low + 1;
	ll logVal = log2(total);
	return (min(sparseTableMin[low][logVal], sparseTableMin[low + total - (1 << logVal)][logVal]) == gcd(sparseTableGCD[low][logVal], sparseTableGCD[low + total - (1 << logVal)][logVal]));
}

void binarySearch(int low, int high)
{
	if(high < low)
	{
		return;
	}
	int mid = (low + high) / 2;
	bool possible = false;
	rep(i,0,n)
	{
		int till = i + mid;
		if(till >= n)
		{
			break;
		}
		if(isPossible(i, till))
		{
			possible = true;
			ans = mid;
			ansMap[mid].push_back(i);
		}
	}
	if(possible)
	{
		low = mid + 1;
	}
	else
	{
		high = mid - 1;
	}
	binarySearch(low, high);
}

int main()
{
	fastread;
	cin >> n;
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	preprocessTable();
	binarySearch(0, n - 1);	
	cout << ansMap[ans].size() << ' ' << ans << '\n';
	for(int i : ansMap[ans])
	{
		cout << i + 1 << ' ';
	}
	return 0;
}