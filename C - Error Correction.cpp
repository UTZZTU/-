#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n,len1,len2;
char u[500010],v[500010];
vector<int> vec;
bool judge(char u[500010],char v[500010])
{
	int pos=0;
	if(len1==len2)
	{
		for(int i=0;i<len2;i++)
		{
			if(u[i]!=v[i])
			{
				pos++;
				if(pos>1) break;
			}
		}
		return pos<=1;
	}
	else if(len1==len2+1)
	{
		for(int i=0,j=0;i<len2&&j<len1;i++,j++)
		{
			if(u[i]!=v[j])
			{
				pos++;
				if(pos>1) break;
				i--;
			}
		}
		return pos<=1;
	}
	else if(len1==len2-1)
	{
		for(int i=0,j=0;i<len2&&j<len1;i++,j++)
		{
			if(u[i]!=v[j])
			{
				pos++;
				if(pos>1) break;
				j--;
			}
		}
		return pos<=1;
	}
	return false;

//	int be1=0,be2=0;
	
}
int main ()
{
	scanf("%d%s",&n,v);
	len1=strlen(v);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",u);
		len2=strlen(u);
		if(judge(u,v))
		{
			vec.push_back(i);
		}
	}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++)
	{
		printf("%d ",vec[i]);
	}
	return 0;
}