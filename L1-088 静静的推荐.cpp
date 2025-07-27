#include <bits/stdc++.h>
using namespace std;
struct stu{
	int num1,num2;
}ss[100010];
bool cmp(stu x,stu y)
{
	if(x.num1!=y.num1) return x.num1<y.num1;
	else return x.num2<y.num2;
}
int n,k,s,cnt,res;
int main ()
{
	cin>>n>>k>>s;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		if(a>=175)
		{
			ss[++cnt].num1=a;
			ss[cnt].num2=b;
		}
	}
	sort(ss+1,ss+1+cnt,cmp);
	vector<stu> vec;
	for(int i=1;i<=cnt;i++)
	{
		int flag=0;
		for(int j=0;j<vec.size();j++)
		{
			stu x=vec[j];
			if(x.num1<ss[i].num1||x.num1==ss[i].num1&&ss[i].num2>=s)
			{
				vec[j]=ss[i];
				res++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			if(vec.size()<k)
			{
				vec.push_back(ss[i]);
				res++;
			}
			else
			continue;
		}
	}
	cout<<res;
	return 0;
}