#include<iostream>

using namespace std;

int main()
{
    long int t,c,l,i,j;
    cin>>t;
    while(t--)
    {
        cin>>l>>c;
        for(i=0;i<l;i++)
        {
            for(j=0;j<c;j++)
            {
                if((i==0)||i==l-1||j==0||j==c-1)
                    cout<<"*";
                else
                    cout<<".";
            }
            cout<<"\n\n";
        }

    }
}
