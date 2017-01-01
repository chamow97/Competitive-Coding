#include<bits/stdc++.h>

using namespace std;

int main()
{
    long int i,j,k,n,len=0;
    char str[201],str1[201][201];
    for(;;)
    {
        cin>>n;
        if(n==0)
            break;
        else
        {
            cin>>str;
            len=strlen(str);
            len=(len/n);
            k=n;
            for(i=0;i<len;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i%2==0)
                    {
                        str1[i][j]=str[(k*i)+j];
                    }
                    else
                    {
                        str1[i][j]=str[(k*i)+n-j-1];
                    }

                }
                            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<len;j++)
                {
                    cout<<str1[j][i];

                }


            }
            cout<<'\n';

        }

    }
}
