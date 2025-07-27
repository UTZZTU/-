#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
char c,s[10010];
set<string> se;
int main()
{
    int i,pos=0;
    while(~(c=getchar()))
    {
        if(isalpha(c))//判断是否为字母
            s[pos++]=tolower(c);//如果为大写字母转化为小写字母
        else if(pos!=0)
        {
            s[pos]='\0';
            se.insert(s);
            pos=0;
        }
    }
    set<string>::iterator it;
    for(it = se.begin(); it != se.end(); it++)
        cout<< *it <<endl;
}