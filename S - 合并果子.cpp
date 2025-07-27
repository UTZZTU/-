#include <cmath>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 20005;
long long ans;
int sum1,sum2,temp;
priority_queue<int ,vector<int>,greater<int> > q;
int main()
{
    int n,k;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&k);
        q.push(k);
    }
    while(q.size() != 1)
    {
        sum1 = q.top();
        q.pop();
        sum2 = q.top();
        q.pop();
        temp = sum1+sum2;
        q.push(temp);
        ans += temp;
    } 
    printf("%lld\n",ans);
    return 0;
}
