#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define moo 1000000007//10^9+7
#define PI acos(-1.0)
#define eps 1e-5
using namespace std;
int ans[10000];
void cal(int sit)
{
    int x;
    scanf("%d",&x);
    if(x==-1)
        return;
    ans[sit]+=x;
    cal(sit-1);//统计左儿子
    cal(sit+1);//统计右儿子
}
int main()
{
    int n,ca=1;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("Case %d:\n",ca++);
        memset(ans,0,sizeof(ans));
        ans[5555]=n;//由于不知道左边有多少项所以设定一个比較靠中间的值作为根节点在的列。
 
cal(5554);cal(5556);
        int now=0;
        while(ans[now]==0)//去除前导零
            now++;
        int flag=0;
        for(int i=now;ans[i]!=0;flag=1,i++)
            printf((flag==0?"%d":" %d"),ans[i]);
        printf("\n\n");
    }
    return 0;
}