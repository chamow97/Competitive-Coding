#include<iostream>

using namespace std;
int main()
{
    int n,i=0;

    cin>>n;
    int a[n*2];
    cout<<endl;
    for(i=0;i<n*2;i++)
    {
        cin>>a[i];

    }
    for(i=0;i<n*2;i+=2)
    {
        int c,d;
        int l=a[i];
        int b=a[i+1];
        if(l>b)
        {
            c=l;
            d=b;
        }
        else
            {
                c=b;
                d=l;
            }
        int sq=0;
        c=c-d;
        ++sq;
        sq+=(d/c);
        cout<<endl<<sq;
    }

}
