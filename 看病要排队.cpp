#include <iostream>
#include <queue>
using namespace std;
struct p
{
	int lv;
	int bh;
	p(int a,int b){lv=a;bh=b;}
	bool operator<(const p& a)const
	{
		if(lv!=a.lv)
		return lv<a.lv;
		else
		return bh>a.bh;
	}
};
int main ()
{
	int n;
	while(cin>>n)
	{
		priority_queue<p> q1,q2,q3;
		string a="IN",b="OUT",c;
		int js=1;
		for(int i=1;i<=n;i++)
		{
			cin>>c;
			if(c==a)
			{
				int ys,dj;
				scanf("%d %d",&ys,&dj);
				if(ys==1)
				{
					q1.push(p(dj,js));
				}
				else if(ys==2)
				{
					q2.push(p(dj,js));
				}
				else
				q3.push(p(dj,js));
				js++;
			}
			else if(c==b)
			{
				int ys;
				scanf("%d",&ys);
				if(ys==1)
				{
					if(q1.empty())
					{
						printf("EMPTY\n");
					}
					else
					{
						cout<<q1.top().bh<<endl;
						q1.pop();
					}
				}
				else if(ys==2)
				{
					if(q2.empty())
					{
						printf("EMPTY\n");
					}
					else
					{
						cout<<q2.top().bh<<endl;
						q2.pop();
					}
				}
				else
				{
					if(q3.empty())
					{
						printf("EMPTY\n");
					}
					else
					{
						cout<<q3.top().bh<<endl;
						q3.pop();
					}
				}
			}
		}
	}
	return 0;
}