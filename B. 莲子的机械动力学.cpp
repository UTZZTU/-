#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int n,m,jw,a[200010],b[200010],t1,t2,num,tt=2;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%d",&b[i]);
	t1=n,t2=m;
	while(t1>=1&&t2>=1)
	{
		num=a[t1]+b[t2]+jw;
		jw=num/tt;
		num%=tt;
		vec.push_back(num);
		tt++;
		t1--,t2--;
	}
	while(t1>=1)
	{
		num=a[t1]+jw;
		jw=num/tt;
		num%=tt;
		vec.push_back(num);
		tt++;
		t1--;
	}
	while(t2>=1)
	{
		num=b[t2]+jw;
		jw=num/tt;
		num%=tt;
		vec.push_back(num);
		tt++;
		t2--;
	}
	if(jw)
	vec.push_back(jw);
	for(int i=vec.size()-1;i>=0;i--)
	printf("%d ",vec[i]);
	return 0;
}