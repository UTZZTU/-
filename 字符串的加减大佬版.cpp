#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,k,t=0,o=0;  
    char c[10000],c1[1000000],c2[1000000],c3[100];           //cΪ��+����-��//c1c2 ������ַ��� 
    while(1)
    {   
        o++  ; 
        if(o>=2)gets(c3);                                    //�ӵڶ��ο�ʼ����һ���س� 
        scanf("%c",&c[o]);
        if(c[o]==0)break;                                    //�����EOF�ͽ�����ascall�����EOF=0��//printf("%c\n",c);//�������Ե� 
        for(i=0;i<10000;i++)
        {
            c1[i]=c2[i]='\0';                               //�������� 
        }
        scanf("%s",&c1);scanf("%s",&c2);                    //����c1c2 
        if(c[o]=='+')
        {
            for(i=0,j=0;c1[i]!='\0'||c2[j]!='\0';i++,j++)   //�����û���ַ���ֹͣ 
            {
                if(c1[i]!='\0')printf("%c",c1[i]);
                else k=0;
                if(c2[j]!='\0')printf("%c",c2[j]);          //�������/0����� 
                else k=0;
            } 
            printf("\n");                                   //������ӡ�س� 
        }
        if(c[o]=='-')                                       //�����-�� 
        {
            for(i=0;c1[i]!='\0';i++)
            {
                if(c1[i]!='\0')
                {
                    k=1;                                     //�����ж��Ƿ��ظ� 
                    for(j=0;c2[j]!='\0';j++)                //����һ�����û������ַ��ʹ�ӡ 
                    {
                        if(c2[j]==c1[i])
                        {
                            k=0;break;
                        }
                    }
                    if(k==1)printf("%c",c1[i]);
                    else k=k;                              //����else������ 
                }
            } 
            printf("\n");                                  //������ӡ�س�
        }
        continue;
    }
    return 0;
}
