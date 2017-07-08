//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */
ll read_int(){
	char r;
	bool start=false,neg=false;
	ll ret=0;
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


int main()
{
    ll n, m, k, temp, u, v;
    n  = read_int();
    m = read_int();
    k = read_int();
    boolean arr(1000001, false);
    rep(i,0,m)
    {
        temp = read_int();
        arr[temp] = true;
    }
    ll current = 1;
    if(arr[1] == true)
    {
        cout<<1<<endl;
        return 0;
    }
    rep(i,0,k)
    {
        u = read_int();
        v = read_int();
        if(current == u)
        {
            current = v;
        }
        else if(current == v)
        {
            current = u;
        }
        if(arr[current] == true)
        {
            cout<<current<<endl;
            return 0;
        }
    }
    cout<<current;



	return 0;
}
