#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[1000001],i,j,q,f,t,frequency,temp;
    scanf("%lli",&n);
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    scanf("%lli",&q);

    for(i=0;i<q;i++)
    {
        scanf("%lli%lli",&t,&f);
        frequency=1;
        temp=a[0];
        bool found=false;
        for(j=1;j<n;j++)
        {

            if(a[j]==a[j-1])
            {
                frequency+=1;
                temp=a[j];
            }
            else
            {
                frequency=0;
            }
            if(frequency>=f)
            {
                found = true;
                cout<<temp<<'\n';
                break;

            }
        }
        if(found==false)
        {
            cout<<"0\n";
        }
    }

}
