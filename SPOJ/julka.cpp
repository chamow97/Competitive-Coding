#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void strrev(char str[])
{
    char t;
    int i;
    int len = strlen(str);
    for(i=0;i<len/2;i++)
    {
        t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
}
int main()
{
    int i;
    char str1[100],str2[100],str3[100];
    cin>>str1>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    strrev(str1);
     strrev(str2);
     //cout<<str1;
    if(len1<len2)
    {
        for(i=len1;i<len2;i++)
        {
            str1[i] = '0';
        }
        str1[i] = '\0';
    }
    else
    {
        for(i=len2;i<len1;i++)
        {
            str2[i] = '0';
        }
        str2[i] = '\0';
    }
    len1 = max(len1, len2);
    len2 = max(len1, len2);
    int sum = 0, rem = 0;
    i = 0;
    while(len1>0)
    {
        sum = (int(str1[i] - 48) + int(str2[i] - 48))+rem;
        rem = sum/10;
        sum = sum%10;
        str3[i] = char(sum + 48);
        i++;
        len1--;
        if(len1 == 0 && rem!=0)
        {
            str3[i] = char(rem + 48);
            i++;
        }
    }
    str3[i] = '\0';
    strrev(str3);
    cout<<str3;
    //cout<<str1<<endl<<str2;
}
