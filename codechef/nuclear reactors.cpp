#include<iostream>
#include<algorithm>

using namespace std;



    int main()
{
    long int a,n,k,len,i;
    cin>>a>>n>>k;
    long int arr[101]={0};
    len=k;
    long int temp=0;
    for(i=0;i<k;i++)
    {


        arr[temp]=a%(n+1);
        a/=(n+1);
        cout<<arr[temp++]<<" ";
    }


}
