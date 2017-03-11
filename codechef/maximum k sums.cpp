#include<bits/stdc++.h>


using namespace std;

long b[100000],k;
long elements=0;

void subarry(long a[100000],long start,long n)
{
    long j,total=((n*(n+1))/2),sum=0,i;
    k=0;
if(elements<=total)
{
    for(j=0;j<n;j++)
    {
    sum=0;
    b[k]=0;
    for(i=0;i<start;i++)
        sum+=a[i+j];
    cout<<sum<<' ';
    k++;

    }
    subarry(a,start+1,n-1);
}

}


int main()
{
    long total=0,start=1,i,n,k,a[100000];
    cin>>n>>k;
    total=((n*(n+1))/2);
    for(i=0;i<n;i++)
        cin>>a[i];
    subarry(a,start,n);
   //sort(b,b+total);
    //for(i=0;i<total;i++)
       // cout<<b[i]<<' ';

}
