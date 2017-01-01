#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
   int n,i,j;
   int t[500];
   char q[500][500],a[500][500];
   long int w[500][500];
   cin>>n;
   for( i=0;i<n;i++)
   {


       cin>>t[i];

       for( j=0;j<t[i];j++)
       {
           q[i][j]=getche();
       }
       cout<<endl;
       for( j=0;j<t[i];j++)
       {
           a[i][j]=getche();
       }
        cout<<endl;
       for(j=0;j<=t[i];j++)
       {
           cin>>w[i][j];
       }

   }

   for(i=0;i<n;i++)
   {
       int sum=0;
       for(j=0;j<t[i];j++)
       {
           if(q[i][j]==a[i][j])
            ++sum;
       }

       cout<<endl<<w[i][sum];
   }





}
