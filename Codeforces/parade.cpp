#include<bits/stdc++.h>
using namespace std;
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
int main()
{
    long long pos=-1,n,l[100000],r[100000],i,maxi1=0,maxi=0,sum1=0,sum2=0;
   n=read_int();;
    for(i=0;i<n;i++)
    {
        l[i]=read_int();
        r[i]=read_int();
        sum1+=l[i];
        sum2+=r[i];
    }
    maxi=abs(sum1-sum2);
    for(i=0;i<n;i++)
    {
        maxi1=abs((sum1-l[i]+r[i])-(sum2-r[i]+l[i]));
        if(maxi1>maxi)
        {
            maxi=abs((sum1-l[i]+r[i])-(sum2-r[i]+l[i]));
            pos=i;
        }
    }
    cout<<pos+1;
}
