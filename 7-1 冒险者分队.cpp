#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cs=0;
		int y1,y2,y3,w1,w2,w3;
		cin>>y1>>y2>>y3>>w1>>w2>>w3;
		if((y1-w1)+(y2-w2)+(y3-w3)!=0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if((y1-w1)/10&1||(y2-w2)/10&1||(y3-w3)/10&1)
		{
			cout<<"-1"<<endl;
			continue;
		}
		int a[3];
		a[0]=abs(y1-w1),a[1]=abs(y2-w2),a[2]=abs(y3-w3);
		sort(a,a+3);
		cs+=a[2]/40;
		a[2]%=40;
		a[1]-=cs*20;
		a[0]-=cs*20;
		if(a[1]<=a[0]&&a[2])
		{
			a[1]+=20;
			a[0]-=40;
		}
		else if(a[1]>a[0]&&a[2])
		{
			a[0]+=20;
			a[1]-=40;
		}
		cs+=a[2]/20;
		a[2]%=20;
		if(a[1]==0&&a[2]==0&&a[0]==0)
		cout<<cs<<endl;
		else
		cout<<-1<<endl;
	}
	return 0;
}