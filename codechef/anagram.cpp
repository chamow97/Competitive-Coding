#include<iostream>

using namespace std;

int main()
{
    long int t,sum1=0,sum2=0,i,j,flag=0;
    char str1[227],str2[227];
    cin>>t;
    while(t--)
    {
        flag=0;
        sum1=0;
        sum2=0;
        cin>>str1;
        cin>>str2;

        for(i=0;str1[i]!='\0';i++)
        {
            sum1+=(int)str1[i];
            sum2+=(int)str2[i];
        }
        for(i=0;str1[i]!='\0';i++)
        {
            for(j=0;str2[j]!='\0';j++)
            {
                if(str1[i]==str2[j])
                {
                    flag=1;
                    break;
                }

                else
                {
                    flag=0;

                }
            }
            if(flag==0)
                break;
        }
        if(sum1==sum2 && flag==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
