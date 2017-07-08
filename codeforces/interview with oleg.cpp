#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val) for(int j=val-1;j>=0;j--)
#define pb push_back
typedef long long ll;
int main()
{
    ll n,i,j;
    char str[102];
    cin>>n;
    cin>>str;
    rep(i,0,n)
    {
        if(str[i]!='o')
        {
            cout<<str[i];
        }
        else
        {
            bool flag=false;
            for(j=i;j<n-2;j+=2)
            {
                if(str[j]=='o' && str[j+1]=='g' && str[j+2]=='o')
                {
                    flag=true;
                }
                else
                {
                    break;
                }
            }
            if(flag==true)
            {
                cout<<"***";
                i=j;
            }
            else
            {
                cout<<str[i];
            }
        }
    }
    return 0;
}
