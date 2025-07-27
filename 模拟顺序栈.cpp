#include <iostream>
using namespace std;
const int Maxsize = 110;
//静态定义
typedef struct sqstack{
	int data[Maxsize];
	int top;
}sqstack;
//动态定义
/*
typedef struct sqstack{
    int *base;
    int *top;
}sqstack;
bool InitStack(sqstack &s)
{
    s.base=new int[Maxsize];
    if(!s.base)
    return false;
    s.top=s.base;
    return true;
}
bool push(sqstack &s,int e)
{
    if(s.top-s.base==Maxsize)
    return false;
    *(s.top++)=e;
    return true;
}
bool pop(sqstack &s,int &e)
{
    if(s.top==s.base)
    return false;
    e=*(--s.top);
    return true;
}
int GetTop(sqstack &s)
{
    if(s.top==s.base)
    return -1;
    else
    return *(s.top-1);
}
*/
int main ()
{
	return 0;
}
