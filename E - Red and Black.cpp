#include<stdio.h>
int dir[4][2]= {{1,0},{0,-1},{0,1},{-1,0}};//��������
char a[25][25];
int num,m,n;//num�������ߵĺ�ש����
void DFS(int x,int y)
{
    num++;
    a[x][y]='#';//��ֹ�ظ���¼
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
        num=0;//ÿһ�ζ���ʼ��0
        getchar();//�Ե��س���
        for(i=0;i<m; i++)
            scanf("%s",a[i]); //һ��һ�е�����
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
