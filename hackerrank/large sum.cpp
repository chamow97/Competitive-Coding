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

string add(string s1, string s2)
{
    ll len = max(s2.length(), s1.length());
    if(s1.length() < len)
    {
        rep(i,s1.length(),len)
        {
            s1[i] = '0';
        }
    }
    else
    {
        rep(i,s2.length(),len)
        {
            s2[i] = '0';
        }
    }
    ll carry = 0;
    ll sum = 0;
    string ans = "";
    per(j,len-1,0)
    {
        sum = ((s1[j] - 48) + (s2[j] - 48)) + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans = ans + char(sum + 48);
    }
    if(carry != 0)
    ans = ans + char(carry + 48);

    string temp = "";
    ll l = ans.length();
    rep(i,0,l)
    {
        temp = temp + (ans[l-1-i]);
    }
    return temp;
}

int main()
{
    ll n;
    cin>>n;
    vector<string> s;
    string ans = "";
    rep(i,0,n)
    {
        string temp;
        cin>>temp;
        s.pb(temp);
    }
   string sum = "00000000000000000000000000000000000000000000000000";
   vector<string> :: iterator it;
   for(it = s.begin(); it != s.end(); it++)
   {
       ans = add(*it,sum);
       cout<<ans<<endl;
       sum = ans;
   }
   cout<<ans;
	return 0;
}
