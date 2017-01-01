#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,str[2],str1[5];
    cin>>x>>str>>str1;
    if(strcmp(str1,"week")==0)
    {
        if(x<=5)
            cout<<"52\n";
        else
            cout<<"51\n";
    }
}
