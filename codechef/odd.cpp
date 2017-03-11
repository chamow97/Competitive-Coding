#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{



long int t;
scanf("%ld",&t);

while(t--)
{
    long int n,count=0;
    scanf("%ld",&n);
    while(n!=0)
    {
        n/=2;
        ++count;
    }
    long int ans=pow(2,count-1);
    printf("%ld\n",ans);

}
}
