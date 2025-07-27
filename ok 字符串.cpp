#include <cstdio>
int n,t,ans;
char s[1000005];
void deal(char ch)
{
    int i,j;
    i=j=1;
    if (s[1]!=ch) t--;
    while (j<n)
    {
        for (;j<n && s[j+1]==ch;j++);
        if (j-i+1>ans) ans=j-i+1;
        if (j==n)
        {
            break;
        }
        if (t)
        {
            t--;
            j++;
            if (j-i+1>ans) ans=j-i+1;
            continue;
        }
        for (;i<j && s[i]==ch;i++);
        i++;  j++;
    }
    return;
}
int main()
{
    int i,j,tt;
    scanf("%d%d",&n,&tt);
    scanf("%s",s+1);
    t=tt;
    deal('o');
    t=tt;
    deal('k');
    printf("%d",ans);
    return 0;
}