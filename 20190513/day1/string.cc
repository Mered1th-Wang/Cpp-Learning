 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-13 17:30:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void test0()
{
	char str[] = "hello,world";//字符数组  栈上
	printf("str = %s\n", str);

	const char * pstr = "hello,world";//字符串常量 文字常量区
	printf("pstr = %s\n", pstr);
}

void test1()
{
	int number(1);
	cout << "number = " << number << endl;

	string s1 = "hello";//C风格字符串转换成C++风格字符串
	string s2("world");
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	//把C++风格字符串转换成C风格字符串
	const char * pstr = s1.c_str();
	const char * pstr2 = s1.data();
	printf("pstr = %s\n", pstr);
	printf("pstr2 = %s\n", pstr2);


	//求取字符串长度
	cout << "s2.size() = " << s2.size() << endl;
	cout << "s2.length() = " << s2.length() << endl;
	
	//字符串的遍历
	for(size_t idx = 0; idx != s2.size(); ++idx){
		cout << s2[idx] << endl;//下标访问运算符
	}

	//字符串拼接
	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;
	s3.append(",shenzhen");
	cout << "s3 = " << s3 << endl;
	s3.append(3, 'z');
	cout << "s3 = " << s3 << endl;
	s3.append(s1);
	cout << "s3 = " << s3 << endl;

	//截取子串
	size_t pos = s3.find('s');
	string s4 = s3.substr(pos, 8);
	cout << "s4 = " << s4 << endl;

}
 
int main(void)
{
	//test0();
	test1();
	return 0;
}
