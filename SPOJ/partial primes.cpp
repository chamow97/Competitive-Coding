#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,a,b,i,j,pos=-1;
    bool arr[20000000];
    cin>>t;
    while(t--)
    {
        pos=-1;
        cin>>a;
       cin>>b;
        for(i=0;i<=20000000;i++)
        {
            arr[i]=false;
        }

        //cout<<b<<endl;
       // cout<<a<<b;
        for(i=a;i<=b;i++)
        {
            for(j=i*2;j<=(b*2);j+=i)
            {
                arr[j]=true;
            }
        }
        //cout<<b;
        for(i=b+1;i<=b*2;i++)
        {
            if(arr[i]==false)
            {
                pos=i;
                break;
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}
