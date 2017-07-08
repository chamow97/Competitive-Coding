#include<bits/stdc++.h>

using namespace std;
char str1[100000],str2[31];
int counter=0,i;
int substring(int a,int n1,int n2)
{
    char temp[n2+1];

    if(n1-a==n2-1)
        return counter;
    else
    {
        int flag=0;
        i=a;
        while(i<n2+a)
        {
            temp[i]=str1[i];
            i++;

        }
        temp[i]='\0';

        for(i=a;i<n2+a;i++)
        {


         if(temp[i]==str2[i-a])
        {
            flag=1;
        }
        else
         {

         flag=0;
         break;
         }


        }
        if(flag==1)
            ++counter;

        return substring(a+1,n1,n2);
    }
}
int main()
{


    cin>>str1>>str2;
    cout<<substring(0,strlen(str1),strlen(str2));


}
