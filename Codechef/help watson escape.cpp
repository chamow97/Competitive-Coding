#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;


int main()
{
    long long int t,n,k,result;
    cin>>t;

    while(t--)
    {

        cin>>n>>k;

            result=(pow(k-1,(n-1)/2));
            if((n-1)%2==0)
            result=(result*result);
        else
            result=(result*result*(n-1));





        cout<<result*k<<"\n";


    }
}

