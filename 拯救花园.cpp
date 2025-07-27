#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
struct node{
	double time;
	double destory;
	double flag;
}a[105];
int cmp(node x,node y){
	return x.flag<y.flag;
}
int main()
{
	int n;
	double sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&a[i].time,&a[i].destory);
		a[i].flag=a[i].time/a[i].destory;
	}
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++)
//		cout<<a[i].destory<<" "<<a[i].time<<endl;
	for(int i=0;i<(n-1);i++)
	{
		for(int j=i+1;j<n;j++)
			sum+=(2*a[i].time*a[j].destory);
	}
	printf("%.0lf",sum);
	return 0;
}
//按比值计算排列，而不是先时间后破坏力 
