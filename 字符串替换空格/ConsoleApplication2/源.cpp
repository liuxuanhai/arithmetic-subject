#include<iostream>
#include<string>
using namespace std;
void replace(char *array,int length)
{
	if(array!=NULL&&length>0)//�жϲ����Ƿ�Ϸ�
	{
		int blankcount=0,index=0;//blankcount��¼�ո�����index��¼���������һΪ'\0'���±�
		while(array[index]!='\0')//ͳ�ƿո���
		{
			if(array[index]==' ')
				blankcount++;
			index++;
		}
		//�û��ո�֮��ʵ���������һλ���±�
		int lastindex=index+2*blankcount;
		//�ж����������Ƿ�ϸ�
		if(lastindex>length)
		{
			cout<<"���鳤�Ȳ�����"<<endl;
			return;
		}
		//ѭ�����ո��滻Ϊ��%20��
		while(index<lastindex&&index>=0)
		{
			if(array[index]==' ')
			{
				array[lastindex--]='0';
				array[lastindex--]='2';
				array[lastindex--]='%';
				index--;
			}
			else
			{
				array[lastindex--]=array[index--];
			}
		}
	}
}
int main()
{
	char a[100]={' ','a','b',' ',' ','c','d',' ','e','f',' '};//��������
	cout<<a<<endl;
	replace(a,100);
	cout<<a<<endl;
    char *b="asdasd";
	cout<<b<<endl;
	replace(b,20);
	cout<<b<<endl;
	char c[20]={' ',' '};
	cout<<c<<endl;
	replace(c,20);
	cout<<c<<endl;
	char name[20];



	cin.getline(name,20,'\n');//�����ַ��������ո�Ļ���getline
	cout<<name<<endl;
	return 0;
}