#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
typedef long long ll;
ll a[1000][1000];
ll readInt () {
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
int main()
{
    ll n,m,counter=0,i,j;
    n=readInt();
    m=readInt();
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            a[i][j]=readInt();
        }
    }
    rep(i,0,n)
    {
        bool valid=false;
        rep(j,0,m)
        {
             if(valid==true && a[i][j]!=1)
            {
                ++counter;
            }
            if(a[i][j]==1)
            {
                valid=true;
            }

        }

    }
    rep(i,0,n)
    {
        bool valid=false;
        per(j,m-1,0)
        {
            if(valid==true && a[i][j]!=1)
            {
                ++counter;
            }
             if(a[i][j]==1)
            {
                valid=true;
            }



        }
    }

rep(i,0,m)
    {
         bool valid=false;
         rep(j,0,n)

            {

            if(valid==true && a[j][i]!=1)
            {
                ++counter;
            }

           if(a[j][i]==1)
            {
                valid=true;
            }

         }
    }

   rep(i,0,m)
    {
        bool valid=false;
        per(j,n-1,0)
        {
            if(valid==true && a[j][i]!=1)
            {
                ++counter;
            }

           if(a[j][i]==1)
            {
                valid=true;
            }

        }
    }
cout<<counter;
    return 0;
}
