#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
public:
	Mystring &operator=(const Mystring &str);
	Mystring(char *pdata=NULL)//��Ĭ��ֵ�Ĺ��캯��
	{
		data=pdata;
	}
	Mystring(const Mystring &str)//�������캯��
	{
		data=str.data;
	}
	~Mystring() //��������
	{
	}
	void show()
	{
		cout<<data<<endl;
	}
private:
	char* data;
};
Mystring &Mystring::operator=(const Mystring &str)
{
	if(&str!=this)//���&str==this�򲻱ظ�ֵ
	{
		delete data;//���ͷ�ԭ�пռ�
		data=NULL;
		data=new char[strlen(str.data)+1];//Ϊָ���ʼ���ռ�
		strcpy(data,str.data);//��ֵ

	}
	return *this;
}
int main()
{
	Mystring str1("hello"),str2;//�������������
	str1.show();
	str2=str1;//�����Զ��帳ֵ����
	str2.show();
	str1=str1;//�Լ����Լ���ֵ
	str1.show();
	return 0;
}