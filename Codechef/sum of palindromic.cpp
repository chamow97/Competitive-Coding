#include<iostream>

int t,i,j;
using namespace std;
int sum[100];


int palindrome(int lb,int ub)
{
    int sumofp=0;
    for(j=lb;j<=ub;j++)
    {
        int temp=j;
        int rem,rev=0;
        while(temp)
        {
            rem=temp%10;
            temp/=10;
            rev=(rev*10)+rem;

        }

        if(rev==j)
        {
            sumofp+=j;
        }
    }
    return sumofp;
}

int main()
{
    cin>>t;

    for(i=0;i<t;i++)
    {
        int upperbound, lowerbound;
        cin>>lowerbound;
        cin>>upperbound;

        sum[i]=palindrome(lowerbound,upperbound);

    }
    for(i=0;i<t;i++)
        cout<<sum[i]<<endl;
}
