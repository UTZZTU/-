#include<stdio.h>
int dir[4][2]= {{1,0},{0,-1},{0,1},{-1,0}};//上下左右
char a[25][25];
int num,m,n;//num代表能走的黑砖个数
void DFS(int x,int y)
{
    num++;
    a[x][y]='#';//防止重复记录
    for(int i=0;i<4; i++)
    {
        int p,q;
        p=x+dir[i][0];
        q=y+dir[i][1];
        if(p>=0&&q>=0&&p<m&&q<n&&a[p][q]=='.')
        {
            DFS(p,q);
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)&&n>0&&m>0)
    {
        num=0;//每一次都初始化0
        getchar();//吃掉回车符
        for(i=0;i<m; i++)
            scanf("%s",a[i]); //一行一行的输入
        for(i=0;i<m; i++)
         for(j=0; j<n; j++)
          if(a[i][j]=='@')
                {
                   a[i][j]='#';
                    DFS(i,j);
                    break;
                }
        printf("%d\n",num);
    }
    return 0;
}
