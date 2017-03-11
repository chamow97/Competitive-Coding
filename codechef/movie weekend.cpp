#include<iostream>

using namespace std;

int main()
{
    int t,n,l[100],r[100],maximum,pos,i,ratingpos,rating;
    cin>>t;
    while(t--)
    {
        maximum=-1,pos=-1,ratingpos=-1,rating=-1;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>l[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>r[i];

        }
        for(i=n-1;i>=0;i--)
        {
            if(maximum<=(r[i]*l[i]))
            {
                maximum=(r[i]*l[i]);
                pos=i;
            }

        }
       for(i=n-1;i>=0;i--)
       {
           if((r[i]*l[i]==maximum)&&(rating<=r[i]))
           {
               rating=r[i];
               ratingpos=i;
           }
       }
       cout<<ratingpos+1<<"\n";
    }

}
