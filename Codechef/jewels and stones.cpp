#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int count=0;
        char str1[101],str2[101];
        cin>>str1;
        cin>>str2;
        //len1=strlen(str1);
        //len2=strlen(str2);
      /*  if(len1<len2)
        {
            strcpy(minstr,str1);
            strcpy(maxstr,str2);
        }
        else
        {
            strcpy(minstr,str2);
            strcpy(maxstr,str1);
        }
*/
        for(i=0;i<strlen(str2);i++)
        {
            for(j=0;j<strlen(str1);j++)
            {
                if(str2[i]==str1[j])
                    {++count;
                    break;}
            }
        }

        cout<<count<<"\n";

    }
}
