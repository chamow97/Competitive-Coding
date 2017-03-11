#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int i,t,n,k,sum1=0,sum2=0,s1=0,s2=0;
    long int a[100];
    cin>>t;
    while(t--)
    {
        sum1=0,sum2=0,s1=0,s2=0;
        cin>>n>>k;
        for(i=0;i<n;i++)
            cin>>a[i];

            sort(a,a+n);
        for(i=0;i<n;i++)
        {
            if(i<k)
                sum1+=a[i];
            else
                sum2+=a[i];;
        }
        s1=sum1-sum2;
        if(s1<0)
        {
            s1=(s1*(-1));
        }
        sum1=0,sum2=0;
        for(i=0;i<n;i++)
        {
            if(i<(n-k))
                sum1+=a[i];
            else
                sum2+=a[i];
        }
        s2=sum1-sum2;
        if(s2<0)
        {
            s2=(s2*(-1));
        }
        cout<<max(s1,s2)<<"\n";

    }

}
