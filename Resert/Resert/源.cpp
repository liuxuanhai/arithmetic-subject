#include<iostream>
#include<stack>
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
//ʹ��ջ��ʵ�ִ�β��ͷ��ӡ����
void usestack(listnode *head)
{
	if(head!=NULL)
	{
		stack<int> s=stack<int>();
		listnode *temp=head->next;
		while(temp!=NULL)//ѭ����ջ
		{
			s.push(temp->data);
			temp=temp->next;
		}
		while(s.size()!=0)//ѭ����ջ
		{
			cout<<"  "<<s.top();
			s.pop();
		}
	}
}
//��ת������ʵ���������
listnode *resert(listnode *head)
{
	listnode *now=head->next;
	listnode *pre=NULL;
	listnode *newhead=NULL;
	while(now!=NULL)
	{
		listnode *next=now->next;//��¼��ǰ�����¸���㣬�Ա��ڷ�תָ��
		if(next==NULL)//�����ǰ����ָ����¸����Ϊ�գ���¼��ǰ���󷵻�
			newhead=now;
		now->next=pre;//��תָ��
		//ָ�����
		pre=now;
		now=next;
	}
	listnode *hhead=(listnode *)malloc(sizeof(listnode));//���ڵ�һ����Ϊ�գ����������һ����ͷ
	hhead->next=newhead;
	return hhead;
}
int main()
{
	listnode *head=init();
	print(head);
	cout<<endl;
	usestack(head);
	cout<<endl;
	head=resert(head);
	print(head);
}