
//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
size_t popcount(size_t n) {
    std::bitset<sizeof(size_t) * CHAR_BIT> b(n);
    return b.count();
}

ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
//    char str[10000];
//    ll t,n,k;
//    t = readInt();
//    while(t--)
//    {
//        ll j,n1,n2,temp,counter = 0;
//        n = readInt();
//        ll i=0;
//        n2 = n;
//        n1 = n;
//        while(n2!=0)
//        {
//            temp = n2%2;
//            n2 /= 2;
//            str[i++] = char(temp-48);
//        }
//        rep(j,0,i)
//        {
//            if(str[j] == '1')
//            {
//                ++counter;
//            }
//        }
//        i = 0,k=0;
//        for(j=n+1;;j++)
//        {
//            ll counter1 = 0;
//            char str1[10000];
//            ll t1;
//            temp = j;
//            while(temp)
//            {
//                t1 = temp%2;
//                temp/= 2;
//                str1[i++] = char(t1 - 48);
//            }
//            for(k=0;k<i;k++)
//            {
//                if(str1[k] == '1')
//                {
//                    ++counter1;
//                }
//            }
//            if(counter1 == counter)
//            {
//                break;
//            }
//
//        }
//        cout<<j<<endl;
//    }
ll t,n,k,i;
t = readInt();
while(t--)
{
    n = readInt();
    ll temp = popcount(n);
    for(i=n+1;;i++)
    {
        if(popcount(i) == temp)
        {
            break;
        }
    }
    cout<<i<<endl;
}
    return 0;
}
