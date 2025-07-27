#include <iostream>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
int main ()
{
	int n;
	char s1[10010],s2[10010];
	while(~scanf("%d %s %s",&n,s1,s2))
	{
		int i,j=0,flag=0;
		stack<char> u;
		for(i=0;i<n;i++)
		{
			if(s1[i]==s2[j])
			{
				j++;
			    while(!u.empty()&&u.top()==s2[j])
			    {
			    	j++;
			    	u.pop();
				}
			}
			else
			{
				u.push(s1[i]);
				if(u.size()>9)
				flag=1;
			}
		}
		if(flag==1||!u.empty())
		printf("No.\n");
		else
         {
         		printf("Yes.\n");
			i=0;
			j=0;
			for(i;i<n;i++)
		{
			printf("in\n");
			if(s1[i]==s2[j])
			{
				printf("out\n");
				j++;
			    while(!u.empty()&&u.top()==s2[j])
			    {
			    	printf("out\n");
			    	j++;
			    	u.pop();
				}
			}
			else
			{
				u.push(s1[i]);
			}
		}
		}
		printf("FINISH\n");
		 }
	return 0;
}