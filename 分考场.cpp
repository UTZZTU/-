#include<stdio.h>
#include<string.h>
#define N 301
#define min(a,b) a>b?b:a 
int gxb[N][N];//关系表 
int p[N][N];// 房间状态  
int num=N,n;
void DFS(int x,int kcs){//x 代表当前安排了多少个人 kcs 代表考场数
  if(kcs>=num)return;//剪子 
  if(x==n+1){num=min(num,kcs);return;}//如果已经安排了n个人，进行判断  
	 int j,k;
	for(j=1;j<=kcs;j++){//枚举考场
     k=0;
   	 while(p[j][k]&&!gxb[x][p[j][k]])k++;//找到一个空位 并且与该考场人无关系 
	if(p[j][k]==0)p[j][k]=x,DFS(x+1,kcs),p[j][k]=0;//满足条件 进行下一考生 
   }                                    //回溯 
	 p[j][0]=x;
	 DFS(x+1,kcs+1);// 如果所有房间都不满足条件 增加房间 
	 p[j][0]=0;//回溯 
}
int main(){
	int m,i,s1,s2;
	memset(gxb,0,sizeof(gxb));
	memset(p,0,sizeof(p));
	scanf("%d\n%d",&n,&m);
	for(i=1;i<=m;i++){ 
	 scanf("%d%d",&s1,&s2);
	 gxb[s1][s2]=gxb[s2][s1]=1;//建关系 
	}
	  DFS(1,1);
	printf("%d\n",num);
	return 0;
}
