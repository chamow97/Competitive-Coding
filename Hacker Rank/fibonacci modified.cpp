#include<bits/stdc++.h>
using namespace std;

int main()
{
char str[100],str1[100],product[1000];
int arr[1000];
cin>>str>>str1;
strcpy(str,strrev(str));
strcpy(str1,strrev(str1));

long long i,j,k,len=strlen(str),len1=strlen(str1),mul=0,carry=0,maximum;
if(len>len1)
{
    for(i=len1;i<len;i++)
    {
        str1[i]='0';
    }

}
else if(len1>len)
{
    for(i=len;i<len1;i++)
    {
        str[i]='0';
    }
}

len=max(len,len1);
len1=len;
str1[len1]='\0';
str[len]='\0';
cout<<str<<endl<<str1<<endl;
k=0;
for(i=0;i<len;i++)
{carry=0;
    for(j=0;j<len;j++)
    {
        mul=int(((str[i]-48)*(str1[j]-48))+carry);
        product[k]=char((mul%10)+48);
        k++;
        carry=mul/10;
    }

        cout<<product;
    k=0;
    carry=0;
    cout<<endl;
}

}
