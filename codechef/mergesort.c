#include<stdio.h>
void mergesort(int a,int b,int m,int arr[1000]);
void merge(int a,int b,int arr[1000])
{
    int m;

    if(a<b)
    {
        m=(a+(b-1)/2);
        merge(a,m-1,arr);
        merge(m,b,arr);
        mergesort(a,b,m,arr);
    }

}
void mergesort(int a,int b,int m,int arr[1000])
{
    int n1=(m-a+1);
    int n2=b-m;
    int l[n1],r[n2];



    int i=0,j=0,k=0;

    for(i=0;i<n1;i++)
        l[i]=arr[i+a];

    for(i=0;i<n2;i++)
        r[i]=arr[m+1+i];

    i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(l[i]<r[j])
        {
            arr[k]=l[i];

        }
        else
            arr[k]=r[j];
        k++;
        i++;
        j++;

    }

    while(i<n1)
        arr[k++]=l[i++];
    while(j<n2)
        arr[k++]=r[j++];

}


int main()
{
    int i,n,arr[1000];
    printf("\n\n\tMERGE SORT!!! \n\t----- ----");
    printf("\n\n Enter number of terms :");
    scanf("%d",&n);
    pritnf("\n\n Enter the terms :");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    merge(0,n-1,arr);
for(i=0;i<n;i++)
    printf("%d ",arr[i]);


}
