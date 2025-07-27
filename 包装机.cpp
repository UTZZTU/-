#include <iostream>
#include <stack>
using namespace std;
char w[1000005];
int main ()
{
	char s[105][1005];
	stack<char >u;
	int n,m,sm,i,a[105],q=0,k;
	scanf("%d %d %d",&n,&m,&sm);
	for(i=1;i<=n;i++)
	{
		a[i]=m;
	}
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
	}
	while(~scanf("%d",&k))
	{
		if(k==-1)
		break;
		else
		{
			if(k!=0)
			{
				if(a[k]!=0&&u.size()<sm)
				{
					u.push(s[k][m-a[k]]);
					a[k]--;
				}
				else if(a[k]!=0&&u.size()==sm)
				{
					w[q]=u.top();
					u.pop();
					u.push(s[k][m-a[k]]);
					a[k]--;
					q++;
				}
			}
			else
			{
				if(!u.empty())
				{
					w[q]=u.top();
				u.pop();
				q++;
				}
			}
		}
	}
	w[q]='\0';
	printf("%s",w);
	return 0;
}