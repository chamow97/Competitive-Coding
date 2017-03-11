#include<bits/stdc++.h>
using namespace std;
int main()
{
    int j,a[3],c[3],b[3],m,i;
    cin>>a[0]>>a[1]>>a[2];
    cin>>c[0]>>c[1]>>c[2];
    cin>>m;
    b[0]=a[0];
    b[1]=a[1];
    b[2]=a[2];
    sort(b,b+3);
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(i!=j && b[i]==a[j])
            {
                swap(c[i],c[j]);
            }
        }
    }


}
