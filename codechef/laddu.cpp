#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,i;
    long int points=0,rank,severity;
    char origin[11],str[101][20];
    cin>>t;
    while(t--)
    {
        points=0;
        cin>>n;
        cin>>origin;

        for(i=0;i<n;i++)
        {
            cin>>str[i];
            if(str[i][0]=='C' && str[i][8]=='W')
            {
                points+=300;

                cin>>rank;
                if(rank<=19)
                    points+=(20-rank);

            }
            else if(str[i][0]=='B')
            {
                cin>>severity;
                points+=severity;
            }
            else if(str[i][0]=='C' && str[i][8]=='H')
                points+=50;
            else
                points+=300;

        }

        if(origin[0]=='I')
            cout<<points/200<<'\n';
        else
            cout<<points/400<<'\n';

    }
}
