#include<iostream>

using namespace std;

int main()
{
    long long int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4==0)
            cout<<"Second\n";
        else
            cout<<"First\n";
    }
}
