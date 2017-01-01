#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int cut=0,i,n,w,l,c[100],d[100],b[100],count=0,pos=0;
    cin>>n>>w>>l;
    for(i=0;i<n;i++)
    {
        cin>>c[i]>>d[i];
        b[i]=c[i]+d[i];

    }
    sort(b+n,b);
    sort(d+n,d);

    while(count<w)
    {
        count+=((w)*(l/d[pos])+b[pos]);
        if(((l/d[pos]))<w)
        cut=(l/d[pos])+1;
        else
            cut=(l/d[pos]);
        ++pos;

    }
    cout<<cut;

}
