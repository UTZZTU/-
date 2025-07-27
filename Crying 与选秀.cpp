#include <bits/stdc++.h>
using namespace std;
int n,res;
double num;
int x;
priority_queue<pair<double,int>> p;
int main ()
{
	vector<int> vec;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&num);
//		x=(int)(num*10000000);
		p.push({-num,i});
//		cout<<x<<endl;
		if(p.size()<=6) 
		{
			res++;
			vec.push_back(0);
		}
		else
		{
			pair<int,int> pp=p.top();
			p.pop();
			if(pp.second==i)
			{
				vec.push_back(0);
			}
			else
			{
				res++;
				vec.push_back(pp.second);
			}
		}
	}
	printf("%d\n",res);
	for(int i=0;i<n;i++)
	{
		printf("%d ",vec[i]);
	}
	return 0;
}