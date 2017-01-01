#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    bool visited=false;
    long long n,len,i,counter1=0,counter2=0;
    cin>>n;
    while(n--)
    {
        counter1=0;counter2=0,flag=0;
        visited=false;
        cin>>a>>b;
        for(i=0;i<len;i++)
        {
            if(a[i]==b[i] && a[i]=='#')
            {
                cout<<"No\n\n";
                flag=1;
                break;
            }
            if(a[i]=='#')
                pos1=i;
            if(b[i]=='#')
                pos2=i;
        }
        if(flag!=0)
        {
            if(pos1<pos2)
            {
                arr=2;
            }
            else
            {
                arr=1;
            }
        }



    }
}
