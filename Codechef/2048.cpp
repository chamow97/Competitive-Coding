#include<iostream>


using namespace std;

long power(long temp,long n)
{
    if(n==0)
        return 1;
    if(n==1)
       return temp;

    long result=power(2,n/2);
    return result*result*power(2,n%2);

}

int main()
{

    long t,n,temporary=0,count=0;

    cin>>t;
    while(t--)
    {
        count=0;

        cin>>n;
        temporary=n;
        while(temporary!=1)
        {


        }
        cout<<power(2,count-1);



    }
}
