#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v[]={1,3,5};
    int min[1000];
    min[0]=0;
    int i,j,s=3;
    for(i=1;i<=s;i++)
    {
        min[i]=INT_MAX;
        for(j=0;j<3;j++)
        {
            if(v[j]<=i && (min[i-v[j]]+1<min[i]))
                min[i]=min[i-v[j]]+1;
        }
    }
    cout<<min[s];

}
