//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
bool checkPrimeNumber(ll n)
{
  bool flag = false;

  for(ll i = 2; i <= n/2; ++i)
  {
      if(n%i == 0)
      {
          flag = true;
          break;
      }
  }
  return flag;
}
int main()
{
    ll n,arr[100000],brr[100001],k,a,b,sum=0;
    n = readInt();
    rep(i,0,100001)
    {
        brr[i] = 0;
    }
    rep(i,0,n)
    {
        arr[i] = readInt();
        brr[arr[i]]++;
    }
    k  = readInt();
    while(k--)
    {
        ll j;
        sum = 0;
        a = readInt();
        b = readInt();
        for(j=sqrt(a);j>=1;j--)
        {

            if(a%j == 0)
            {
                sum += brr[j];
                if(a/j != j)
                sum += brr[a/j];
            }
            if(sum>=b)
            {
                break;
            }

        }

        if(sum >= b)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }
    return 0;
}
