#include<vector>
#include<iostream>
#include<fstream>
using namespace std;
bool reserve_file()
{
	bool result=false;
	ifstream in("in.txt",ios::in);
	ofstream out("out.txt",ios::out||ios::trunc);
	if(!in)
	{
		cout<<"不能打开文件！"<<endl;
		return false;
	}
	if(!out)
	{
		cout<<"不能写入文件！"<<endl;
		return 0;
	}
	vector<char> vec(20,0);
	char temp;
	in.get(temp);
	while(!in.eof())
	{
		vec.push_back(temp);
		in.get(temp);
	}
	vector<char>::reverse_iterator it=vec.rbegin();
	for(;it!=vec.rend();it++)
	{
		out.put(*it);
	}
	return 1;
}
int main()
{
	cout<<reserve_file()<<endl;
	return 0;
}