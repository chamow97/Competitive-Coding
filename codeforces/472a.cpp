#include<bits/stdc++.h>

using namespace std;


int main()
{
    long int n,temp;
    cin>>n;
    temp=n/2;
    if(n%2==0)
        cout<<temp<<" "<<temp;
    else
        cout<<temp-1<<" "<<temp+1;
}
