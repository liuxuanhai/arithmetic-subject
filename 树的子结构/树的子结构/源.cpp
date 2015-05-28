#include<iostream>
using namespace std;

struct treenode
{
	char data;
	treenode *lchild;
	treenode *rchild;
};
bool issame(treenode *head1,treenode *head2);
//���򹹽����������ݹ飩
treenode *init()
{
	treenode *head=new treenode;
	char data;
	cout<<"please input a number of node<��#����>"<<endl;
	cin>>data;
	if(data=='#')
		return NULL;
	else
	{
		head->data=data;
		head->lchild=init();
		head->rchild=init();
	}
	return head;
}
//�����ӡ������
void preorderprint(treenode *head)
{
	if(head)
	{
		cout<<head->data<<"	";
		preorderprint(head->lchild);
		preorderprint(head->rchild);
	}
}
//�жϵڶ������Ƿ�Ϊ��һ�������ӽṹ
bool contains(treenode *head1,treenode *head2)
{
	bool result=false;
	//�������κ������ӽṹ
	if(head2==NULL)
		return true;
	if(head1!=NULL)
	{
		//������������ȣ�������ж����ǵ������Ƿ����
		if(head1->data==head2->data)
			result=issame(head1,head2);
		//��������������ݹ��ж�������
		if(!result)
			result=contains(head1->lchild,head2);
		//��������������ݹ��ж�������
		if(!result)
			result=contains(head2->rchild,head2);
	}
	return result;
}
//�ݹ��ж��������������Ƿ�Ҳ��ͬ
bool issame(treenode *head1,treenode *head2)
{
	//����ڶ������Ϊ�գ��򷵻�true
	if(head2==NULL)
		return true;
	//��һ���ڵ�Ϊ�գ��򷵻�false
	if(head1==NULL)
		return false;
	//���������㶼��Ϊ�ղ������ǲ���ȣ�����false
	if(head1->data!=head2->data)
		return false;
	//������������ݹ��ж��������������Ľ���Ƿ����
	return issame(head1->lchild,head2->lchild)&&issame(head1->rchild,head2->rchild);
}
int main()
{
	treenode *head1=init();
	preorderprint(head1);
	cout<<endl;
	treenode *head2=init();
	preorderprint(head2);
	cout<<endl;
	cout<<"�Ƿ������"<<contains(head1,head2);
	return 0;
}