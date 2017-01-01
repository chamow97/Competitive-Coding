#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long tot = 0;
        int minn = 1000000001;
        for(int i = 0;i < n;i++)
        {
            int x;  cin>>x;
            tot += x;
            if(x % 2 != 0)
                minn = min(x,minn);
        }
        if(tot % 2 != 0)
            tot -= minn;
        cout<<tot<<endl;
    }
    return 0;
}
