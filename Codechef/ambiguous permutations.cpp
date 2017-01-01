#include<iostream>

using namespace std;
int j,i,n=1,t[10][10],counting[10],flag=0;;
int tcase=0;

int main()
{


    for(;;)
        {
        cin>>n;
        if(n==0)
            break;
        counting[tcase]=n;
        for(i=0;i<n;i++)
        {
            cin>>t[tcase][i];
        }
                ++tcase;

        }

            for(i=0;i<tcase;i++)
            {


        for(j=0;j<counting[i];j++)
        {

            if(t[i][t[i][j]-1] == j+1)
                flag=0;
            else
            {
                flag=1;break;
            }


        }

         if(flag==0)
        {
            cout<<"\nambiguous";
        }
        else
        {
            cout<<"\nnot ambiguous";
        }
        flag=1;

        }




    }




