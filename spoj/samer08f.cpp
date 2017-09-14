#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,result=0;
    while(1)
    {
        result=0;
        cin>>n;
        if(n==0)
            break;

        else
        {
            while(n!=0)
            {
                result+=(n*n);
                --n;
            }
            cout<<result<<'\n';
        }

    }

}
