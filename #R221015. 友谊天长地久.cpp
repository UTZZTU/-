#include <bits/stdc++.h>
using namespace std;
int pos1,pos2,num1,num2,a[100010],n,k1,k2;
struct node
{
	int num,pos;
}s1[100010],s2[100010];
bool cmp(node a,node b)
{
	return a.pos>b.pos;
}
int main ()
{
	map<int,int> mp1,mp2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i+=2)
	{
		mp1[a[i]]++;
		if(mp1[a[i]]>pos1)
		{
			pos1=mp1[a[i]];
			num1=a[i];
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		mp2[a[i]]++;
		if(mp2[a[i]]>pos2)
		{
			pos2=mp2[a[i]];
			num2=a[i];
		}
	}
	if(num1!=num2)
	printf("%d",n-pos1-pos2);
	else
	{
		for(auto it1=mp1.begin();it1!=mp1.end();it1++)
		{
			s1[++k1].num=it1->first;
			s1[k1].pos=it1->second;
		}
		for(auto it2=mp2.begin();it2!=mp2.end();it2++)
		{
			s2[++k2].num=it2->first;
			s2[k2].pos=it2->second;
		}
		sort(s1+1,s1+1+k1,cmp);
		sort(s2+1,s2+1+k2,cmp);
		if(k1==1&&k2==1)
		{
			printf("%d",n-max(pos1,pos2));
		}
		else if(k1==1)
		{
			printf("%d",n-(s1[k1].pos+s2[2].pos));
		}
		else if(k2==1)
		{
			printf("%d",n-(s1[2].pos+s2[k2].pos));
		}
		else
		{
			printf("%d",n-max(s1[2].pos+s2[1].pos,s1[1].pos+s2[2].pos));
		}
	}
	return 0;
}