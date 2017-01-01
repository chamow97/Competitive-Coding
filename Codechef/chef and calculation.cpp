#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t,n,c[100][100],type[100][7],i,j,q,winner[100],nooftypes[100]=0,size[100],maximum=0,pos=0,counter=0;
    cin>>t;
    while(t--)
    {
        maximum=0;pos=0;counter=0;
        nooftypes=0;

        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>size[i];
            for(j=0;j<size[i];j++)
            {
                cin>>c[i][j];
                type[i][c[i][j]]++;
            }

        }
        for(i=0;i<n;i++)
        {
            nooftypes=0;
            for(j=1;j<=6;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(type[i][j]==k)
                    {
                        ++nooftypes[k];
                    }

                }

            }
            // cout<<nooftypes<<endl;
            if(nooftypes<=3)
            {
                winner[i]=size[i];
            }
            else
            {
                if(nooftypes==6)
                {
                    nooftypes=4;
                }
                else
                {
                    nooftypes=nooftypes-3;
                }
                winner[i]=size[i]+nooftypes;
            }
            nooftypes=0;
        }
        maximum=winner[0];
        pos=0;
        counter=1;
        for(i=1;i<n;i++)
        {
            cout<<winner[i]<<endl;
            if(winner[i]>maximum)
            {
                maximum=winner[i];
                counter=1;
                pos=i;
            }
            else if(winner[i]==maximum)
            {
                maximum=winner[i];
                counter+=1;
            }
        }
        if(counter>1)
        {
            cout<<"tie\n";
        }
        else if(counter==1 && pos==0)
        {
            cout<<"chef\n";
        }
        else
            cout<<pos+1<<'\n';

    }

}
