//template by chamow
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
int LIS(vector<int> &v)
{
	int i,length = v.size(),len=1;
	vector<int> tail(v.size(),0);
	tail[0] = v[0];
	if(length == 0)
	{
		return 0;
	}
	for(i = 1; i<length ; i++)
	{
        if(gcd(v[i],tail[len-1])>1)
        {
            tail[len++] = v[i];
        }
        else if(v[i]<tail[len-1])
        {
            tail[len-1]=v[i];
        }
	}
	return len;
}

//int findPosition(int l, int r, vector<int> &tail, int key)
//{
//	while((r-l)>1)
//	{
//		int m = l+(r-l)/2;
//		if(tail[m] >= key)
//		{
//			r = m;
//		}
//		else
//		{
//			l = m;
//		}
//	}
//	return r;
//}


int main()
{
	std::vector<int> v{13, 2, 8, 6, 3, 1, 9};
	cout<<"\nLongest Increasing Subsequence is : "<<LIS(v);
}
