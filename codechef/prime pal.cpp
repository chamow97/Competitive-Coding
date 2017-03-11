#include<iostream>

using namespace std;

int main()
{

long long int n,i,j,duplicate,flag2=0,temp,rev=0;

cin>>n;


for(i=n+1;;i++)
{
flag2=0;
    int flag=0;
    if(i%2!=0)
    {
         duplicate=i;
    while(duplicate!=0)
    {
    temp=duplicate%10;
    duplicate/=10;
    rev=(rev*10)+temp;
    }
    if(rev==i)
    flag2=1;

        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
    }
    if(flag==1 && flag2==1)
    {
        cout<<i<<"\n";
        break;
    }
}

}
