#include <bits/stdc++.h>
using namespace std;
int n,q,h1,m1,k,a[110],x,y,h2,m2,min1,min2,mb;
int main ()
{
	cin>>n>>q;
	scanf("%d:%d %d",&h1,&m1,&k);
	min1=h1*60+m1;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	while(q--)
	{
		scanf("%d %d %d:%d",&x,&y,&h2,&m2);
		min2=h2*60+m2;
		if(x<=y)
		{
			 mb=min1+a[x];
		if(mb<min2)
		{
			mb+=ceil((min2-mb)*1.0/k)*k;
		}
		mb+=a[y]-a[x];
		h2=mb/60;
		m2=mb%60;
		if(h2>=24)
		cout<<"cr";
		printf("%02d:%02d\n",h2%24,m2);
		}
		else
		{
			mb=min1+a[n]-a[x];
		if(mb<min2)
		{
			mb+=ceil((min2-mb)*1.0/k)*k;
		}
		mb+=a[x]-a[y];
		h2=mb/60;
		m2=mb%60;
		if(h2>=24)
		cout<<"cr";
		printf("%02d:%02d\n",h2%24,m2);
		}
		
	}
	return 0;
}