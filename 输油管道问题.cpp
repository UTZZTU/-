#include<stdlib.h>
#include<stdio.h>
#define N 10000
void Swap(int &a,int &b);
int Partion (int a[],int l,int h);
int Select(int a[],int l,int h,int k);
int main()
{
	int a[N],b[N];
    int n,mid,sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d %d",&b[i],&a[i]);
    mid=Select(a,0,n-1,n/2+1);
    for(int i=0; i<n; i++)
        sum+=abs(a[i]-mid);
    printf("%d",sum);
    return 0;
}
void Swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int Partion (int a[],int l,int h)
{
	 int x=a[l];
	while(l<h)
	{
		while(l<h&&a[h]>=x) --h;
		Swap(a[l],a[h]);
		while(l<h&&a[l]<=x) ++l;
		Swap(a[l],a[h]);
	}
	a[l]=x;
	return l;
}
int Select(int a[],int l,int h,int k)
{
	if(l==h) return a[l];
	int i=Partion(a,l,h);
	int j=i-l+1; 
	if(k<=j)
	   return Select(a,l,i,k);
	else
		return Select(a,i+1,h,k-j);
}