#include<iostream>


using namespace std;
int main()
{
char a[8][10] = {"monday","tuesday", "wednesday", "thursday" ,"friday" , "saturday", "sunday"};

int b;
cin>>b;
cout<<"\n";
int c[b];
for(int i=0;i<b;i++)
{
cin>>c[i];
cout<<"\n";
}
for(int i=0;i<b;i++)
{
    int d=(2001 - c[i]);
    int e=0;
         if(d<0)
         {
             for(int j=2001; j<c[i]; j++)
             {
                 if(j%4 == 0)
                 {
                     ++e;
                 }

             }


         }
         else if(d>=0)
         {
             for(int k=c[i];k<=2001; k++)
             {
                 if(k%4 == 0)
                 {
                     ++e;
                 }
             }

         }


    if(d<=0)
    {
        d=d*(-1);
        int f=(d*1) + e;
        f=f%7;
        cout<<a[f]<<"\n";
    }


    else if(d>0)
    {

    int f=(d*1) +e;
     if(f!=7)f=f%7;
     cout<<a[7-f]<<"\n";
    }
}
}
