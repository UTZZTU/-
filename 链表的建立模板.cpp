#include <stdio.h>
#include <stdlib.h>
struct stu_node
{
	int num;
	float score;
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL,*p2=NULL;
	struct stu_node *head=NULL;
	int n;float s;
	scanf("%d %f",&n,&s);
	while(n!=0)
	{
		p1=(struct stu_node*)malloc(LEN);
		p1->num=n;p1->score=s;
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
		scanf("%d %f",&n,&s);
	}
	p2->next=NULL;
	return head;
}
void list(struct stu_node*head)
{
	struct stu_node *p;
	if(head==NULL)
	{
		printf("链表为空！\n");
	}
	else
	{
		printf("链表信息如下\n");
		p=head;
		while(p!=NULL)
		{
			printf("%d %5.2f\n",p->num,p->score);
			p=p->next;
		}
	}
}
struct stu_node *del(struct stu_node *head,int num)
{
	struct stu_node *p1,*p2=NULL;
	if(head==NULL)
	printf("链表为空不能进行删除操作！\n");
	else
	{
		p1=head;
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			if(p1==head)
			head=p1->next;
			else
			p2->next=p1->next;
			free(p1);
			printf("结点已删除！\n");
		}
	}
}
int main ()
{
	struct stu_node *head;int delnum;
	char ch='y';
	head=creat();
	list(head);
	printf("进行删除结点操作\n");
	while(ch=='y'||ch=='Y')
	{
		printf("输入要删除学生的学号：");
		scanf("%d",&delnum);
		getchar();
		head=del(head,delnum) ;
		printf("继续删除其他学生的信息吗？(y/n):");
		ch=getchar();
		getchar();
	}
	printf("删除后的学生信息：\n");
	list(head);
}
