#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,l,t,k,m=1;
    int num[2050],tt[2050];
    char s[3],str[2050],ss[10];
    while(~scanf("%d",&n)&&n)
    {
        for(i=1; i<=n; i++)
            scanf("%s",s);
        scanf("%s",str);
        l=strlen(str);
        for(i=l; i<2*l; i++)
            num[i]=str[i-l]-'0';
        int h=0;
        scanf("%d",&t);
        for(i=0; i<t; i++)
        {
            scanf("%s",ss);
            k=1;
            for(j=0; j<n; j++)
            {
                if(ss[j]=='0')
                    k=k*2;
                else
                    k=k*2+1;
            }
            tt[h++]=num[k];
        }
        printf("S-Tree #%d:\n",m++);
        for(i=0;i<h;i++)
            printf("%d",tt[i]);
            printf("\n\n");
        }
    return 0;
}