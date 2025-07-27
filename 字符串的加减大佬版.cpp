#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,t=0,o=0;  
    char c[10000],c1[1000000],c2[1000000],c3[100];           //c为‘+’或‘-’//c1c2 输入的字符串 
    while(1)
    {   
        o++  ; 
        if(o>=2)gets(c3);                                    //从第二次开始吸收一个回车 
        scanf("%c",&c[o]);
        if(c[o]==0)break;                                    //如果是EOF就结束（ascall码表中EOF=0）//printf("%c\n",c);//用来测试的 
        for(i=0;i<10000;i++)
        {
            c1[i]=c2[i]='\0';                               //重置数组 
        }
        scanf("%s",&c1);scanf("%s",&c2);                    //输入c1c2 
        if(c[o]=='+')
        {
            for(i=0,j=0;c1[i]!='\0'||c2[j]!='\0';i++,j++)   //如果都没有字符就停止 
            {
                if(c1[i]!='\0')printf("%c",c1[i]);
                else k=0;
                if(c2[j]!='\0')printf("%c",c2[j]);          //如果不是/0就输出 
                else k=0;
            } 
            printf("\n");                                   //别忘打印回车 
        }
        if(c[o]=='-')                                       //如果是-号 
        {
            for(i=0;c1[i]!='\0';i++)
            {
                if(c1[i]!='\0')
                {
                    k=1;                                     //用来判断是否重复 
                    for(j=0;c2[j]!='\0';j++)                //遍历一边如果没有这个字符就打印 
                    {
                        if(c2[j]==c1[i])
                        {
                            k=0;break;
                        }
                    }
                    if(k==1)printf("%c",c1[i]);
                    else k=k;                              //吸收else，无用 
                }
            } 
            printf("\n");                                  //别忘打印回车
        }
        continue;
    }
    return 0;
}
