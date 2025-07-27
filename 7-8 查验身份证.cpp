#include <stdio.h>
int main ()
{
    char s[105][20],w[]="10X98765432",k;
    int i,n,a[105],pd=0,j,m=1,sum,b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        pd=0;
        sum=0;
        gets(s[i]);
        for(j=0;j<17;j++)
        {
            if(s[i][j]>='0'&&s[i][j]<='9')
            {
                sum+=(s[i][j]-'0')*b[j];
            }
            else
            {
                pd=1;
                a[m]=i;
                m++;
                break;
            }
        }
        if(pd==0)
        {
            sum%=11;
            k=w[sum];
            if(k!=s[i][j])
            {
                a[m]=i;
                m++;
            }
        }
    }
    if(m==1)
    {
        printf("All passed");
    }
    else
    {
        for(i=1;i<m-1;i++)
       printf("%s\n",s[a[i]]);
        printf("%s",s[a[i]]);
    }
    return 0;
}