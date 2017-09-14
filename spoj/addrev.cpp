#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;
long int reverse(int n)
{
    int temp=0;
    long int reverse=0;
    while(n!=0)
    {
        temp=n%10;
        n/=10;
        reverse=(reverse*10)+temp;
    }
    return reverse;

}
int main()
{
   long int n,a,b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        a=reverse(a);
        b=reverse(b);
        a=reverse(a+b);
        cout<<a<<'\n';
    }

}
