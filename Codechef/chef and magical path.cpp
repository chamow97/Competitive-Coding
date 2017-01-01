#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long int t,n,m,maximum,minimum;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        minimum=min(n,m);
        maximum=max(n,m);

        if(minimum == 1 && maximum ==2)
            cout<<"Yes\n";
        else if(minimum>=2 &&(n%2==0 || m%2==0))
            cout<<"Yes\n";
        else cout<<"No\n";
    }
}

