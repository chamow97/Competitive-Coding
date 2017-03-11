#include<bits/stdc++.h>

using namespace std;

int main()
{
    float a,b,c,d;
    while(1)
    {
        cin>>a>>b>>c;
        if(a==0 && b==0 &&c==0)
            break;
        else
        {
            if(b/a == c/b)
                cout<<"GP "<<((b/a)*c)<<'\n';
            else
                cout<<"AP "<<((b-a+c))<<'\n';
        }
    }
}
