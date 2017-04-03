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

ll BSEarch(vector<ll> &tail, ll low, ll high, ll key)
{
    ll mid;
    while(high - low > 0)
    {
        mid = low + (high - low)/2;
        if(tail[mid] >= key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

ll LIS(vector<ll> &arr)
{
    ll answer = 1;
    vector<ll> tail(arr.size(),0);
    tail[0] = arr[0];
    rep(i,1,arr.size())
    {
        if(arr[i] < tail[0])
        {
            tail[0] = arr[i];
        }
        else if(arr[i] > tail[answer - 1])
        {
            tail[answer++] = arr[i];
        }
        else
        {
            tail[BSEarch(tail, -1, answer-1, arr[i])] = arr[i];
        }

    }
    return answer;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    rep(i,0,n)
    {
        cin>>arr[i];
    }
	cout<<LIS(arr);
	return 0;
}
