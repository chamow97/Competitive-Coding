#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,cards=0;
    float temp,a,ans;
    for(;;)
    {


        cards=0;
        ans=0.00;
        cin>>a;
        if(a==0.00)
            break;
        else
        {
           for(i=2;;i++)
           {
               float t=i;
               ans+=(1/t);
               temp=a/(1.0000000);
              if(ans>=temp)
                break;
           }
           cout<<i-1<<" cards(s)\n";

        }
    }
}
