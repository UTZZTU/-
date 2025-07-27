#include <bits/stdc++.h>
using namespace std;
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},res,y,m,d;
bool judge(int x)
{
	if(x%4==0&&x%100!=0||x%400==0)
	return true;
	else
	return false;
}
int main ()
{
	while(cin>>y>>m>>d)
	{
		res=0;
		if(judge(y))
		a[2]=29;
		else
		a[2]=28;
		for(int i=1;i<m;i++)
		res+=a[i];
		res+=d;
		cout<<res<<endl;
	}
	return 0;
}