#include <stdio.h>
#include <string.h>
int main ()
{
    char s[110][110],w[110][110],q;
    int n,i,j,k1,k2,sum=0;
    scanf("%c %d",&q,&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%c",&s[i][j]);
        s[i][j]='\0';
        if(i!=n)
            getchar();
    }
    k1=1;
    for(i=n;i>=1;i--)
    {
        w[k1][n]='\0';
        k2=0;
        for(j=n-1;j>=0;j--)
        {
            w[k1][k2]=s[i][j];
            k2++;
        }
        k1++;
    }
    for(i=1;i<=n;i++)
    {
        if(strcmp(w[i],s[i])==0)
            sum++;
    }
    if(sum==n)
        printf("bu yong dao le\n");
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(w[i][j]=='@')
                printf("%c",q);
            else
                printf("%c",w[i][j]);
        }
        printf("\n");
    }
    return 0;
}