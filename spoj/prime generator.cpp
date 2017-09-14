#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxi 1000000000
ll i,j;
ll sq1=sqrt(maxi);
ll sq2=sqrt(sq1);
int temp=sq1;
char prime[maxi+5];
void seive()
{
    memset(prime,1,sizeof(prime));
    prime[0]=0;
    prime[1]=0;
    for(i=2;i<=sq2;i++)
    {
        if(prime[i]==1)
        {
            for(j=i*i;j<=sq1;j+=i)
            {
                prime[j]=0;
            }
        }
    }

}
void segmented(ll m,ll n)
{
    ll lim=sqrt(n);
    for(i=2;i<=lim;i++)
    {
        if(prime[i]==1)
        {
            for(j=m-m%i;j<=n;j+=i)
            {
                if(j>=m && j!=i && prime[j]==1)
                {
                    prime[j]=0;
                }
            }
        }
    }

}
int main()
{
    seive();
    ll t,m,n;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        if(n>sq2)
        {
            segmented(m,n);
        }
            for(i=m;i<=n;i++)
            {
                if(prime[i]==1)
                {
                    cout<<i<<endl;
                }
            }
            cout<<endl;
    }

}
