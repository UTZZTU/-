#include<iostream>
#include<cstdio>
using namespace std;
char c[202000];
int main()
{
    int n,x,i,sum=0;
    scanf("%d",&n);
    scanf("%s",c+1);
    for(i=n;i>1;)
    {
        if(c[i]==c[i-1])
        c[i]='0',i=i-1,sum++;//��ͬʹc[i]Ϊ'0',sum++����¼ɾ���Ĵ�����
        else
        i=i-2;//�����ͬ�Ļ���iֱ�Ӽ�������λ��
    }
    if((n-sum)%2==0)//n-sumΪʣ�µ��ַ������ȣ��ж��Ƿ�Ϊż��
    {
        printf("%d\n",sum);
        for(i=1;i<=n;i++)
        if(c[i]!='0')
        printf("%c",c[i]);
    }
    else//�����Ϊż������ɾ����һ���ַ����ӵڶ����ַ���ʼ���
    {
        printf("%d\n",sum+1);
        for(i=2;i<=n;i++)
        if(c[i]!='0')
        printf("%c",c[i]);
    }
    return 0;
}
