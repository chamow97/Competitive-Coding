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
    ll n, k;
    n = read_int();
    k = read_int();
    ll mat[n][n];
    if(k>(n*n))
    {
        cout<<-1;
        return 0;
    }
    else
    {
        if(k == 0)
        {
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    mat[i][j] = 0;
                }
            }
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    mat[i][j] = 0;
                }
            }
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    if(mat[i][j] != 1){
                    if(i == j && k > 0)
                    {
                        mat[i][j] = 1;
                        --k;
                    }
                    else if(k > 1 && i!=j)
                    {
                        mat[i][j] = 1;
                        mat[j][i] = 1;
                        k -= 2;
                    }
                   }
                }
            }
            if(k == 1)
            {
                cout<<-1;
                return 0;
            }
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
	return 0;
}
