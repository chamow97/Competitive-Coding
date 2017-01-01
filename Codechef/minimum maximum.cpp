#include<iostream>

using namespace std;
int n,testcase=0,t=0,sum=0,sum1=0;
int b[12],c[12];
void small(int a[100])
{
    int temp=a[0];

    for(int i=0;i<n-1;i++)
    {
        if(temp<=a[i+1])
        {

            sum+=temp;
        }
        else
        {
            temp=a[i+1];

            sum+=temp;

        }


    }
    int temp1=a[n-1];
    for(int i=n-1;i>0;i--)
    {
        if(temp<=a[i-1])
        {
            sum1+=temp;
        }
        else
        {
            temp=a[i-1];
            sum1+=temp;
        }
    }
    c[testcase]=sum1;
    b[testcase]=sum;
    ++testcase;
}


int main()
{

    cin>>t;
    if(t>10 && t<0)
        goto exit;

    for(int run=0;run<t;run++)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        small(a);
        sum=sum1=0;
    }
    if(sum<sum1)
    {

        for(int i=0;i<t;i++)
        cout<<b[i]<<endl;
    }
    else
    {
        for(int i=0;i<t;i++)
        cout<<c[i]<<endl;
    }


    exit: ;
}
