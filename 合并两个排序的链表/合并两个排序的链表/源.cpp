#include<iostream>
using namespace std;
struct listnode
{
    int data;
    listnode *next;
};
//β�巨��������
listnode *init()
{
	listnode *head=new listnode;
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
        cout<<p->data<<"    ";
        p=p->next;
    }
    cout<<endl;
}
//��������������ϲ�(ѭ��ʵ��)
listnode *hebing(listnode *head1,listnode *head2)
{
	listnode *head=new listnode;
	head->next=NULL;
	//��������ָ��ֱ�ָ��������������ݿ�ʼ����
	listnode *p1=head1->next;
	listnode *p2=head2->next;
	//����һ��ָ����ָ������������һ�����,��ʼʱָ��head
	listnode *last=head;
	while(p1!=NULL && p2!=NULL)
	{
		//p1��������С����lastָ��p1��㣬last��p1�ֱ����
		if(p1->data<p2->data)
		{
			last->next=p1;
			p1=p1->next;
			last=last->next;
		}
		//p2�������С����lastָ��p2��㣬last��p2�ֱ����
		else
		{
			last->next=p2;
			p2=p2->next;
			last=last->next;
		}
	}
	//����һ���������ʱ�򣬽�lastָ��δ����������
	if(p1==NULL)
		last->next=p2;
	else if(p2==NULL)
		last->next=p1;
	return head;
}
//��������������ϲ�(�ݹ�ʵ��)
listnode *hebing2(listnode *head1,listnode *head2)
{
	//ѭ��������������һ���������β
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	listnode *head=NULL;
	//ѡ������ͷ����н�С����Ϊͷ���
	if(head1->data>head2->data)
	{
		head=head2;
		head->next=hebing2(head1,head2->next);
	}
	else
	{
		head=head1;
		head->next=hebing2(head1->next,head2);
	}
	return head;
}
//��Ϊ���ʱ���һ�����ʱ�յģ���Ҫ���һ���յ�ͷ���
listnode *diguihebing(listnode *head1,listnode *head2)
{
	listnode *head=new listnode;
	head->next=hebing2(head1->next,head2->next);
	return head;
}
int main()
{
	listnode *head1=init();
	print(head1);
	listnode *head2=init();
	print(head2);
	//listnode *head=hebing(head1,head2);//����ѭ������
	//print(head);
	listnode *head=diguihebing(head1,head2);//���Եݹ����
	print(head);
	delete head,head1,head2;
	return 0;
}