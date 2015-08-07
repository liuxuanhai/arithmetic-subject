#include<iostream>
using namespace std;
class  String
{
public:
	String(const char *str=NULL);//���캯��
	~ String();
	String(const String& src);//�������캯��
	String& operator=(const String &src);//���ظ�ֵ����
private:
	char *m_data;
};
String& String::operator=(const String &src)
{
	if(this==&src)
		return *this;
	delete[] m_data;//ɾ������
	m_data=new char[strlen(src.m_data)+1];
	strcpy(m_data,src.m_data);
	return *this;
}
String::String(const String& src)
{
	m_data=new char[strlen(src.m_data)+1];
	strcpy(m_data,src.m_data);
}
String:: String(const char *str)
{
	if(str==NULL)
	{
		m_data=new char[1];
		m_data[0]='\0';
	}
	else

	{
		m_data=new char[strlen(str)+1];
		//m_data=new char[strlen(str)];//���͵��ڴ��������
		strcpy(m_data,str);
	}
}

String::~ String()
{
	cout<<"����������"<<m_data<<endl;
	delete[] m_data;
}
int main()
{
	String a("1000");
	String dest=a;//���ÿ������캯��
	String f=dest=a;//�ȵ��ø�ֵ�������ڵ��ÿ������캯��
	return 0;
}