#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q,a,b,d,steps=0,sum,maximum,rem,counter=0,counter1=0,rem1;
    cin>>q;
    while(q--)
    {
        steps=0;
        counter=0;
        counter1=0;
        cin>>a>>b>>d;
        maximum=max(a,b);
        sum=a+b;
        if(d%sum==0)
        {
            steps=(d/sum);
            steps*=2;
        }
        else if((d%sum)%a==0 && a!=1)
        {
            steps=(d/sum);
            steps*=2;
            steps+=1;
        }
        else if((d%sum)%b==0 && b!=1)
        {
            steps=(d/sum);
            steps*=2;
            steps+=1;
        }
        else
        {
            d=(d-(2*maximum));
            if(d>0)
            steps=(d/maximum);
            if(d%maximum!=0 && d>0)
            steps+=1;
            steps+=2;
        }
        cout<<steps<<endl;
    }
}
