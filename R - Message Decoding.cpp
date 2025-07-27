#include<stdio.h>
#include<string.h> 
int readchar()//读取字符，当遇到'\n'&&\r'时返回输入的字符（跨行读字符）
{
    for(;;)
    {
        int ch=getchar();
        if(ch!='\n'&&ch!='\r')
        {
            return ch;
        }
    }
}
int readint(int c)//者读取c位二进制字符（即0和1），并转化为十进制整数。
{
    int v=0;
    while(c--)
    {
        v=v*2+readchar()-'0';
    }
    return v;
}
int code[8][1<<8];
int readcodes()//读取编码
{
    memset(code,0,sizeof(code));
    code[1][0] = readchar(); //直接调到下一行开始读取。如果输入已经结束，会读到EOF
    for(int len = 2; len <=7; len++)
    {
        for(int i=0;i<(1<<len)-1;i++)
        {
            int ch = getchar();
            if(ch==EOF)
                return 0;
            if(ch=='\n'||ch=='\r')
                return 1;
            code[len][i] = ch;
        }
    }
    return 1;
} 
int main()
{
    while(readcodes())
    {
        for(;;)
        {
            int len = readint(3);
            if(len == 0)
                break;
            for(;;)
            {
                int v=readint(len);
                if(v==(1<<len)-1)
                    break;
            putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}