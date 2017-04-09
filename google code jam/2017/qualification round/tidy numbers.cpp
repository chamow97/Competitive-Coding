//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */

void func(string &str)
{
    ll len = str.length();
    ll firstpos = -1;
    per(j,len-1,1)
    {
        if(str[j] < str[j-1])
        {
            firstpos = j;
            j--;
            str[j] = str[j] - 1;
            j++;
            rep(i,firstpos,len)
            {
                str[i] = '9';
            }

        }
    }
    ll j = 0;
    while(str[j] == '0')
    {
        str[j] = '$';
        j++;
    }
}


int main()
{
    ll t;
    cin>>t;
    rep(i,0,t)
    {
        string n;
        cin>>n;
        func(n);
        cout<<"Case #"<<i+1<<": ";
        rep(j,0,n.length())
        {
            if(n[j] != '$')
            {
                cout<<n[j];
            }
        }
        cout<<endl;

    }
	return 0;
}
