#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[11],i;
    int m,rem,winner=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    while(n!=0)
    {
        bool found=false;
        //cout<<winner<<' '<<n<<endl;
        for(i=0;i<m;i++)
        {
           // cout<<n%a[i]<<' '<<n/a[i]<<endl;
      if(n%a[i]==0 && (n/a[i])%2!=0)
        {
            winner+=(n/a[i]);
          n=(n/a[i]);
            found=true;
           break;

        }
        }

        if(found!=true)
        {
            for(i=0;i<m;i++)
        {
            if((n/a[i])%2==0 && n%a[i]==0)
        {
            winner+=(n/a[i]);
            n=(n/a[i]);
            found=true;
            break;
        }
        else
        {
            found=false;
        }


        }
         if(found==false)
        {
            n=0;
        }


        }



    }
    winner=pow(-1,winner);
        if(winner==1)
            cout<<"Second";
        else
            cout<<"First";

}
