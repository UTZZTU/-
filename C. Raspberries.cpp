#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,f[100010];
int get_two(){
	int res1=0,res2=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]%2==0)
		{
			res1++;
		}
		else
		{
			res2++;
		}
	}
	if(res1) return 0;
	else return 1;
}
int get_three(){
	int maxx=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,f[i]%3);
		if(f[i]%3==0) pos++;
	}
	if(pos) return 0;
	else
	return 3-maxx;
}
int get_five(){
	int maxx=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,f[i]%5);
		if(f[i]%5==0) pos++;
	}
	if(pos) return 0;
	else
	return 5-maxx;
}
int get_four(){
	if(n==1)
	{
		int pos=0;
		while(f[1]%4!=0) 
		{
			f[1]++;
			pos++;
		}
		return pos;
	}
	int res1=0,res2=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i]%2==0)
		{
			int j=f[i];
			while(j%2==0)
			{
				j/=2;
				res1++;
			}
		}
		else
		{
			res2++;
		}
	}
	if(res1>=2) return 0;
	else if(res1==1)
	{
		return 1;
	}
	else
	{
		int minn=2;
		for(int i=1;i<=n;i++)
		{
			if((f[i]+1)%4==0) minn=1;
		}
		return minn;
	}
}
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		if(k==2)
		{
			printf("%d\n",get_two());
		}
		else if(k==3)
		{
			printf("%d\n",get_three());
		}
		else if(k==4)
		{
			printf("%d\n",get_four());
		}
		else
		{
			printf("%d\n",get_five());
		}
	}
	return 0;
}