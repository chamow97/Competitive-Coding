#include<iostream>

using namespace std;

int main()
{
    int a,i,temp;
    cin>>a;
    int b[a];
    cout<<endl;
    for(i=0;i<a;i++)
    {
        cin>>b[i];
        cout<<endl;
    }
    for(i=0;i<a;i++)
    { int four=0;
        while(b[i])
        {
            temp=b[i]%10;
            if(temp==4)
                ++four;
            b[i]/=10;
        }
        cout<<four;
        cout<<endl;
    }
}
