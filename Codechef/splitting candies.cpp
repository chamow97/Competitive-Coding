#include<iostream>

using namespace std;

int main()
{
    int t;
    long long int students,teacher,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==0)

        {
            teacher=n;
            students=0;
        }
        else if(n==0)
        {
            teacher=0;
            students=0;
        }
        else
        {
            students=(n/k);
            teacher=n%k;
        }
        cout<<students<<" "<<teacher<<"\n";
    }
}
