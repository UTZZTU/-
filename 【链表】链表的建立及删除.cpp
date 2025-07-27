#include <stdio.h>
#include <stdlib.h>
struct stu_node
{
	int num;
	struct stu_node *next;
};
#define LEN sizeof(struct stu_node)
struct stu_node *creat(void)
{
	struct stu_node *p1=NULL,*p2=NULL;
	struct stu_node *head=NULL;
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		p1=(struct stu_node*)malloc(LEN);
		p1->num=n;
		if(head==NULL)
		{
			head=p1;
		}
		else  p2->next=p1;
		p2=p1;
		scanf("%d",&n);
	}
	p2->next=NULL;
	return head;
}
void list(struct stu_node*head)
{
	struct stu_node *p;
		p=head;
		printf("%d",p->num);
		p=p->next;
		while(p!=NULL)
		{
			printf(" %d",p->num);
			p=p->next;
		}
}
struct stu_node *del(struct stu_node *head,int num)
{
	struct stu_node *p1,*p2=NULL;
	
		p1=head;
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
			if(p1==head)
			head=p1->next;
			else
			p2->next=p1->next;
			free(p1);
	return head;
}
int main ()
{
	struct stu_node *head;
	int num;
	head=creat();
	scanf("%d",&num);
	head=del(head,num);
	list(head);
	return 0;
}
