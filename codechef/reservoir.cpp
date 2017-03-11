#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,t,n,m;
    bool isStable= false;
    char str[1001][1001];
    cin>>t;
    while(t--)
    {
        isStable = true;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>str[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {

               if(str[i][j] == 'W')
                {
                    if(str[i][j+1] != 'B' || str[i][j-1] != 'B' || str[i+1][j] != 'B' )
                    {
                        isStable = false;
                        break;
                    }

                }
                else if(str[i][j] == 'B')
                {
                    if(str[i+1][j] == 'A' || str[i+1][j] == 'W')
                    {
                        isStable = false;
                        break;
                    }
                }
            }
            if(isStable == false)
            {
                break;
            }
        }
        if(isStable == true)
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
        cout<<endl;
    }
}
