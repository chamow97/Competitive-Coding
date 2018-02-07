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

int main()
{
    fastread;
    //saw editorial
    ll n, k, m = 0;
    cin >> n >> k;
    ll counter = 0;
    map<ll, ll> cnt;
    rep(i,0,64)
    {
        if((n >> i) & 1)
        {
            ++counter;
            cnt[i]++;
        }
    }
    if(counter > k)
    {
        cout << "No";
        return 0;
    }
    else
    {
        per(i,63,-63)
        {
            if(counter + cnt[i] <= k)
            {
                counter += cnt[i];
                cnt[i-1] += cnt[i] * 2;
                cnt[i] = 0;
            }
            else
            {
                break;
            }
        }
        cout << "Yes\n";
        multiset<ll> ms;
        per(i,63,-63)
        {
            rep(j,0,cnt[i])
            {
                // cout << i << ' ';
                ms.insert(i);
            }
        }
        while(ms.size() < k)
        {
            ll now = *(ms.begin());
            ms.erase(ms.begin());
            ms.insert(now - 1);
            ms.insert(now - 1);
        }
        for(auto it = ms.rbegin(); it != ms.rend(); it++)
        {
            cout << *it << ' ';
        }
    }
    return 0;
}
