#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    char str1[251],str2[251],str3[251];
    long int t;
    cin>>t;
    while(t--)
    {
        int i=0,j=0,k=0;
        while(str1[i]!=' ' || str1[i]!=13)
        {
            str1[i]=getche();
            ++i;
        }
        j=0;
        while(str2[j]!=' ' || str2[j]!=13)
        {
            str2[j]=getche();
            ++j;
        }
        for(k=0;k<min(i,j);k++)
        {
            str3[k]=((int)(str1[k]-48)+(int)(str2[k]-48));
        }
        cout<<str3;


    }

}
