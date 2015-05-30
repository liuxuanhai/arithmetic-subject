#include<iostream>
using namespace std;
struct treenode
{
	char data;
	treenode *lchild;
	treenode *rchild;
};
//���򴴽�������
treenode *init()
{
	char data;
	cout<<"please inpur a number:(#����NULL)"<<endl;
	cin>>data;
	if(data=='#')
		return NULL;
	treenode *head=new treenode;
	head->data=data;
	head->lchild=init();
	head->rchild=init();
	return head;
}
//����ݹ����������
void print(treenode *head)
{
	if(head)
	{
		cout<<head->data<<"	";
		print(head->lchild);
		print(head->rchild);
	}
}
//ת��������������
void change(treenode *head)
{
	if(head==NULL)
		return;
	if(head->lchild==NULL && head->rchild==NULL)
		return;
	//�����ý������ҽ��
	treenode *temp=head->lchild;
	head->lchild=head->rchild;
	head->rchild=temp;
	//�ݹ�������
	if(head->lchild)
		change(head->lchild);
	//�ݹ�������
	if(head->rchild)
		change(head->rchild);
}
int main()
{
	treenode *head=init();
	print(head);
	cout<<endl;
	change(head);
	print(head);
	cout<<endl;
	return 0;
}