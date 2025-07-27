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
		printf("����Ϊ�գ�\n");
	}
	else
	{
		printf("������Ϣ����\n");
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
	printf("����Ϊ�ղ��ܽ���ɾ��������\n");
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
			printf("�����ɾ����\n");
		}
	}
}
int main ()
{
	struct stu_node *head;int delnum;
	char ch='y';
	head=creat();
	list(head);
	printf("����ɾ��������\n");
	while(ch=='y'||ch=='Y')
	{
		printf("����Ҫɾ��ѧ����ѧ�ţ�");
		scanf("%d",&delnum);
		getchar();
		head=del(head,delnum) ;
		printf("����ɾ������ѧ������Ϣ��(y/n):");
		ch=getchar();
		getchar();
	}
	printf("ɾ�����ѧ����Ϣ��\n");
	list(head);
}
