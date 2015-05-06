#include<iostream>
using namespace std;
struct Treenode
{
	int data;
	Treenode *lchild;
	Treenode *rchild;
};
//�ؽ����������ݹ鹹��
Treenode *build(int *first,int *second,int length)
{
	//�жϲ����Ƿ�Ϸ�
	if(first==NULL||second==NULL||length<=0)
		return NULL;
	int rootvalue=first[0];
	Treenode *root=new Treenode();
	root->data=rootvalue;
	root->lchild=root->rchild=NULL;
	//ֻ��һ�����ʱ����
	if(length==1)
	{
		if(first[0]==second[0])
			return root;
		else
			throw exception("input error!");//�׳��쳣��C#����throw new exception();
	}
	//������ʱ��ݹ�
	else
	{
		int i=0;
		//������������ҵ�root���
		while(i<length&&second[i]!=rootvalue)
			i++;
		if(i==length)
			throw exception("input error!!");
		//�ݹ���������i��ߵ�����
		if(i>0)
		{
			root->lchild=build(first+1,second,i);
		}
		//�ݹ���������i�ұߵ�����
		if(i<length-1)
		{
			root->rchild=build(first+i+1,second+i+1,length-i-1);
		}
	}
	return root;
}
//���������ӡ������
void print(Treenode *root)
{
	if(root)
	{
		print(root->lchild);
	    cout<<root->data<<endl;
		print(root->rchild);
	}
}
int main()
{
	try
	{
		int a[10]={1,2,4,7,3,5,6,8};
		int b[10]={4,7,2,1,5,3,8,6};
		Treenode *root=build(a,b,8);
		print(root);
	}
	catch(const exception &e)
	{
		cerr<<e.what()<<endl;//cerr��������쳣
	}
}
