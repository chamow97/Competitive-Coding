#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long a,b,c; cin>>a>>b>>c;
  if(a > b) swap(a,b);
  if(a > c) swap(a,c);
  long long ans = 0;
  for(int i = 0;i <= min(a,1000000LL);i++) {
    long long ts = a - i;
    long long can = ts;
    can+=(a - ts)/3;
    can+=(b - ts)/3;
    can+=(c - ts)/3;
    ans = max(ans,can);
    can = i;
    can+=(a - i) / 3;
    can+=(b - i) / 3;
    can+=(c - i) / 3;
    ans = max(ans,can);
  }
  cout<<ans<<endl;

}

int main() {
  //freopen("output2.txt","w",stdout);
  int t; cin>>t;
  while(t--) {
    solve();
  }
}
