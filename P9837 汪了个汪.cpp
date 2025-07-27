#include <bits/stdc++.h>
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
using namespace std;
int n,t;
vector<int> vec[4010];
bool cmp(vector<int> v1,vector<int> v2)
{
	return v1.size()<v2.size();
}
int main () {
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    {
    	int p=i,tt=1;
    	vec[i].push_back(i);
    	while(1)
    	{
    		if(i+tt>=1&&i+tt<=n)
    		{
    			vec[i].push_back(i+tt);
			}
			else break;
			if(i-tt>=1&&i-tt<=n)
    		{
    			vec[i].push_back(i-tt);
			}
			else break;
			tt++;
		}
	}
	sort(vec+1,vec+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			printf("%d ",vec[i][j]);
		}
		printf("\n");
	}
    return 0;
}
