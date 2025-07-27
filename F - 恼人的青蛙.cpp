#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
 
#define MAXN (5000+10)
struct Point{
	int x,y;
};
int r,c;
int n;
int ans=0;
bool flag[MAXN][MAXN];
Point p[MAXN];
 
bool operator<(const Point &a,const Point &b)  //重载运算符 
{
	return(a.x<b.x||(a.x==b.x&&a.y<b.y));
}
 
bool Outside(int x1,int y1)     //判断点是否在农田之中 
{
	if(x1<=0||y1<=0||x1>r||y1>c)return true;
	return false;
}
 
//判断以点a和b为起点的路径是否存在 
bool count(int a,int b)
{
	int dx=p[b].x-p[a].x;
	int dy=p[b].y-p[a].y;
	//优化条件1：如果不能从稻田外跳到a点，则直接退出 
	if(!Outside(p[a].x-dx,p[a].y-dy))return false;
	//优化条件2：如果青蛙经过MAXSTEPS-1步会跳出去，那么直接退出 
	if(p[a].x+ans*dx<=0||p[a].x+ans*dx>r)return false;
	if(p[a].y+ans*dy<=0||p[a].y+ans*dy>c)return false;
	int k=2;
	int x1=p[b].x+dx;
	int y1=p[b].y+dy;
	while(!Outside(x1,y1)&&flag[x1][y1]) //按照步长将路径延伸 
	{
		++k;
		x1+=dx;
		y1+=dy;
	}
	if(Outside(x1,y1)&&k>ans)ans=k;
}
 
int main()
{
	scanf("%d%d%d",&r,&c,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);  //读入点 
		flag[p[i].x][p[i].y]=true;
	}
	sort(p,p+n);   //将点排序，注意这里重载了Point的<运算符 
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			count(i,j);   //枚举每一种情况 
	if(ans<3) ans=0;
	printf("%d\n",ans);
	return 0;
}
