#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    long long int a[3],k;

    while(t--)
    {
        long long int moves=0;
        cin>>a[0]>>a[1]>>a[2];
        cin>>k;
        sort(a,a+3);
        if(k<=a[0])
        {
            moves=((k-1)*3)+1;
        }
        else if(k>a[0] && k<=a[1])
        {
            moves=((a[0]*3)+((k-1-a[0])*2)+1);
        }
        else
        {
            moves=((a[0]*3)+((a[1]-a[0])*2)+((k-1-a[1])*1)+1);
        }
        cout<<moves<<endl;


     }

}
