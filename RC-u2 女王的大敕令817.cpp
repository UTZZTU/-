#include <bits/stdc++.h>
using namespace std;
int c1,c2,r1,r2,n[10],row,col,d1,d2;
bool judge(int x,int y,int u,int v)
{
	if(abs(x-u)+abs(y-v)!=d1||abs(u-row)+abs(v-col)!=d2) return false;
	if(x==r2+n[4]||x==r1-n[3]||y==c1||y==c2) return false;
	if(u==r2+n[4]||u==r1-n[3]||v==c1+n[1]||v==c2-n[2]) return false;
	return true;
}
int main ()
{
	cin>>c1>>c2>>r1>>r2;
	for(int i=1;i<=4;i++)
	cin>>n[i];
	cin>>row>>col>>d1>>d2;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k1=1;k1<=5;k1++)
			{
				for(int k2=1;k2<=5;k2++)
				{
					if(judge(i,j,k1,k2))
					cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
				}
			}
		}
	}
	return 0;
}