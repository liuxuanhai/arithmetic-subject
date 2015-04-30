#include<iostream>
#include<cstring>
using namespace std;
class Mystring
{
public:
	Mystring &operator=(const Mystring &str);
	Mystring(char *pdata=NULL)//带默认值的构造函数
	{
		data=pdata;
	}
	Mystring(const Mystring &str)//拷贝构造函数
	{
		data=str.data;
	}
	~Mystring() //析构函数
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
	if(&str!=this)//如果&str==this则不必赋值
	{
		delete data;//先释放原有空间
		data=NULL;
		data=new char[strlen(str.data)+1];//为指针初始化空间
		strcpy(data,str.data);//赋值

	}
	return *this;
}
int main()
{
	Mystring str1("hello"),str2;//声明两个类对象
	str1.show();
	str2=str1;//调用自定义赋值方法
	str2.show();
	str1=str1;//自己给自己赋值
	str1.show();
	return 0;
}