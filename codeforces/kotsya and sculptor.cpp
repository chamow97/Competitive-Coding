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
    bool flag=false;
    long long j,n,a[10000][3],i,pos1=-1,pos2=-1,pos=-1;    float maxi=0.0;
    n=read_int();
    for(i=0;i<n;i++)
    {
a[i][0]=read_int();
a[i][1]=read_int();
a[i][2]=read_int();        sort(a[i],a[i]+3);
        if(maxi<((a[i][0]*1.00)/(2*1.00)))
        {
            maxi=((a[i][0]*1.00)/(2*1.00));
            pos=i;
        }
    }
   for(i=0;i<n;i++)
    {
        long long small;
        small=min(a[i][0],a[i][1]);
        small=min(small,a[i][2]);
        for(j=i+1;j<n;j++)
        {
            if(a[i][0]==a[j][0] && a[i][1]==a[j][1])
            {
                long long temp=a[i][2]+a[j][2];
                long long temp1=min(a[i][0],a[i][1]);
                    temp1=min(temp1,temp);
                if(temp1>small)
                {

                    if(maxi<float((temp1*1.0)/(2*1.0)))
                    {
                        flag=true;
                        maxi=float(temp1/2);
                        pos1=i;
                        pos2=j;
                    }
                }
            }
            else if(a[i][0]==a[j][0] && a[i][2]==a[j][2])
            {
                long long temp=a[i][1]+a[j][1];
                long long temp1=min(a[i][0],a[i][2]);
                    temp1=min(temp1,temp);
                if(temp1>small)
                {

                    if(maxi<float((temp1*1.00)/(2*1.00)))
                    {
                        flag=true;
                        maxi=float((1.00*temp1)/(2*1.00));
                        pos1=i;
                        pos2=j;
                    }
                }

            }
            else if(a[i][1]==a[j][1] && a[i][2]==a[j][2])
            {
                long long temp=a[i][0]+a[j][0];
                 long long temp1=min(a[i][1],a[i][2]);
                    temp1=min(temp1,temp);
                if(temp1>small)
                {

                    if(maxi<float((1.00*temp1)/(2*1.00)))
                    {
                        flag=true;
                        maxi=float((1.00*temp1)/(2*1.00));
                        pos1=i;
                        pos2=j;
                    }
                }

            }
        }
    }
    if(flag==false)
    {
        cout<<"1"<<endl<<pos+1;
    }
    else
    {
        cout<<"2"<<endl<<pos1+1<<" "<<pos2+1;
    }
}
