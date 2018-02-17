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
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


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

void solve()
{
  ll k, d0, d1;
  cin >> k >> d0 >> d1;
  ll counter = 0;
  ll ans = d0 + d1;
  ll temp = ans;
  ll arr[] = {4, 8, 6, 2, 4, 8, 6, 2};
  k -= 2;
  while(k > 0)
  {
    temp %= 10;
    if(temp == 4 || temp == 8 || temp == 6 || temp == 2 || temp == 0)
    {
      break;
    }
    else
    {
      ++counter;
      --k;
      ans += temp;
      temp = (ans) % 10;
    }
  }
  if(temp == 0)
  {
    if(ans % 3 == 0)
    {
      cout << "YES";
    }
    else
    {
      cout << "NO";
    }
  }
  else if(k <= 0)
  {
    if(ans % 3 == 0)
    {
      cout << "YES";
    }
    else
    {
      cout << "NO";
    }
  }
  else
  {
    ll ptr = 0;
    if(temp == 4)
    {
      ptr = 0;
    }
    else if(temp == 8)
    {
      ptr = 1;
    }
    else if(temp == 6)
    {
      ptr = 2;
    }
    else
    {
      ptr = 3;
    }
    while(ptr < 4 && k > 0)
    {
      ans += arr[ptr++];
      --k;
    }
    if(k == 0)
    {
      if(ans % 3 == 0)
      {
        cout << "YES";
      }
      else
      {
        cout << "NO";
      }
      return;
    }
    k -= (4 - ptr);
    ll quotient = k/4;
    ans += (quotient * 20);
    ll remainder = k % 4; 
    rep(i,0,remainder)
    {
      ans += arr[i];
    }
    if(ans % 3 == 0)
    {
      cout << "YES";
    }
    else
    {
      cout << "NO";
    }

  }

}

int main()
{
  fastread;
  ll t;
  cin >> t;
  while(t--)
  {
    solve();
    cout << '\n';
  }
  return 0;
}
