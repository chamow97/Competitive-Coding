
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

int main()
{
    ll mat[50][50] = {0}, ans = 0;
    rep(i,5,25)
    {
        rep(j,5,25)
        {
            cin>>mat[i][j];
        }
    }
    rep(i,5,25)
    {
        rep(j,5,25)
        {
            ans = max(ans, mat[i][j] * mat[i+1][j] * mat[i+2][j] * mat[i+3][j]);

            ans = max(ans, mat[i][j] * mat[i][j+1] * mat[i][j+2] * mat[i][j+3]);

            ans = max(ans, mat[i][j] * mat[i+1][j+1] * mat[i+2][j+2] * mat[i+3][j+3]);

            ans = max(ans, mat[i][j] * mat[i-1][j-1] * mat[i-2][j-2] * mat[i-3][j-3]);
            ans = max(ans, mat[i][j] * mat[i][j-1] * mat[i][j-2] * mat[i][j-3]);
            ans = max(ans, mat[i][j] * mat[i-1][j] * mat[i-2][j] * mat[i-3][j]);
            ans = max(ans, mat[i][j] * mat[i+1][j-1] * mat[i+2][j-2] * mat[i+3][j-3]);
             ans = max(ans, mat[i][j] * mat[i-1][j+1] * mat[i-2][j+2] * mat[i-3][j+3]);




        }
    }
    cout<<ans;
	return 0;
}
