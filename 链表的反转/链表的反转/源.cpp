#include<iostream>
using namespace std;
struct listnode
{
	int data;
	listnode *next;
};
//�������õ�����ͷ��㶼�ǿյ�
//β�巨��������
listnode *init()
{
	listnode *head=(listnode *)malloc(sizeof(listnode));
	head->next=NULL;
	listnode *p=head;
	cout<<"please input a number(��-1����)"<<endl;
	int data;
	cin>>data;
	while(data!=-1)
	{
		listnode *temp=(listnode *)malloc(sizeof(listnode));
		temp->data=data;
		temp->next=p->next;
		p->next=temp;
		p=temp;
		cout<<"please input a number(��-1����)"<<endl;
		cin>>data;
	}
	return head;
}
//��ӡ����
void print(listnode *head)
{
	listnode *p=head->next;
	while(p)
	{
		cout<<p->data<<"	";
		p=p->next;
	}
	cout<<endl;
}
//��ת����ʹ������ָ��ֱ�ָ��ǰ��㣬��ǰ����ǰһ�����͵�ǰ������һ����㣩
listnode *reverselist(listnode *head)
{
	if(head==NULL)
		return NULL;
	listnode *now=head->next;//��ǰ���
	listnode *newhead=(listnode *)malloc(sizeof(listnode));//�½���ͷָ��
	newhead->next=NULL;
	//ֻ��һ�����,ͷ��㣨�գ�
	if(now==NULL)
		return head;
	listnode *pre=NULL;//��ǰ����ǰһ�����
	while(now !=NULL)
	{
		listnode *pnext=now->next;		//���浱ǰ������һ�����
		//�����ǰ������һ�����Ϊ�գ��򹹽��µ�ͷ���
		if(now->next==NULL)
		{
			newhead->next=now;
		}
		//����ǰ����nextָ������ǰһ�����
		now->next=pre;
		//pre��nowָ�붼����
		pre=now;
		now=pnext;
		
	}
	return newhead;
}
int main()
{
	listnode *head=init();
	print(head);
	head=reverselist(head);
	print(head);
	return 0;
}