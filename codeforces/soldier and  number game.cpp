#include <iostream>
using namespace std;
#define ll long long

#define maxn 5000001

ll spf[maxn+1];
ll result[maxn+1];
void seive()
{
    spf[1] = 1;
    for(ll i = 2; i < maxn; i++)
    {
        spf[i] = i;
    }
    for(ll i = 4; i < maxn; i+=2)
    {
        spf[i] = 2;
    }
    for(ll i = 3; i*i < maxn; i++)
    {
        if(spf[i] == i)
        {
            for(ll j = i*i; j < maxn; j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

void getPrimeFactorLength()
{
    for(ll i = 1; i < maxn; i++)
    {
        ll temp = i;
        ll counter = 0;
        while(temp != 1)
        {
            counter++;
            temp = temp / spf[temp];
        }
        result[i] = counter;
    }
    for(ll i = 1; i < maxn; i++)
    {
        result[i] += result[i-1];
    }
}

int main()
{
    ll t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    getPrimeFactorLength();
    cin>>t;
    while(t--)
    {
        ll a, b;
        cin>>a>>b;
        cout<<result[a] - result[b]<<'\n';
    }
    return 0;
    
}