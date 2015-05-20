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
//ɾ�������е�ĳһ���
void deletenode(listnode *head,listnode *tobedeleted)
{
	try
	{
		if(!head||!tobedeleted)
			throw  exception("��������");
		//Ҫɾ���Ľ���������м�
		if(tobedeleted->next!=NULL)
		{
			listnode *temp=tobedeleted->next;//���Ҫɾ��������һ�����
			tobedeleted->data=temp->data;//����һ������ֵ������ǰ���
			tobedeleted->next=temp->next;//����ǰ����nextָ����һ������next����ɾ������һ�����
			delete temp;//�ͷ��ڴ�
			temp=NULL;
		}
		//Ҫɾ���Ľ����β���
		else
		{
			//�������Ҫɾ������ǰһ����㣬��ǰһ������nextֵ��ֵΪNULL
			listnode *p=head;
			while(p->next!=tobedeleted)
			
			{
				p=p->next;
			}
			p->next=tobedeleted->next;
			delete tobedeleted;
			tobedeleted=NULL;

		}
	}
	catch(exception e)
	{
		cerr<<e.what()<<endl;
	}
}
int main()
{
	listnode *head=init();
	listnode *tobedeleted=head->next->next;
	cout<<"ɾ��ǰ��ʾ��";
	print(head);
	cout<<endl<<"ɾ������ʾ��";
	deletenode(head,tobedeleted);
	print(head);
	cout<<endl;
	return 0;
}