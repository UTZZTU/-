#include <bits/stdc++.h>
using namespace std;
int n,k,a[1010],minn=0x3f3f3f3f,x,pos=-1,num;
int main ()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		x=0;
		if(a[i]-(i-1)*k<=0)
		continue;
		num=a[i];
		for(int j=i-1;j>=1;j--)
		{
			num-=k;
			if(a[j]!=num)
			x++;
		}
		num=a[i];
		for(int j=i+1;j<=n;j++)
		{
			num+=k;
			if(a[j]!=num)
			x++;
		}
		if(x<minn)
		{
			minn=x;
			pos=i;
		}
	}
	cout<<minn<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i<=pos)
		{
			num=a[pos]-(pos-i)*k;
		}
		else
		{
			num=a[pos]+(i-pos)*k;
		}
		if(a[i]<num)
		{
			printf("+ %d %d\n",i,num-a[i]);
		}
		else if(a[i]>num)
		{
			printf("- %d %d\n",i,a[i]-num);
		}
	}
	return 0;
}