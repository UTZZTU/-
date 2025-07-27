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
	char compare[100],example1[]="大型",example2[]="中型",example3[]="小型",carnum[100],model[20],placenum[20],choose='y';
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
	 		printf("欢迎您使用该系统！\n");
	 		pdjy=1;
		 }
	 printf("您可以使用以下功能：\n");
	 printf("1.输入数字 1 可进行停车服务。\n");
	 printf("2.输入数字 2 可进行缴费。\n");
	 printf("3.输入数字 3 可进行查询操作。\n");
	 printf("4.输入数字 4 可进行统计工作。\n");
	 printf("请输入数字选择您需要的服务：");
	 scanf("%d",&function);
	 if(function!=1&&function!=2&&function!=3&&function!=4)
	 {
	 	printf("您输入的数字有误，无法提供该服务！\n");
	  	printf("请重新输入正确的数字以便我们提供给您服务：");
	  	scanf("%d",&function);
	 }
	  if(function==1)
	 {
	 	printf("请输入您的车型（大型、中型或小型）：");
	 	scanf("%s",model);
	 	if(strcmp(model,example1)==0||strcmp(model,"大")==0)
	 	{
	 		if(strcmp(Chead->pnumber,"C00")!=0)
	 		{
	 			p3=Chead;
	 			while(p3->cnumber[0]!='0'&&p3->next!=NULL)
	 			{
	 				p3=p3->next;
				 }
	 			q3=p3;
				 printf("请输入您的车牌号：");
				 scanf("%s",carnum);
				 strcpy(q3->cnumber,carnum);
				 printf("请输入您要开始停车的时间(请用24小时计时法，只需输入小时、分钟即可，例如：12 30)：");
				 scanf("%d %d",&q3->hour,&q3->min);
				  printf("您的车位号为：%s,请记好！\n",p3->pnumber);
				  fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p3->pnumber,carnum,q3->hour,q3->min);
				  fclose(fp);
				  printf("停车成功，请注意按时取车哦！\n");
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
			 	printf("非常抱歉，该时间段此类型车停车区域已无空位！\n");
			 }	
		 }
		 else if(strcmp(model,example2)==0||strcmp(model,"中")==0)
	 	{
	 		if(strcmp(Bhead->pnumber,"B00")!=0)
	 		{
	 			p2=Bhead;
	 			while(p2->cnumber[0]!='0'&&p2->next!=NULL)
	 			{
	 				p2=p2->next;
				 }
	 			q2=p2;
				 printf("请输入您的车牌号：");
				 scanf("%s",carnum);
				 strcpy(q2->cnumber,carnum);
				 printf("请输入您要开始停车的时间(请用24小时计时法，只需输入小时、分钟即可，例如：12 30)：");
				 scanf("%d %d",&q2->hour,&q2->min);
				  printf("您的车位号为：%s,请记好！\n",p2->pnumber);
				  fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p2->pnumber,carnum,q2->hour,q2->min);
				  fclose(fp);
				  printf("停车成功，请注意按时取车哦！\n");
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
			 	printf("非常抱歉，该时间段此类型车停车区域已无空位！\n");
			 }	
		 }
		 else if(strcmp(model,example3)==0||strcmp(model,"小")==0)
	 	{
	 		if(strcmp(Ahead->pnumber,"A00")!=0)
	 		{
	 			p1=Ahead;
	 			while(p1->cnumber[0]!='0'&&p1->next!=NULL)
	 			{
	 				p1=p1->next;
				 }
	 			q1=p1;
				 printf("请输入您的车牌号：");
				 scanf("%s",carnum);
				 strcpy(q1->cnumber,carnum);
				 printf("请输入您要开始停车的时间(请用24小时计时法，只需输入小时、分钟即可，例如：12 30)：");
				 scanf("%d %d",&q1->hour,&q1->min);
				 printf("您的车位号为：%s,请记好！\n",p1->pnumber);
				 fp=fopen("car.txt","a");
				  fprintf(fp,"%s %s %d %d\n",p1->pnumber,carnum,q1->hour,q1->min);
				  fclose(fp);
				 printf("停车成功，请注意按时取车哦！\n");
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
			 	printf("非常抱歉，该时间段此类型车停车区域已无空位！\n");
			 }	
		 }
		 else
		 {
		 	printf("请下次输入标准正确的车型以便系统为您服务，谢谢配合！\n");
		 }
	  } 
	  else if(function==2)
	  {
	  	int year,month,day,hour,min,time1,time2,parttime,pdrq=0,jfxz,jfsb=0,i,j;
	  	double money;
	  	printf("请输入当前的时间（年，月，日，小时，分钟）：");
		scanf("%d%d%d%d%d",&year,&month,&day,&hour,&min);
		printf("请输入您停车时的车位号：");
		scanf("%s",placenum);
		jfsb=0;
		if(placenum[0]=='a'||placenum[0]=='A')
		{
			printf("请输入您的车牌号：");
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
				printf("输入的时间有误，请下次输入正确的时间！\n");
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
			printf("您需要交纳的停车费用为：");
			printf("%.1f元",money);
			printf("\n");
			printf("您可使用微信或支付宝来扫码缴费，输入数字 1 生成微信二维码，输入数字 2 生成支付宝二维码，请输入数字：");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("微信缴费成功！\n");
			else if(jfxz==2)
			printf("支付宝缴费成功！\n");
			else 
			{
				printf("缴费失败！请重新登入系统进行缴费！\n");
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
				 while(fscanf(fp,"%d年%d月%d日，%lf元",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
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
				    fprintf(fp,"%d年%d月%d日，%lf元\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d年%d月%d日，%lf元\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else if(placenum[0]=='b'||placenum[0]=='B')
		{
			printf("请输入您的车牌号：");
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
				printf("输入的时间有误，请下次输入正确的时间！\n");
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
			printf("您需要交纳的停车费用为：");
			printf("%.1f元",money);
			printf("\n");
			printf("您可使用微信或支付宝来扫码缴费，输入数字 1 生成微信二维码，输入数字 2 生成支付宝二维码，请输入数字：");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("微信缴费成功！\n");
			else if(jfxz==2)
			printf("支付宝缴费成功！\n");
			else 
			{
				printf("缴费失败！请重新登入系统进行缴费！\n");
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
				 while(fscanf(fp,"%d年%d月%d日，%lf元",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
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
				    fprintf(fp,"%d年%d月%d日，%lf元\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d年%d月%d日，%lf元\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else if(placenum[0]=='c'||placenum[0]=='C')
		{
			printf("请输入您的车牌号：");
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
				printf("输入的时间有误，请下次输入正确的时间！\n");
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
			printf("您需要交纳的停车费用为：");
			printf("%.1f元",money);
			printf("\n");
			printf("您可使用微信或支付宝来扫码缴费，输入数字 1 生成微信二维码，输入数字 2 生成支付宝二维码，请输入数字：");
			scanf("%d",&jfxz);
			if(jfxz==1)
			printf("微信缴费成功！\n");
			else if(jfxz==2)
			printf("支付宝缴费成功！\n");
			else 
			{
				printf("缴费失败！请重新登入系统进行缴费！\n");
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
				 while(fscanf(fp,"%d年%d月%d日，%lf元",&s[i].year,&s[i].month,&s[i].day,&s[i].money)!=EOF)
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
				    fprintf(fp,"%d年%d月%d日，%lf元\n",year,month,day,money);
				    fclose(fp);
				 }
				 else
				 {
				 	fp=fopen("money.txt","w");
				 	for(j=0;j<i;j++)
				 	{
				 		fprintf(fp,"%d年%d月%d日，%lf元\n",s[j].year,s[j].month,s[j].day,s[j].money);
					 }
				 	fclose(fp);
				 }
			}
			}
		}
		else
		printf("请下次输入正确的车位号以便系统为您提供服务！\n");
	  }
	  else if(function==3)
	  {
	  	int decision,xz1=0;
	  	  printf("1.输入数字 1 可查看A区，B区，C区当前所停放的汽车的信息。\n");
	  	  printf("2.输入数字 2 可查看当前A区，B区，C区空闲的车位号。\n");
	  	  printf("3.输入数字 3 可通过车牌号查找车辆所停放的车位号。\n");
	  	  printf("请输入数字选择您需要的服务：");
		  scanf("%d",&decision);
		  if(decision==1)
		  {
		  	p1=Ahead;
		  	printf("A区的车辆信息如下：\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("车位号：A01  车牌号：%s  停车时间：%d点%d分\n",p1->cnumber,p1->hour,p1->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
				  p1=p1->next;
				  xz1++;
			  }
		  	if(p1->cnumber[0]!='0')
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
			p2=Bhead;
			xz1=0;
			 printf("B区的车辆信息如下：\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("车位号：B01  车牌号：%s  停车时间：%d点%d分\n",p2->cnumber,p2->hour,p2->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
				  p2=p2->next;
				  xz1++;
			  }
		  	if(p2->cnumber[0]!='0')
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
		  	p3=Chead;
		  	xz1=0;
			 printf("C区的车辆信息如下：\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]!='0')
		  		{
		  			if(xz1==0)
		  			printf("车位号：C01  车牌号：%s  停车时间：%d点%d分\n",p3->cnumber,p3->hour,p3->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
				  p3=p3->next;
				  xz1++;
			  }
		  	if(p3->cnumber[0]!='0')
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
		   }else if(decision==2)
		   {
		   	int xz2=0;
		   	p1=Ahead;
		  	printf("A区的空闲车位号如下：\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("车位号：A01\n");
		  			else
		  			printf("车位号：%s\n",p1->pnumber);
				  }
				  p1=p1->next;
				  xz2++;
			  }
		  	if(p1->cnumber[0]=='0')
		  		{
		  			printf("车位号：%s\n",p1->pnumber);
				  }
			p2=Bhead;
			xz2=0;
			 printf("B区的空闲车位号如下：\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("车位号：B01\n");
		  			else
		  			printf("车位号：%s\n",p2->pnumber);
				  }
				  p2=p2->next;
				  xz2++;
			  }
		  	if(p2->cnumber[0]=='0')
		  		{
		  			printf("车位号：%s\n",p2->pnumber);
				  }
		  	p3=Chead;
		  	xz2=0;
			 printf("C区的空闲车位号如下：\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]=='0')
		  		{
		  			if(xz2==0)
		  			printf("车位号：C01\n");
		  			else
		  			printf("车位号：%s\n",p3->pnumber);
				  }
				  p3=p3->next;
				  xz2++;
			  }
		  	if(p3->cnumber[0]=='0')
		  		{
		  			printf("车位号：%s\n",p3->pnumber);
				  }
		   }else if(decision==3)
		   {
		   	int a=0,b=0,c=0,xz3=0;
		   	printf("请输入车牌号：");
		   	scanf("%s",carnum);
		   	p1=Ahead;
		   	while(p1->next!=NULL)
		   	{
		   		if(strcmp(p1->cnumber,carnum)==0)
		   		{
		   			if(xz3==0)
		   			printf("该车车位号为：A01\n");
		   			else
		   			printf("该车车位号为：%s\n",p1->pnumber);
		   			if(a<19)
		   			p1=p1->next;
		   			break;
				   }
				   else a++;
				   p1=p1->next;
				   xz3++;
			   }
			   if(strcmp(p1->cnumber,carnum)==0)
		   			printf("该车车位号为：%s\n",p1->pnumber);
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
		   				printf("该车车位号为：B01\n");
		   			else
		   				printf("该车车位号为：%s\n",p2->pnumber);
		   				if(b<14)
		   				p2=p2->next;
		   			break;
				   }
				   else b++;
				   p2=p2->next;
				   xz3++;
			   }
			   if(strcmp(p2->cnumber,carnum)==0)
		   			printf("该车车位号为：%s\n",p2->pnumber);
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
		   			printf("该车车位号为：C01\n");
		   			else
		   			printf("该车车位号为：%s\n",p3->pnumber);
		   			if(c<9)
		   			p3=p3->next;
		   			break;
				   }
				   else c++;
				   p3=p3->next;
				   xz3++;
			   }
			   if(strcmp(p3->cnumber,carnum)==0)
		   			printf("该车车位号为：%s\n",p3->pnumber);
			   else c++;
			   }
			   if(c>=10)
			   {
			   	printf("输入的车牌有误，无法查找到该车辆信息！\n");
			   }
		   }
	  }
	  else if(function==4)
	  {
	  	int decide,num1=0,num2=0,num3=0;
	  	   printf("1.输入数字 1 可查看A区，B区，C区当前所停放的汽车的数量。\n");
	  	   printf("2.输入数字 2 可进一步查找特定汽车数量。\n");
	  	   printf("3.输入数字 3 可统计某月停车场的收费总金额。\n");
	  	   printf("请输入数字选择您需要的服务：");
	  	   scanf("%d",&decide);
	  	   if(decide==1)
	  	   {
	  	   	p1=Ahead;
		  	printf("A区的汽车数量如下：\n");
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
				  printf("车辆数量：%d\n",num1);
			p2=Bhead;
			 printf("B区的汽车数量如下：\n");
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
				  printf("车辆数量：%d\n",num2);
		  	p3=Chead;
			 printf("C区的汽车数量如下：\n");
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
	  	   	printf("车辆数量：%d\n",num3);
			 }else if(decide==2)
			 {
			 	int xs,fz,xz=0;
			 	printf("请输入当前时间(小时，分钟)：");
			 	scanf("%d %d",&xs,&fz);
			 	p1=Ahead;
		  	printf("A区的车辆信息如下：\n");
		  	while(p1->next!=NULL)
		  	{
		  		if(p1->cnumber[0]!='0'&&xs-p1->hour>=5&&fz-p1->min>=0)
		  		{
		  			if(xz==0)
		  			printf("车位号：A01  车牌号：%s  停车时间：%d点%d分\n",p1->cnumber,p1->hour,p1->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
				  p1=p1->next;
				  xz++;
			  }
		  	if(p1->cnumber[0]!='0'&&xs-p1->hour>=5&&fz-p1->min>=0)
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p1->pnumber,p1->cnumber,p1->hour,p1->min);
				  }
			p2=Bhead;
			xz=0;
			 printf("B区的车辆信息如下：\n");
		  	while(p2->next!=NULL)
		  	{
		  		if(p2->cnumber[0]!='0'&&xs-p2->hour>=5&&fz-p2->min>=0)
		  		{
		  			if(xz==0)
		  			printf("车位号：B01  车牌号：%s  停车时间：%d点%d分\n",p2->cnumber,p2->hour,p2->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
				  p2=p2->next;
				  xz++;
			  }
		  	if(p2->cnumber[0]!='0'&&xs-p2->hour>=5&&fz-p2->min>=0)
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p2->pnumber,p2->cnumber,p2->hour,p2->min);
				  }
		  	p3=Chead;
		  	xz=0;
			 printf("C区的车辆信息如下：\n");
		  	while(p3->next!=NULL)
		  	{
		  		if(p3->cnumber[0]!='0'&&xs-p3->hour>=5&&fz-p3->min>=0)
		  		{
		  			if(xz==0)
		  			printf("车位号：C01  车牌号：%s  停车时间：%d点%d分\n",p3->cnumber,p3->hour,p3->min);
		  			else
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
				  p3=p3->next;
				  xz++;
			  }
		  	if(p3->cnumber[0]!='0'&&xs-p3->hour>=5&&fz-p3->min>=0)
		  		{
		  			printf("车位号：%s  车牌号：%s  停车时间：%d点%d分\n",p3->pnumber,p3->cnumber,p3->hour,p3->min);
				  }
			 }else if(decide==3)
			 {
			 	int n,y,year1,month1,day1;
			 	double money1,summoney=0;
			 	printf("请输入日期（年，月）：");
			 	scanf("%d %d",&n,&y);
			 	fp=fopen("money.txt","r");
			 	while(fscanf(fp,"%d年%d月%d日，%lf元",&year1,&month1,&day1,&money1)!=EOF)
			 	{
			 		if(n==year1&&y==month1)
			 		{
			 			summoney+=money1;
					 }
				 }
				 fclose(fp);
				 printf("该月的收费金额为：%.1f\n",summoney);
			 } 
		}
		printf("您是否要继续操作（y/n)?:");
		getchar();
		choose=getchar();
		if(choose!='n'&&choose!='N'&&choose!='y'&&choose!='Y')
		{
			printf("您输入的指令有误，系统不能辨别，请输入正确的指令！\n");
			printf("重新输入指令(y/n)：");
			getchar();
			choose=getchar();
		}
		if(choose=='n'||choose=='N')
		printf("感谢您的使用，期待您下次光临！");
	  }
	  return 0;
}
