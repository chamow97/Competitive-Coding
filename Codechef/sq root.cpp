#include<iostream>

using namespace std;

int main()
{

    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i <n; i++)
    {
        cin>>a[i];
    }
    for( i=0;i<n;i++)
    {
        for(j=1; ;j++)
        {
            if((j*j)>a[i])
            {
                cout<<(j-1)<<endl;;
                goto next;
            }
        }
        next:;
    }

}
