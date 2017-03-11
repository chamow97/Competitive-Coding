#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    long int c[n],sum1=0,sum2=0,i;
    for(i=0;i<n;i++)
    {

        cin>>c[i];
        sum1+=c[i];
        sum2+=(i+1);
    }

    if(sum1==sum2)
        cout<<"YES";
    else
        cout<<"NO";

}

