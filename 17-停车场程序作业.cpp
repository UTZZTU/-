#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct A
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct A *next;
};
struct B
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct B *next;
};
struct C
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
	struct C *next;
};
struct sum
{
	int year,month,day;
	double money;
};
struct car
{
	char pnumber[4];
	char cnumber[20];
	int hour,min;
};
#define LENA sizeof(struct A)
#define LENB sizeof(struct B)
#define LENC sizeof(struct C)
struct A *creatA(void)
{
	struct A *p1=NULL,*p2=NULL;
	struct A *head=NULL;
	int i;
	for(i=1;i<=20;i++)
	{
		p1=(struct A*)malloc(LENA);
		p1->pnumber[0]='A';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  if(i!=20)
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]=i%10+48;
		}
		else
		{
			p1->pnumber[1]='2';
			p1->pnumber[2]='0';
		}
		p1->pnumber[3]='\0';
	    p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
struct B *creatB(void)
{
	struct B *p1=NULL,*p2=NULL;
	struct B *head=NULL;
	int i;
	for(i=1;i<=15;i++)
	{
		p1=(struct B*)malloc(LENB);
		p1->pnumber[0]='B';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]=i%10+48;
		}
		p1->pnumber[3]='\0';
		p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
struct C *creatC(void)
{
	struct C *p1=NULL,*p2=NULL;
	struct C *head=NULL;
	int i;
	for(i=1;i<=10;i++)
	{
		p1=(struct C*)malloc(LENC);
		p1->pnumber[0]='C';
		if(i<=9)
		{
			p1->pnumber[1]='0';
			p1->pnumber[2]=i+48;
		}
		else  
		{
			p1->pnumber[1]='1';
			p1->pnumber[2]='0';
		}
		p1->pnumber[3]='\0';
		p1->cnumber[0]='0'; 
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
int main ()
{
	struct A *Ahead,*p1,*q1;
	struct B *Bhead,*p2,*q2;
	struct C *Chead,*p3,*q3;
	struct sum s[10000];
	struct car w[10000];
	Chead=creatC();
	Ahead=creatA();
	Bhead=creatB();
	char compare[100],example1[]="����",example2[]="����",example3[]="С��",carnum[100],model[20],placenum[20],choose='y';
	 int function,cs=0,i,pdjy,xiaoshi,fenzhong,zd=0;
	 FILE*fp;
	 pdjy=0;
	 if((fp=fopen("car.txt","r"))==NULL)
				 {
				 	fp=fopen("car.txt","w");
					fclose(fp);
					exit(0);
				 }
	 fp=fopen("car.txt","r");
	 while(fscanf(fp,"%s %s %d %d",placenum,carnum,&xiaoshi,&fenzhong)!=EOF)
	 {
	 		p1=Ahead;
	 		while(p1->next!=NULL)
	 		{
	 			if(strcmp(p1->pnumber,placenum)==0)
	 			{
	 				strcpy(p1->cnumber,carnum);
	 				p1->hour=xiaoshi;
	 				p1->min=fenzhong;
	 				zd=1;
				 }
				 p1=p1->next;
			 }
			 if(strcmp(p1->pnumber,placenum)==0)
	 			{
	 				strcpy(p1->cnumber,carnum);
	 				p1->hour=xiaoshi;
	 				p1->min=fenzhong;
	 				zd=1;
				 }
				 if(zd==0)
				 {
				 	p2=Bhead;
	 		while(p2->next!=NULL)
	 		{
	 			if(strcmp(p2->pnumber,placenum)==0)
	 			{
	 				strcpy(p2->cnumber,carnum);
	 				p2->hour=xiaoshi;
	 				p2->min=fenzhong;
	 				zd=1;
				 }
				 p2=p2->next;
			 }
			 if(strcmp(p2->pnumber,placenum)==0)
	 			{
	 				strcpy(p2->cnumber,carnum);
	 				p2->hour=xiaoshi;
	 				p2->min=fenzhong;
	 				zd=1;
				 }
				 if(zd==0)
				 {
				 	p3=Chead;
	 		while(p3->next!=NULL)
	 		{
	 			if(strcmp(p3->pnumber,placenum)==0)
	 			{
	 				strcpy(p3->cnumber,carnum);
	 				p3->hour=xiaoshi;
	 				p3->min=fenzhong;
				 }
				 p3=p3->next;
			 }
			 if(strcmp(p3->pnumber,placenum)==0)
	 			{
	 				strcpy(p3->cnumber,carnum);
	 				p3->hour=xiaoshi;
	 				p3->min=fenzhong;
				 }
				 }
		 }
	 }
	 fclose(fp);
	 p3=Chead;
	 			while(p3->cnumber[0]!='0'&&p3->next!=NULL)
	 			{
	 				p3=p3->next;
				 }
				 if(p3->cnumber[0]!='0')
				 {
				 	strcpy(Chead->pnumber,"C00");
				 }
				 else
				 {
					strcpy(Chead->pnumber,p3->pnumber);
				 }
	p2=Bhead;
	 			while(p2->cnumber[0]!='0'&&p2->next!=NULL)
	 			{
	 				p2=p2->next;
				 }
				 if(p2->cnumber[0]!='0')
				 {
				 	strcpy(Bhead->pnumber,"B00");
				 }
				 else
				 {
					strcpy(Bhead->pnumber,p2->pnumber);
				 }
	p1=Ahead;
	 			while(p1->cnumber[0]!='0'&&p1->next!=NULL)
	 			{
	 				p1=p1->next;
				 }
				 if(p1->cnumber[0]!='0')
				 {
				 	strcpy(Ahead->pnumber,"A00");
				 }
				 else
				 {
					strcpy(Ahead->pnumber,p1->pnumber);
				 }	 			 
	 while(choose=='y'||choose=='Y')
	 {
	 	if(pdjy==0)
	 	{ 
	 		printf("��ӭ��ʹ�ø�ϵͳ��\n");
	 		pdjy=1;
		 }
	 printf("������ʹ�����¹��ܣ�\n");
	 printf("1.�������� 1 �ɽ���ͣ������\n");
	 printf("2.�������� 2 �ɽ��нɷѡ�\n");
	 printf("3.�������� 3 �ɽ��в�ѯ������\n");
	 printf("4.�������� 4 �ɽ���ͳ�ƹ�����\n");
	 printf("����������ѡ������Ҫ�ķ���");
	 scanf("%d",&function);
	 if(function!=1&&function!=2&&function!=3&&function!=4)
	 {
	 	printf("����������������޷��ṩ�÷���\n");
	  	printf("������������ȷ�������Ա������ṩ��������");
	  	scanf("%d",&function);
	 }
	  if(function==1)
	 {
	 	printf("���������ĳ��ͣ����͡����ͻ�С�ͣ���");
	 	scanf("%s",model);
	 	if(strcmp(model,example1)==0||strcmp(model,"��")==0)
	 	{
	 		if(strcmp(Chead->pnumber,"C00")!=0)
	 		{
	 			p3=Chead;
	 			while(p3->cnumber[0]!='0'&&p3->next!=NULL)
	 			{
	 				p3=p3->next;
				 }
	 			q3=p3;
				 printf("���������ĳ��ƺţ�");
				 scanf("%s",carnum);
				 strcpy(q3->cnumber,carnum);
				 printf("��������Ҫ��ʼͣ����ʱ��(����24Сʱ��ʱ����ֻ������Сʱ�����Ӽ��ɣ����磺12 30)��");
				 scanf("%d %d",&q3->hour,&q3->min);
				  printf("���ĳ�λ��Ϊ��%s,��Ǻã�\n",p3->pnumber);
				  fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p3->pnumber,carnum,q3->hour,q3->min);
				  fclose(fp);
				  printf("ͣ���ɹ�����ע�ⰴʱȡ��Ŷ��\n");
				 p3=Chead;
	 			while(p3->cnumber[0]!='0'&&p3->next!=NULL)
	 			{
	 				p3=p3->next;
	 				cs++;
				 }
				 if(p3->cnumber[0]!='0')
				 {
				 	strcpy(Chead->pnumber,"C00");
				 }
				 else
				 {
					strcpy(Chead->pnumber,p3->pnumber);
				 }
			 }
			 else
			 {
			 	printf("�ǳ���Ǹ����ʱ��δ����ͳ�ͣ���������޿�λ��\n");
			 }	
		 }
		 else if(strcmp(model,example2)==0||strcmp(model,"��")==0)
	 	{
	 		if(strcmp(Bhead->pnumber,"B00")!=0)
	 		{
	 			p2=Bhead;
	 			while(p2->cnumber[0]!='0'&&p2->next!=NULL)
	 			{
	 				p2=p2->next;
				 }
	 			q2=p2;
				 printf("���������ĳ��ƺţ�");
				 scanf("%s",carnum);
				 strcpy(q2->cnumber,carnum);
				 printf("��������Ҫ��ʼͣ����ʱ��(����24Сʱ��ʱ����ֻ������Сʱ�����Ӽ��ɣ����磺12 30)��");
				 scanf("%d %d",&q2->hour,&q2->min);
				  printf("���ĳ�λ��Ϊ��%s,��Ǻã�\n",p2->pnumber);
				  fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p2->pnumber,carnum,q2->hour,q2->min);
				  fclose(fp);
				  printf("ͣ���ɹ�����ע�ⰴʱȡ��Ŷ��\n");
				 p2=Bhead;
	 			while(p2->cnumber[0]!='0'&&p2->next!=NULL)
	 			{
	 				p2=p2->next;
				 }
				 if(p2->cnumber[0]!='0')
				 {
				 	strcpy(Bhead->pnumber,"B00");
				 }
				 else
				 {
					strcpy(Bhead->pnumber,p2->pnumber);
				 }
			 }
			 else
			 {
			 	printf("�ǳ���Ǹ����ʱ��δ����ͳ�ͣ���������޿�λ��\n");
			 }	
		 }
		 else if(strcmp(model,example3)==0||strcmp(model,"С")==0)
	 	{
	 		if(strcmp(Ahead->pnumber,"A00")!=0)
	 		{
	 			p1=Ahead;
	 			while(p1->cnumber[0]!='0'&&p1->next!=NULL)
	 			{
	 				p1=p1->next;
				 }
	 			q1=p1;
				 printf("���������ĳ��ƺţ�");
				 scanf("%s",carnum);
				 strcpy(q1->cnumber,carnum);
				 printf("��������Ҫ��ʼͣ����ʱ��(����24Сʱ��ʱ����ֻ������Сʱ�����Ӽ��ɣ����磺12 30)��");
				 scanf("%d %d",&q1->hour,&q1->min);
				 printf("���ĳ�λ��Ϊ��%s,��Ǻã�\n",p1->pnumber);
				 fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p1->pnumber,carnum,q1->hour,q1->min);
				  fclose(fp);
				 printf("ͣ���ɹ�����ע�ⰴʱȡ��Ŷ��\n");
				 p1=Ahead;
	 			while(p1->cnumber[0]!='0'&&p1->next!=NULL)
	 			{
	 				p1=p1->next;
				 }
				 if(p1->cnumber[0]!='0')
				 {
				 	strcpy(Ahead->pnumber,"A00");
				 }
				 else
				 {
					strcpy(Ahead->pnumber,p1->pnumber);
				 }
			 }
			 else
			 {
			 	printf("�ǳ���Ǹ����ʱ��δ����ͳ�ͣ���������޿�λ��\n");
			 }	
		 }
		 else
		 {
		 	printf("���´������׼��ȷ�ĳ����Ա�ϵͳΪ������лл��ϣ�\n");
		 }
	  } 
	  else if(function==2)
	  {
	  	int year,month,day,hour,min,time1,time2,parttime,pdrq=0,jfxz,jfsb=0,i,j;
	  	double money;
	  	printf("�����뵱ǰ��ʱ�䣨�꣬�£��գ�Сʱ�����ӣ���");
		scanf("%d%d%d%d%d",&year,&month,&day,&hour,&min);
		printf("��������ͣ��ʱ�ĳ�λ�ţ�");
		scanf("%s",placenum);
		jfsb=0;
		if(placenum[0]=='a'||placenum[0]=='A')
		{
			printf("���������ĳ��ƺţ�");
			scanf("%s",carnum);
			p1=Ahead;
			while(strcmp(p1->cnumber,carnum)!=0&&p1->next!=NULL)
			{
				p1=p1->next;
			}
			time1=hour*60+min;
			time2=p1->hour*60+p1->min;
			parttime=time1-time2;
			if(parttime<=0)
			{
				printf("�����ʱ���������´�������ȷ��ʱ�䣡\n");
			}
			else
			{
							if(parttime%60!=0)
			{
				if(parttime%60<=30)
				{
					money=parttime/60*3+1.5;
				}
				else
				{
					money=parttime/60*3+3;
				}
			}
			else
			{
				money=parttime/60*3;
			}
			printf("����Ҫ���ɵ�ͣ������Ϊ��");
			printf("%.1fԪ",money);
			printf("\n");
			printf("����ʹ��΢�Ż�֧������ɨ��ɷѣ��������� 1 ����΢�Ŷ�ά�룬�������� 2 ����֧������ά�룬���������֣�");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("΢�Žɷѳɹ���\n");
			else if(jfxz==2)
			printf("֧�����ɷѳɹ���\n");
			else 
			{
				printf("�ɷ�ʧ�ܣ������µ���ϵͳ���нɷѣ�\n");
				jfsb=1;
			}
			if(jfsb!=1)
			{
				fp=fopen("car.txt","r");
				i=0;
				while(fscanf(fp,"%s %s %d %d",w[i].pnumber,w[i].cnumber,&w[i].hour,&w[i].min)!=EOF)
				{
					if(strcmp(placenum,w[i].pnumber)==0)
					{
						strcpy(w[i].cnumber,"0");
					}
					i++;
				}
				fclose(fp);
				fp=fopen("car.txt","w");
				for(j=0;j<i;j++)
				{
					if(w[j].cnumber[0]!='0')
					{
						fprintf(fp,"%s %s %d %d\n",w[j].pnumber,w[j].cnumber,w[j].hour,w[j].min);
					}
				}
				fclose(fp);
				strcpy(p1->cnumber,"0");
			p1->hour=0;
			p1->min=0;
			p1=Ahead;
	 			while(p1->cnumber[0]!='0'&&p1->next!=NULL)
	 			{
	 				p1=p1->next;
				 }
				 if(p1->cnumber[0]!='0')
				 {
				 	strcpy(Ahead->pnumber,"A00");
				 }
				 else
				 {
					strcpy(Ahead->pnumber,p1->pnumber);
				 }
				 i=0;
				 if((fp=fopen("money.txt","r"))==NULL)
				 {
				 	fp=fopen("money.txt","w");
					fclose(fp);
					exit(0);
				 }
				 fp=fopen("money.txt","r");
				 while(fscanf(fp,"%d��%d��%d�գ�%lfԪ",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
				 {
				 	if(year==s[i].year&&month==s[i].month&&day==s[i].day)
				 	{
				 		s[i].money+=money;
				 		pdrq=1;
					 }
					 i++;
				 }
				 fclose(fp);
				 if(pdrq==0)
				 {
				    fp=fopen("money.txt","a");
				    fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else if(placenum[0]=='b'||placenum[0]=='B')
		{
			printf("���������ĳ��ƺţ�");
			scanf("%s",carnum);
			p2=Bhead;
			while(strcmp(p2->cnumber,carnum)!=0&&p2->next!=NULL)
			{
				p2=p2->next;
			}
			time1=hour*60+min;
			time2=p2->hour*60+p2->min;
			parttime=time1-time2;
			if(parttime<=0)
			{
				printf("�����ʱ���������´�������ȷ��ʱ�䣡\n");
			}
			else
			{
							if(parttime%60!=0)
			{
				if(parttime%60<=30)
				{
					money=parttime/60*3+2;
				}
				else
				{
					money=parttime/60*3+4;
				}
			}
			else
			{
				money=parttime/60*4;
			}
			printf("����Ҫ���ɵ�ͣ������Ϊ��");
			printf("%.1fԪ",money);
			printf("\n");
			printf("����ʹ��΢�Ż�֧������ɨ��ɷѣ��������� 1 ����΢�Ŷ�ά�룬�������� 2 ����֧������ά�룬���������֣�");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("΢�Žɷѳɹ���\n");
			else if(jfxz==2)
			printf("֧�����ɷѳɹ���\n");
			else 
			{
				printf("�ɷ�ʧ�ܣ������µ���ϵͳ���нɷѣ�\n");
				jfsb=1;
			}
			if(jfsb!=1)
			{
				fp=fopen("car.txt","r");
				i=0;
				while(fscanf(fp,"%s %s %d %d",w[i].pnumber,w[i].cnumber,&w[i].hour,&w[i].min)!=EOF)
				{
					if(strcmp(placenum,w[i].pnumber)==0)
					{
						strcpy(w[i].cnumber,"0");
					}
					i++;
				}
				fclose(fp);
				fp=fopen("car.txt","w");
				for(j=0;j<i;j++)
				{
					if(w[j].cnumber[0]!='0')
					{
						fprintf(fp,"%s %s %d %d\n",w[j].pnumber,w[j].cnumber,w[j].hour,w[j].min);
					}
				}
				fclose(fp);
				strcpy(p2->cnumber,"0");
			p2->hour=0;
			p2->min=0;
			p2=Bhead;
	 			while(p2->cnumber[0]!='0'&&p2->next!=NULL)
	 			{
	 				p2=p2->next;
				 }
				 if(p2->cnumber[0]!='0')
				 {
				 	strcpy(Bhead->pnumber,"B00");
				 }
				 else
				 {
					strcpy(Bhead->pnumber,p2->pnumber);
				 }
				 i=0;
				 if((fp=fopen("money.txt","r"))==NULL)
				 {
				 	fp=fopen("money.txt","w");
					fclose(fp);
					exit(0);
				 }
				 fp=fopen("money.txt","r");
				 while(fscanf(fp,"%d��%d��%d�գ�%lfԪ",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
				 {
				 	if(year==s[i].year&&month==s[i].month&&day==s[i].day)
				 	{
				 		s[i].money+=money;
				 		pdrq=1;
					 }
					 i++;
				 }
				 fclose(fp);
				 if(pdrq==0)
				 {
				    fp=fopen("money.txt","a");
				    fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else if(placenum[0]=='c'||placenum[0]=='C')
		{
			printf("���������ĳ��ƺţ�");
			scanf("%s",carnum);
			p3=Chead;
			while(strcmp(p3->cnumber,carnum)!=0&&p3->next!=NULL)
			{
				p3=p3->next;
			}
			time1=hour*60+min;
			time2=p3->hour*60+p3->min;
			parttime=time1-time2;
			if(parttime<=0)
			{
				printf("�����ʱ���������´�������ȷ��ʱ�䣡\n");
			}
			else
			{
							if(parttime%60!=0)
			{
				if(parttime%60<=30)
				{
					money=parttime/60*3+2.5;
				}
				else
				{
					money=parttime/60*3+5;
				}
			}
			else
			{
				money=parttime/60*5;
			}
			printf("����Ҫ���ɵ�ͣ������Ϊ��");
			printf("%.1fԪ",money);
			printf("\n");
			printf("����ʹ��΢�Ż�֧������ɨ��ɷѣ��������� 1 ����΢�Ŷ�ά�룬�������� 2 ����֧������ά�룬���������֣�");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("΢�Žɷѳɹ���\n");
			else if(jfxz==2)
			printf("֧�����ɷѳɹ���\n");
			else 
			{
				printf("�ɷ�ʧ�ܣ������µ���ϵͳ���нɷѣ�\n");
				jfsb=1;
			}
			if(jfsb!=1)
			{
				fp=fopen("car.txt","r");
				i=0;
				while(fscanf(fp,"%s %s %d %d",w[i].pnumber,w[i].cnumber,&w[i].hour,&w[i].min)!=EOF)
				{
					if(strcmp(placenum,w[i].pnumber)==0)
					{
						strcpy(w[i].cnumber,"0");
					}
					i++;
				}
				fclose(fp);
				fp=fopen("car.txt","w");
				for(j=0;j<i;j++)
				{
					if(w[j].cnumber[0]!='0')
					{
						fprintf(fp,"%s %s %d %d\n",w[j].pnumber,w[j].cnumber,w[j].hour,w[j].min);
					}
				}
				fclose(fp);
				strcpy(p3->cnumber,"0");
			p3->hour=0;
			p3->min=0;
			p3=Chead;
	 			while(p3->cnumber[0]!='0'&&p3->next!=NULL)
	 			{
	 				p3=p3->next;
				 }
				 if(p3->cnumber[0]!='0')
				 {
				 	strcpy(Chead->pnumber,"C00");
				 }
				 else
				 {
					strcpy(Chead->pnumber,p3->pnumber);
				 }
				 i=0;
				 if((fp=fopen("money.txt","r"))==NULL)
				 {
				 	fp=fopen("money.txt","w");
					fclose(fp);
					exit(0);
				 }
				 fp=fopen("money.txt","r");
				 while(fscanf(fp,"%d��%d��%d�գ�%lfԪ",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
				 {
				 	if(year==s[i].year&&month==s[i].month&&day==s[i].day)
				 	{
				 		s[i].money+=money;
				 		pdrq=1;
					 }
					 i++;
				 }
				 fclose(fp);
				 if(pdrq==0)
				 {
				    fp=fopen("money.txt","a");
				    fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d��%d��%d�գ�%lfԪ\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else
		printf("���´�������ȷ�ĳ�λ���Ա�ϵͳΪ���ṩ����\n");
	  }
	  else if(function==3)
	  {
	  	int decision,xz1=0;
	  	  printf("1.�������� 1 �ɲ鿴A����B����C����ǰ��ͣ�ŵ���������Ϣ��\n");
	  	  printf("2.�������� 2 �ɲ鿴��ǰA����B����C�����еĳ�λ�š�\n");
	  	  printf("3.�������� 3 ��ͨ�����ƺŲ��ҳ�����ͣ�ŵĳ�λ�š�\n");
	  	  printf("����������ѡ������Ҫ�ķ���");
		  scanf("%d",&decision);
		  if(decision==1)
		  {
		  	p1=Ahead;
		  	printf("A���ĳ�����Ϣ���£�\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("��λ�ţ�A01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->cnumber,p1->hour,p1->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
				  p1=p1->next;
				  xz1++;
			  }
		  	if(p1->cnumber[0]!='0')
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
			p2=Bhead;
			xz1=0;
			 printf("B���ĳ�����Ϣ���£�\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("��λ�ţ�B01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->cnumber,p2->hour,p2->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
				  p2=p2->next;
				  xz1++;
			  }
		  	if(p2->cnumber[0]!='0')
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
		  	p3=Chead;
		  	xz1=0;
			 printf("C���ĳ�����Ϣ���£�\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("��λ�ţ�C01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->cnumber,p3->hour,p3->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
				  p3=p3->next;
				  xz1++;
			  }
		  	if(p3->cnumber[0]!='0')
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
		   }else if(decision==2)
		   {
		   	int xz2=0;
		   	p1=Ahead;
		  	printf("A���Ŀ��г�λ�����£�\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("��λ�ţ�A01\n");
		  			else
		  			printf("��λ�ţ�%s\n",p1->pnumber);
				  }
				  p1=p1->next;
				  xz2++;
			  }
		  	if(p1->cnumber[0]=='0')
		  		{
		  			printf("��λ�ţ�%s\n",p1->pnumber);
				  }
			p2=Bhead;
			xz2=0;
			 printf("B���Ŀ��г�λ�����£�\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("��λ�ţ�B01\n");
		  			else
		  			printf("��λ�ţ�%s\n",p2->pnumber);
				  }
				  p2=p2->next;
				  xz2++;
			  }
		  	if(p2->cnumber[0]=='0')
		  		{
		  			printf("��λ�ţ�%s\n",p2->pnumber);
				  }
		  	p3=Chead;
		  	xz2=0;
			 printf("C���Ŀ��г�λ�����£�\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("��λ�ţ�C01\n");
		  			else
		  			printf("��λ�ţ�%s\n",p3->pnumber);
				  }
				  p3=p3->next;
				  xz2++;
			  }
		  	if(p3->cnumber[0]=='0')
		  		{
		  			printf("��λ�ţ�%s\n",p3->pnumber);
				  }
		   }else if(decision==3)
		   {
		   	int a=0,b=0,c=0,xz3=0;
		   	printf("�����복�ƺţ�");
		   	scanf("%s",carnum);
		   	p1=Ahead;
		   	while(p1->next!=NULL)
		   	{
		   		if(strcmp(p1->cnumber,carnum)==0)
		   		{
		   			if(xz3==0)
		   			printf("�ó���λ��Ϊ��A01\n");
		   			else
		   			printf("�ó���λ��Ϊ��%s\n",p1->pnumber);
		   			if(a<19)
		   			p1=p1->next;
		   			break;
				   }
				   else a++;
				   p1=p1->next;
				   xz3++;
			   }
			   if(strcmp(p1->cnumber,carnum)==0)
		   			printf("�ó���λ��Ϊ��%s\n",p1->pnumber);
			   else a++;
			   if(a>=20)
			   {
			   	p2=Bhead;
				xz3=0;
			   	while(p2->next!=NULL)
		   	{
		   		if(strcmp(p2->cnumber,carnum)==0)
		   		{
		   			if(xz3==0)
		   				printf("�ó���λ��Ϊ��B01\n");
		   			else
		   				printf("�ó���λ��Ϊ��%s\n",p2->pnumber);
		   				if(b<14)
		   				p2=p2->next;
		   			break;
				   }
				   else b++;
				   p2=p2->next;
				   xz3++;
			   }
			   if(strcmp(p2->cnumber,carnum)==0)
		   			printf("�ó���λ��Ϊ��%s\n",p2->pnumber);
			   else b++;
			   }
			   if(b>=15)
			   {
			   	p3=Chead;
			   	xz3=0;
			   	while(p3->next!=NULL)
		   	{
		   		if(strcmp(p3->cnumber,carnum)==0)
		   		{
		   			if(xz3==0)
		   			printf("�ó���λ��Ϊ��C01\n");
		   			else
		   			printf("�ó���λ��Ϊ��%s\n",p3->pnumber);
		   			if(c<9)
		   			p3=p3->next;
		   			break;
				   }
				   else c++;
				   p3=p3->next;
				   xz3++;
			   }
			   if(strcmp(p3->cnumber,carnum)==0)
		   			printf("�ó���λ��Ϊ��%s\n",p3->pnumber);
			   else c++;
			   }
			   if(c>=10)
			   {
			   	printf("����ĳ��������޷����ҵ��ó�����Ϣ��\n");
			   }
		   }
	  }
	  else if(function==4)
	  {
	  	int decide,num1=0,num2=0,num3=0;
	  	   printf("1.�������� 1 �ɲ鿴A����B����C����ǰ��ͣ�ŵ�������������\n");
	  	   printf("2.�������� 2 �ɽ�һ�������ض�����������\n");
	  	   printf("3.�������� 3 ��ͳ��ĳ��ͣ�������շ��ܽ�\n");
	  	   printf("����������ѡ������Ҫ�ķ���");
	  	   scanf("%d",&decide);
	  	   if(decide==1)
	  	   {
	  	   	p1=Ahead;
		  	printf("A���������������£�\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]!='0')
		  		{
		  		num1++;
				  }
				  p1=p1->next;
			  }
		  	if(p1->cnumber[0]!='0')
		  		{
		  			num1++;
				  }
				  printf("����������%d\n",num1);
			p2=Bhead;
			 printf("B���������������£�\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]!='0')
		  		{
		  			num2++;
				  }
				  p2=p2->next;
			  }
		  	if(p2->cnumber[0]!='0')
		  		{
		  			num2++;
				  }
				  printf("����������%d\n",num2);
		  	p3=Chead;
			 printf("C���������������£�\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]!='0')
		  		{
		  			num3++;
				  }
				  p3=p3->next;
			  }
		  	if(p3->cnumber[0]!='0')
		  		{
		  			num3++;
				  }
	  	   	printf("����������%d\n",num3);
			 }else if(decide==2)
			 {
			 	int xs,fz,xz=0;
			 	printf("�����뵱ǰʱ��(Сʱ������)��");
			 	scanf("%d %d",&xs,&fz);
			 	p1=Ahead;
		  	printf("A���ĳ�����Ϣ���£�\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]!='0'&&xs-p1->hour>=5&&fz-p1->min>=0)
		  		{
		  			if(xz==0)
		  			printf("��λ�ţ�A01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->cnumber,p1->hour,p1->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
				  p1=p1->next;
				  xz++;
			  }
		  	if(p1->cnumber[0]!='0'&&xs-p1->hour>=5&&fz-p1->min>=0)
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
			p2=Bhead;
			xz=0;
			 printf("B���ĳ�����Ϣ���£�\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]!='0'&&xs-p2->hour>=5&&fz-p2->min>=0)
		  		{
		  			if(xz==0)
		  			printf("��λ�ţ�B01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->cnumber,p2->hour,p2->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
				  p2=p2->next;
				  xz++;
			  }
		  	if(p2->cnumber[0]!='0'&&xs-p2->hour>=5&&fz-p2->min>=0)
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
		  	p3=Chead;
		  	xz=0;
			 printf("C���ĳ�����Ϣ���£�\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]!='0'&&xs-p3->hour>=5&&fz-p3->min>=0)
		  		{
		  			if(xz==0)
		  			printf("��λ�ţ�C01  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->cnumber,p3->hour,p3->min);
		  			else
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
				  p3=p3->next;
				  xz++;
			  }
		  	if(p3->cnumber[0]!='0'&&xs-p3->hour>=5&&fz-p3->min>=0)
		  		{
		  			printf("��λ�ţ�%s  ���ƺţ�%s  ͣ��ʱ�䣺%d��%d��\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
			 }else if(decide==3)
			 {
			 	int n,y,year1,month1,day1;
			 	double money1,summoney=0;
			 	printf("���������ڣ��꣬�£���");
			 	scanf("%d %d",&n,&y);
			 	fp=fopen("money.txt","r");
			 	while(fscanf(fp,"%d��%d��%d�գ�%lfԪ",&year1,&month1,&day1,&money1)!=EOF)
			 	{
			 		if(n==year1&&y==month1)
			 		{
			 			summoney+=money1;
					 }
				 }
				 fclose(fp);
				 printf("���µ��շѽ��Ϊ��%.1f\n",summoney);
			 } 
		}
		printf("���Ƿ�Ҫ����������y/n)?:");
		getchar();
		choose=getchar();
		if(choose!='n'&&choose!='N'&&choose!='y'&&choose!='Y')
		{
			printf("�������ָ������ϵͳ���ܱ����������ȷ��ָ�\n");
			printf("��������ָ��(y/n)��");
			getchar();
			choose=getchar();
		}
		if(choose=='n'||choose=='N')
		printf("��л����ʹ�ã��ڴ����´ι��٣�");
	  }
	  return 0;
}
