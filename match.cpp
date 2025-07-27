#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stack>
#define LL long long
#define INF 0x7fffffff
#define MAX 105
#define PI 3.1415926535897932
#define E 2.718281828459045
using namespace std;
int num[6] = {0,1, 2, 3, 4, 5};
string str[8];
string ans;
vector <string> v;
int main()
{
 
 
      for(int i = 0; i <6; i++)
        cin >> str[i];
    //用next_permutation和num完成字符串的随机组合 然后进行条件判断 选择合适的放入容器
    do
    {
        ans=str[num[0]] + str[num[1]] + str[num[2]];
 
        if(ans[0] != str[num[3]][0] || ans[3] != str[num[3]][1] || ans[6] != str[num[3]][2])
            continue;
        if(ans[1] != str[num[4]][0] || ans[4] != str[num[4]][1] || ans[7] != str[num[4]][2])
            continue;
        if(ans[2] != str[num[5]][0] || ans[5] != str[num[5]][1] || ans[8] != str[num[5]][2])
            continue;
        //将三个单词放入九宫格中 然后依次判断这三个单词的放入 是否能够组成其他单词
        v.push_back(ans);
    }while(next_permutation(num,num+6));
 
    if(v.size() ==0)
    {
        printf("0\n");
    }
    else
    {
        sort(v.begin(),v.end());
        for(int i=0;i<9;i++)
        {
            printf("%c",v[0][i]);
            if((i+1) %3 ==0) printf("\n");
        }
    }
    return 0;
}