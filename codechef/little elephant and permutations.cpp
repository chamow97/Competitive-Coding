#include<iostream>

using namespace std;


int main()
{
    int i,j,t,n,a[100],count1=0,count2=0;
    cin>>t;
    while(t--)
    {
        count1=0;
        count2=0;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        for(i=0;i<n;i++)
        {
            if(i!=n-1)
            {
                if(a[i]>a[i+1])
                    ++count1;
            }
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                    ++count2;

            }
        }
        if(count1==count2)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
}
