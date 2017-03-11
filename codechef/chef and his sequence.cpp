#include<iostream>

using namespace std;
int main()
{
int a,b;
int n,i,j;
cin>>n;

for(int z=0;z<n;z++)
{

cin>>a;
int c[a];
for(i=0;i<a;i++)
{
     cin>>c[i];
}

cin>>b;
int d[b];
for(j=0;j<b;j++)
{
    cin>>d[j];

}
int flag=1;
for(j=0;j<b;j++)
{
    for(i=0;i<a;i++)
    {
        if(d[j] == c[i])
            {flag=1;
            break;}
        else{flag=0;}
    }
}
if(flag==0)
    cout<<"No\n";
else cout<<"Yes\n";
}
}
