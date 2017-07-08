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
bool palin(ll n)
{
    ll temp = n;
    ll rev = 0;
    while(temp)
    {
        ll t = temp%10;
        temp /= 10;
        rev = (rev*10) + t;
    }
    if(rev == n)
    {
        return true;
    }
    return false;
}
int main()
{
	fastread;
    int hour, minute;
    scanf("%d : %d",&hour,&minute);
    ll a[4];
    a[0] = hour/10;
    a[1] = hour%10;
    a[2] = minute/10;
    a[3] = minute%10;
    ll counter = 0;
    while(1)
    {
        if(a[0] == a[3] && a[1] == a[2])
        {
            break;
        }
        a[3]++;
        if(a[3] > 9)
        {
            a[3] = 0;
            a[2]++;
        }
        if(a[2] > 5)
        {
            a[2] = 0;
            a[1]++;
        }
        if(a[1] > 3 && a[0] >= 2)
        {
            a[1] = 0;
            a[0] = 0;
        }
        if(a[1] > 9)
        {
            a[1] = 0;
            a[0]++;
        }
        ++counter;
//        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    }
    cout<<counter;

	return 0;
}
