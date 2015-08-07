#include<iostream>
using namespace std;
class  String
{
public:
	String(const char *str=NULL);//构造函数
	~ String();
	String(const String& src);//拷贝构造函数
	String& operator=(const String &src);//重载赋值函数
private:
	char *m_data;
};
String& String::operator=(const String &src)
{
	if(this==&src)
		return *this;
	delete[] m_data;//删除数据
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
		//m_data=new char[strlen(str)];//典型的内存溢出错误
		strcpy(m_data,str);
	}
}

String::~ String()
{
	cout<<"析构函数："<<m_data<<endl;
	delete[] m_data;
}
int main()
{
	String a("1000");
	String dest=a;//调用拷贝构造函数
	String f=dest=a;//先调用赋值函数，在调用拷贝构造函数
	return 0;
}