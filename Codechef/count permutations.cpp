#include <iostream>
using namespace std;

int main() {
    int t;
    long long n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        //n-=2;
        ans=(((n-1)*(n))/2)%1000000007;
        cout<<ans<<endl;
    }
	// your code goes here
	return 0;
}
