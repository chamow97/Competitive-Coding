//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
    bool minus = false;
    ll result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
char* strrev(char str[])
{
    char t;
    ll i;
    ll len = strlen(str);
    for(i=0;i<len/2;i++)
    {
        t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
    return str;
}
int main()
{
    ll t;
    t = readInt();
    while(t--)
    {
        char str[1000001];
    cin>>str;
    ll i,j,k,len = strlen(str);
    i = 0;
    j = len-1;
 
        bool isPalin = true;
                i=0;
        for(i=0;i<len/2;i++)
        {
            if(str[i] == str[len-1-i])
            {
                isPalin = true;
                
            }
            else
            {
                isPalin = false;
                break;
            }
        }
        ll newlen=0;
        char temp[1000001];
          
          
        i = 0;
        if(isPalin == true)
        {

               for(i=0;i<len;i++)
           {
               temp[i] = str[len-1-i];
           }
           temp[len] = '0';
          //cout<<"SDSD";
          ll rem=11;
          i=0;
           while(rem/10 >0)
               {  rem = ll(temp[i] - 48) + 1;
                temp[i] = char((rem%10) + 48);
                temp[i+1] = char(((rem/10) + ll(temp[i+1] - 48)) + 48);
                
                i++;
                
            }
            temp[i+1] = '\0';
            newlen = i+1;
             cout<<temp;
             for(i=0;i<newlen;i++)
        {
            str[i] = temp[newlen-i];
        }
  
        i=0;
        j=newlen;
        len=newlen+1;
        }
        i=0;
        j=len-1;
        
        
            while(i < j)
    {
        if(str[i] >= str[j])
        {
            i++;
            j--;
        }
        else
        {
            str[j] = '0';
            k = j-1;
            while(str[k] == '9' && k>i)
            {
                str[k] = '0';
                k--;
            }
            str[k]++;
            i += (j-k);
            j = len-1-i;
        }

 
        }
        
    for(i=0; i<len/2; i++)
    {
 
        str[len-1-i] = str[i];
    }
   // cout<<str;
    cout<<endl;
 
    }
 
 
    return 0;
}