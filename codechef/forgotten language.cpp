#include<iostream>
#include<string.h>

using namespace std;

int main()
{

    int t;
    int i,j,l,x,m,n,c=0,o;
       int ans[t][100];
    cin>>t;
    char a[100][100],b[100][100][100];
    for( i=0;i<t;i++)
    {

        int n,k;

        cin>>n>>k;

        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        int z;
        for(l=0;l<k;l++)
        {

            cin>>z;
            for(x=0;x<z;x++)
            {
                cin>>b[l][x];
            }
        }


        while(c<n)
        {

            for(m=0;m<k;m++)
            {
                for(o=0;o<z;o++)
                {
                    if(strcmp(a[c],b[m][o])==0)
                    {ans[t][c]=1;
                        break;
                    }
                }
            }

            ++c;
        }
    }

    for(i=0;i<t;i++)
    {
        for(j=0;j<o;j++)
        {
            if(ans[i][j]==1)
                cout<<"YES ";
            else
                cout<<"NO ";
        }
        cout<<endl;
    }


}
