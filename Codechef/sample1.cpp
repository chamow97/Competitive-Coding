#include<stdio.h>

int main()
{
	int t,n,k,i,j,max;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d%d",&n,&k);
		for(i=2;i<=k;i++)
		{
			if(n%i > max)
				max=n%i;
		}
		printf("%d\n",max);
	}
	return 0;
}
