#include <bits/stdc++.h>
using namespace std;
int y,n,m,f[5000010],b[20],minn;
int q[5000010],hh,tt;
multiset<int> mul;
int main ()
{
	scanf("%d%d%d",&y,&n,&m);
//	cout<<-1<<endl;
	hh=0,tt=-1;
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
//	for(int i=1;i<=n;i++)
//	{
//		f[i]=1;
//		if(hh<=tt&&q[hh]<i-n+1) hh++;
//printf("111");
//    	while(hh<=tt&&f[q[tt]]>=f[i]) tt--;
//    	q[++tt]=i;
//    	if(i>=k) printf("%d ",a[q[hh]]);
//		mul.insert(f[i]);
//	}
	for(int i=1;i<=y;i++)
	{
	
		
//		if(i<=n) f[i]=1;
//		if(i-n+1>q[hh]) ++hh;
		minn=0x3f3f3f3f;
		for(int j=1;j<=m;j++)
		{
			if(i%(b[j])==0)
			{
				minn=min(minn,f[i/b[j]]);
			}
		}
		minn=min(minn,f[q[hh]]);
		f[i]=minn+1;	
			while(hh<=tt&&f[q[tt]]>=f[i]) tt--;
//		if(hh<=tt&&q[hh]<i-n+1) hh++;
//    	q[++tt]=i;
		mul.insert(f[i]);
		mul.erase(mul.lower_bound(f[i-n]));
//    	printf("%d %d\n",i,f[i]);
	}
	cout<<f[y];
	return 0;
}