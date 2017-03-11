#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int t,g,i,n,q,l,m;
    cin>>t;
    while(t--)
    {
        cin>>g;
        while(g--)
        {
            cin>>i>>n>>q;
            m=n/2;

            if(i==q)
                cout<<m<<"\n";
            else
                cout<<n-m<<"\n";
        }
    }

}
