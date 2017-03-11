#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,i,minimum;
    int arr[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    long long p;
    cin>>t;
    while(t--)
    {
    	int res=0;
        cin>>p;
        for(i=11;i>=0;i--)
        {
        	if(p>=arr[i])
        		{res+=p/arr[i];
        	p=p%arr[i];}
        }
        cout<<res<<"\n";
    }

}
