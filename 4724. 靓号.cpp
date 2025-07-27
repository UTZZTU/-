#include <bits/stdc++.h>
using namespace std;
int n,k,minn=0x3f3f3f3f;
string u,f;
struct node
{
	int money,qs,wz;
};
bool cmp(node a,node b)
{
	if(a.money!=b.money)
	return a.money<b.money;
	else if(a.qs!=b.qs)
	return a.qs<b.qs;
	else
	{
		if(a.qs==-1)
		{
			return a.wz<b.wz;
		}
		else
		{
			return a.wz>b.wz;
		}
	}
}
int main ()
{
	cin>>n>>k;
	getchar();
	cin>>u;
	f=u;
	for(int i=0;i<=9;i++)
	{
		vector<node> vec;
		int num=0,sum=0;
		for(int j=0;j<u.size();j++)
		{
			if(u[j]-'0'==i)
			num++;
			else
			{
				int money=abs(u[j]-'0'-i),qs,wz=j;
				if(u[j]>'0'+i)
				qs=-1;
				else
				qs=1;
				vec.push_back({money,qs,wz});
			}
		}
		if(num>=k)
		{
			cout<<0<<endl;
			cout<<u;
			return 0;
		}
		sort(vec.begin(),vec.end(),cmp);
		string v=u;
		for(int j=0;j<k-num;j++)
		{
			v[vec[j].wz]='0'+i;
			sum+=vec[j].money;
		}
		if(sum<minn||sum==minn&&v<f)
		{
			minn=sum;
			f=v;
		}
	}
	cout<<minn<<endl;
	cout<<f;
	return 0;
}