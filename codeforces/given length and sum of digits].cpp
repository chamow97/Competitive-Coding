#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val) for(int j=val-1;j>=0;j--)
#define pb push_back
typedef long long ll;
int main()
{
    ll m,s,number=0,temp,number1=0,t;
    bool found=false;
    cin>>m>>s;
    if(s>m*9)
    {
        cout<<"-1 -1";
    }
    else
    {
        //s-=m;
        rep(i,0,m)
        {
            if(s-9>0)
            {
                number=(number*10)+9;
                s-=9;
            }
            else
            {
                number=(number*10)+(s);
                s-=s;
            }
        }
        temp=number;
        while(temp)
        {
            t=temp%10;
            if(t==0)
            {
                found=true;
                break;
            }
            temp/=10;
            number1=(number1*10)+t;
        }

        if(found==true)
            number1=number;
            if(number1==0 && number==0)
            {
                cout<<"-1 -1";
            }
            else
            {
                cout<<number1<<" "<<number;

            }

    }

    return 0;
}
