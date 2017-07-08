#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long d1,d2,d3,sum1=0,sum2=0,sum3=0,sum4=0,min1,min2;
    cin>>d1>>d2>>d3;
    sum1=d1+d2+d3;
    sum2=(d1*2)+(d2*2);
    sum3=(d1*2)+(d3*2);
    sum4=(d2*2)+(d3*2);
    min1=min(sum1,sum2);
    min2=min(sum3,sum4);
    cout<<min(min1,min2);

}
