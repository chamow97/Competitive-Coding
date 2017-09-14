#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long int i,t,n,x,y,minimum,maximum;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        minimum=min(x,y);
        maximum=max(x,y);
        for(i=minimum;i<n;i+=minimum)
        {
            if(i%maximum!=0 )
            {
                cout<<i<<" ";
            }
        }
        cout<<"\n";

    }


}
