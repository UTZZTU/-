#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;
int sum[maxn];
void Sum(char str[maxn])
{
    int length, num[maxn];
    memset(num, 0, sizeof(num));
    length = strlen(str);
    for(int i = 0; i < length; i++)
        num[i] = str[length - i - 1] - '0';
    for(int i = 0; i < maxn - 1; i++)
    {
        sum[i] += num[i];
        if(sum[i] >= 10)
        {
            sum[i] %= 10;
            sum[i+1]++;
        }
    }
}
int main()
{
    char str[maxn];
    memset(sum, 0, sizeof(sum));
    while(scanf("%s", str))
    {
        if(str[0] == '0' && str[1] == 0)
            break;
        Sum(str);
    }
    bool isBegin = false;
    for(int i = maxn - 1; i >= 0; i--)
    {
        if(isBegin)
            printf("%d",sum[i]);
        else if(sum[i])
        {
            printf("%d",sum[i]);
            isBegin = true;
        }
    }
    if(!isBegin)
        printf("0");
    printf("\n");
    return 0;
}
