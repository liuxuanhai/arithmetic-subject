#include<iostream> 
#include<queue>
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
//����δ�ӡ������
void print(treenode *head)
{
	queue<treenode *>myque;
	if(head)
	{
		myque.push(head);
	}
	while(!myque.empty())
	{
		//��ö���ͷ�����ݲ���ӡ
		treenode *temp=myque.front();
		cout<<temp->data<<"	";
		myque.pop();
		if(temp->lchild)
			myque.push(temp->lchild);
		if(temp->rchild)
			myque.push(temp->rchild);
} 	}
int main()
{
	treenode *head=init();
	print(head);
	return 0;
}
