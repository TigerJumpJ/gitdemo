#include<stdio.h>
#include<stdlib.h>
#define N 3
#define M 12500
struct node
{	
	int Data;
	struct node *Link;	
 } *H;
void delete_same(struct node **H)
{
	struct node *p,*x;
	p=*H;
	while(p!=0)    //��ѭ�� 
	{
		//printf("p=%d\n",p->Data);
		x=p;	//x����������ͬ����������ִ��ɾ�� 
		while(x->Link!=0)	
		{
			//printf("Сѭ��������Ϊ: %d\n",x->Link->Data);
		 	if(x->Link!=0 && x->Link->Data==p->Data) x->Link=x->Link->Link;  //���x����β��  and x����һ����p��ͬ��ɾ��x����һ�� 
			else if(x->Link->Data!=p->Data) x=x->Link;				//���x����һ����p����ͬ���ƶ�x 
		}
		p=p->Link;
	} 
}

