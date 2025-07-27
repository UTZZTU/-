#include<iostream>

#include<cstdio>

#include<string>

#include<map>

#include<set>

#include<queue>

#include<vector>

using namespace std;

int i,j,n,m,a,b,c,sum,ans;

int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()

{

    scanf("%d%d",&n,&m);

    for (i=1;i<=12;i++)

        for (j=1;j<=s[i];j++)

        {

            c=(j%10)*1000+

              (j/10)*100+

              (i%10)*10+

              (i/10);

            sum=c*10000+i*100+j;

            if (sum<n||sum>m) continue;

            ans++;

        }

    printf("%d",ans);

    return 0;

}