#include<iostream>
#include<limits.h>

using namespace std;

int main()
{
    int a[10]={100,555,3,5,333,2,6,66654,6};
    int f=INT_MAX;
    int s=INT_MAX;
    for(int i=0;i<9;i++)
    {
        if(a[i]<f )

        {s=f;
            f=a[i];

        }
        else if(a[i]<s && a[i]!=f)
        {
            s=a[i];

        }
    }
    cout<<s<<" "<<INT_MAX;
}
