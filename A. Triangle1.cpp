#include <bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2,a3,b3;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
bool judge(int a1,int b1,int a2,int b2,int a3,int b3)
{
	int l1=(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
	int l2=(a1-a3)*(a1-a3)+(b1-b3)*(b1-b3);
	int l3=(a3-a2)*(a3-a2)+(b3-b2)*(b3-b2);
//	cout<<l1<<" "<<l2<<" "<<l3<<endl;
	if(((double)sqrt(l1)+(double)sqrt(l2)>(double)sqrt(l3)&&(double)sqrt(l1)+(double)sqrt(l3)>(double)sqrt(l2)&&(double)sqrt(l2)+(double)sqrt(l3)>(double)sqrt(l1))&&(l1+l2==l3||l2+l3==l1||l1+l3==l2)) return true;
	return false;
}
void solve()
{
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	if(judge(a1,b1,a2,b2,a3,b3))
	{
		cout<<"RIGHT"<<endl;	
		return;
	} 
	for(int i=0;i<4;i++)
	{
		int xx=a1+dx[i],yy=b1+dy[i];
		if(judge(xx,yy,a2,b2,a3,b3))
		{
			cout<<"ALMOST"<<endl;	
			return;
		}
	}
	for(int i=0;i<4;i++)
	{
		int xx=a2+dx[i],yy=b2+dy[i];
		if(judge(xx,yy,a1,b1,a3,b3))
		{
			cout<<"ALMOST"<<endl;	
			return;
		}
	}
	for(int i=0;i<4;i++)
	{
		int xx=a3+dx[i],yy=b3+dy[i];
		if(judge(xx,yy,a2,b2,a1,b1))
		{
			cout<<"ALMOST"<<endl;	
			return;
		}
	}
	cout<<"NEITHER"<<endl;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}