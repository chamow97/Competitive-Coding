#include <iostream>
using namespace std;

int main() {
    long long n,i;
    char str[101];
    int a[27];
    bool flag = false;
    cin>>n;
    cin>>str;
    for(i = 0; i < 26; i++)
    {
    	a[i] = 0;
    }
    for(i = 0; i<n; i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
        {
            a[str[i] - 65]++;
        }
        else
        {
            a[str[i] - 97]++;
        }
        
    }
    for(i = 0;i <26; i++)
    {
        if(a[i]>=1)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
       // cout<<a[i]<<" ";
        
    }
    if(flag == false)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
	
}
