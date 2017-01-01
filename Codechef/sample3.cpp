#include <cstdio>

using namespace std;

int main() {
  int t,n,k;
  scanf("%d",&t);

  while (t--) {
    scanf("%d%d",&n,&k);

    int even = 0;

    for (int i = 0, val; i < n; ++i) {
      scanf("%d",&val);
      if (val%2==0)
	++even;
    }

    if (k == 0 && even == n)
      printf("NO\n");
    else if (even >= k)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
