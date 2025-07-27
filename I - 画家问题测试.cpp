#include <stdio.h>
#include <stdlib.h>
int mintimes=225;
int nowtimes=0;
void collor(int*a)
{
    *a?(*a=0):(*a=1);
}
void change(int*now,int size)
{
    collor(now);
    collor(now+1);
    collor(now-1);
    collor(now+size+2);
    collor(now-size-2);
}
void searchf(int i,int size,int*wall,int*record)//穷举第一行i~n的所有可能
{
    void paint(int*wall,int n,int*record);
    if(i<=size)
    {
        searchf(i+1,size,wall,record);
        change(wall+size+2+i,size);
        *(record+(size+2)+i)=1;
        searchf(i+1,size,wall,record);
        change(wall+size+2+i,size);
        *(record+(size+2)+i)=0;
    }
    else
        paint(wall,size,record);
}
void paint(int*wall,int n,int*record)
{
  
  
       int flag=0,i,j;
    for(i=1;i<n;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(*(wall+i*(n+2)+j)==0)
            {
                change(wall+(i+1)*(n+2)+j,n);
                *(record+(i+1)*(n+2)+j)=1;
                nowtimes++;
            }
        }
    }
    for(i=1;i<n+1;i++)
    {
        flag+=*(wall+n*(n+2)+i);
        nowtimes+=*(record+(n+2)+i);
    }
    if(flag==n&&nowtimes<mintimes)
        mintimes=nowtimes;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(*(record+i*(n+2)+j)==1)
            {
                change(wall+i*(n+2)+j,n);
                *(record+i*(n+2)+j)=0;
            }
        }
    }
    nowtimes=0;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int paint[n+2][n+2],record[n+2][n+2];
    for(i=1;i<n+1;i++)
        for(j=1;j<n+1;j++)
            record[i][j]=0;
    char wall[n+2][n+2];
    for(i=1;i<n+1;i++)
    {
        scanf("%s",&wall[i][1]);
        for(j=1;j<n+1;j++)
            (wall[i][j]=='w')?(paint[i][j]=0):(paint[i][j]=1);
    }
    searchf(1,n,paint[0],record[0]);
    (mintimes>200)?(printf("inf")):(printf("%d",mintimes));
    return 0;
}
