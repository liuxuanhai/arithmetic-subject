#include<iostream>
using namespace std;
int shunxu(int* numbers,int start,int end);
int Min(int *numbers,int length) throw (exception)
{
	if(numbers==NULL||length<=0)
		throw exception("��������");
	int start=0,end=length-1;//startָ��ǰ�����������ĵ��±꣬endָ���������������±�
	int mid=start;//��mid��ʼ��Ϊstart�����������û����ת������whileѭ����ֱ��return numbers[0]
	while(true)
	{
		if(start-end==-1)//start��end���1ʱ����֤��startΪ��������endΪ��С����
		{
			mid=end;
			break;
		}
		mid=(start+end)/2;
		//���numbers[mid],numbers[start],numbers[end]��ȵĻ�����Ҫ˳�����
		if(numbers[mid]==numbers[start]&&numbers[mid]==numbers[end])
		{
			return shunxu(numbers,start,end);
		}
		if(numbers[mid]>=numbers[start])//��ʱ��ʾ��С����mid����
			start=mid;
		else if(numbers[mid]<=numbers[end])//��ʱ��ʾ��С����midǰ��
			end=mid;
	}
	return numbers[mid];
}
//˳�������������Сֵ
int shunxu(int* numbers,int start,int end)
{
	int min=numbers[start];
	for(int i=start+1;i<=end;i++)
	{
		if(min>numbers[i])
			min=numbers[i];
	}
	return min;
}
int main()
{
	int a[20]={1,1,1,0,1};
	cout<<Min(a,5);
	return 0;
}