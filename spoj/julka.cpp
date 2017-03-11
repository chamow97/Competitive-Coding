#include<bits/stdc++.h>
#include<string.h>
using namespace std;
    char str1[105],str2[105],str3[105],str4[105],str5[105],str6[105];

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
void add(int len1, int len2)
{
    int i,j;
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
}
void subtract(int len1, int len2)
{
    int i,j;
    len1 = max(len1, len2);
    len2 = max(len1, len2);
    int sum = 0, rem = 0;
    i = 0;
    //cout<<str1<<" "<<str2;
    while(len1>0)
    {
        if( int(str1[i] - 48) >= int(str2[i] - 48))
        {
            str4[i] = char(str1[i] - str2[i] + 48) ;
            //cout<<"1";
        }
        else
        {
            j = i;
            str4[j] = char((int(str1[j] - 48) + 10 - int(str2[j] - 48)) + 48);
            j++;
            while(j < len2 && int(str1[j] - 48) == 0)
            {
                //cout<<"ad";
                str1[j] = char(57);
                j++;
            }
            str1[j] =  char( int(str1[j]) - 1) ;
            //cout<<"2";
        }
        i++;
        len1--;
    }
    str4[i] = '\0';
    strrev(str4);

}
void dividebytwo()
{
     int len3 = strlen(str3);
     int len4 = strlen(str4);
     int i,j;
     int rem = 0;
     int result = 0;

     for(i=0;i<len3;i++)
     {
              result = ((rem*10) + (int(str3[i] - 48)))/2;
              rem = int(str3[i] - 48)%2;
              str5[i] = char(result + 48);

     }
     rem = 0;
     str5[i] = '\0';
     for(i=0;i<len4;i++)
     {
            result = ((rem*10) + (int(str4[i] - 48)))/2;
            rem = int(str4[i] - 48)%2;
            str6[i] = char(result + 48);
     }
     str6[i] = '\0';
}
int main()
{
    int i,len1,len2,j;
    int testcases;
    testcases = 10;
    while(testcases--)
    {
        cin>>str1>>str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    strrev(str1);
    strrev(str2);

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

     //cout<<str1;
    add(len1, len2);
    subtract(len1, len2);
    dividebytwo();
    bool flag = false;
    for(i=0;i<strlen(str5);i++)
    {
        if(flag == false && str5[i] == '0')
        {
            continue;
        }
        else
        {
            cout<<str5[i];
            flag = true;
        }
    }
    cout<<endl;
    flag = false;
        for(i=0;i<strlen(str6);i++)
    {
        if(flag == false && str6[i] == '0')
        {
            continue;
        }
        else
        {
            cout<<str6[i];
            flag = true;
        }
    }
    str1[0] = '\0';
    str2[0] = '\0';
    str3[0] = '\0';
    str4[0] = '\0';
    str5[0] = '\0';
    str6[0] = '\0';
    cout<<endl;

    }


    //cout<<str3<<endl<<str4;
}
