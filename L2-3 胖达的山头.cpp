#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//struct node
//{
//	int start,end;
//}s[100010];
//bool cmp(node x,node y)
//{
//	if(s.start!=y.start) return x.start<y.start;
//	else return x.end<y.end;
//}
int n,sum,hy,bhy,s[1000010];
int main ()
{
	int hh,mm,ss;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:%d:%d",&hh,&mm,&ss);
		s[hh*3600+mm*60+ss]++;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		s[hh*3600+mm*60+ss+1]--;
	}
	for(int i=0;i<=1000000;i++)
	{
		if(s[i]>0)
		{
			if(hy>=s[i])
			{
				hy-=s[i];
				bhy+=s[i];
			}
			else
			{
				int cz=s[i]-hy;
				sum+=cz;
				hy=0;
				bhy+=s[i];
			}
		}
		else if(s[i]<0)
		{
			int nn=abs(s[i]);
			bhy-=nn;
			hy+=nn;
		}
	}
	cout<<sum;
	return 0;
}
