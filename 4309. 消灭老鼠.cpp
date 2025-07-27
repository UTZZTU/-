#include <iostream>
#include <map>
using namespace std;
map<double,int> mp1,mp2;
int n,x0,y0,x,y,xx,yy,res;
int main ()
{
	scanf("%d%d%d",&n,&x0,&y0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		x-=x0,y-=y0;
		if(x==0&&y==0)
		{
			xx++,yy++;
		}
		else if(x==0)
		{
			yy++;
		}
		else if(y==0)
		{
			xx++;
		}
		else
		{
			if(x>0&&y>0||x<0&&y<0)
			{
				mp1[y*1.0/x]++;
			}
			else
			{
				mp2[y*1.0/x]++;
			}
		}
	}
	res+=mp1.size()+mp2.size();
	if(xx) res++;
	if(yy) res++;
	cout<<res;
	return 0;
}