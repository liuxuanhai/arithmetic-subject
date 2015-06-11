#include<iostream>
#include <stack> 
#include <assert.h>
using namespace std;
template <typename T>
class mystack
{
public:
	//mystack();
	void mypush(const T& value);
	void mypop();
	const T& mymin();
private:
	stack<T> data,min;//dataջ���������洢ÿһ����ջ�����ݣ�minջ��ջʱ�����洢��ǰ��С������
};
//push������ʵ�֣�dataջ���������ݣ�minջ���뵱ǰջ����С������
template <typename T>
void mystack<T>::mypush(const T& value)
{
	data.push(value);
	//���minջ��û�����ݻ���valueС�ڵ�ǰջ����С���ݣ�top������value����minջ
	if(min.size()==0 || value<min.top())
		min.push(value);
	//����minջ�н���Ļ���ԭ��ջ����С���ݣ�top��
	else
		min.push(min.top());
}
//pop������ʵ�֣�data��minջ������������
template <typename T>
void mystack<T>::mypop()
{
	if(data.size()>0 && min.size()>0)
	{
		data.pop();
		min.pop();
	}
	else
	{
		cout<<"ջΪ�ղ��ܵ������ݣ�"<<endl;
	}
}
//min������ʵ�֣���õ�ǰջ�е���С����
template <typename T>
const T& mystack<T>::mymin()
{
	//�ж����������ֵΪ�����ӡ������Ϣ����ֹ����
	assert(data.size()>0 && min.size()>0);
	return min.top();
}
int main()
{
	mystack<int> s;
	s.mypush(3);
	s.mypush(4);
	s.mypush(2);
	s.mypush(1);
	s.mypop();
	s.mypop();
	cout<<"��ʱջ����С��Ԫ��Ϊ:"<<s.mymin()<<endl;
	return 0;
}