#include<iostream>
using namespace std;
struct listnode
{
	int data;
	listnode *next;
};
//ʹ��β�巨��������
listnode *init()
{
	listnode *head=(listnode *)malloc(sizeof(listnode));
	head->next=NULL;
	listnode *last=head;
	int data;
	cout<<"�����룺����-1��������"<<endl;
	cin>>data;
	while(data!=-1)
	{
		listnode *temp=(listnode *)malloc(sizeof(listnode));
		temp->data=data;
		temp->next=last->next;//last����һ��ΪNULL
		last->next=temp;
		last=temp;
		cout<<"�����룺����-1��������"<<endl;
		cin>>data;
	}
	return head;
}
//��ӡ����
void print(listnode *head)
{
	listnode *temp=head->next;
	while(temp!=NULL)
	{
		cout<<"  "<<temp->data;
		temp=temp->next;
	}
}
//�ҵ�����ĵ�k�����
listnode *findnumberK(listnode *head,unsigned int k)
{
	//�жϲ����Ƿ���ȷ
	if(head==NULL||k==0)
	{
		return NULL;
	}
	listnode *first=head;
	listnode *second=first;
	//�ڶ���ָ����ǰ��k-1��
	for(int i=0;i<k-1;i++)
	{
		//�жϵڶ���ָ���next�Ƿ�Ϊ��
		if(second->next!=NULL)
			second=second->next;
		//û�е�k�����
		else
			return NULL;
	}
	//����ָ��ѭ����ǰ�ߣ��ڶ���ָ�뵽�������β�����һ��ָ�뵽���k�����
	while(second->next)
	{
		first=first->next;
		second=second->next;
	}
	return first;
}
int main()
{
	listnode *head=init();
	print(head);
	cout<<endl;
	cout<<findnumberK(head,3)->data<<endl;
	return 0;
}