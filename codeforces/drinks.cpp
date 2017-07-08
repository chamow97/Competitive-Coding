#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long i,n,a;
    float answer=0.0,temp;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        temp=a;
        answer+=(temp/100);
    }
    cout<<(answer*100)/n<<'\n';


}
