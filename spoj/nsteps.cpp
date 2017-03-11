#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int difference,t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        difference=x-y;

         if(x%2==0 && y%2==0 && difference<=2 && difference>=0)
            cout<<x+y<<'\n';
        else if(x%2==1 && y%2==1 && difference<=2 && difference>=0)
            cout<<x+y-1<<'\n';
        else
            cout<<"No Number\n";

    }
    return 0;
}
