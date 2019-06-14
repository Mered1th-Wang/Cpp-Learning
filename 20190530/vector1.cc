#include<iostream>
#include<cstring>
#include<vector>
#include<stdio.h>
#include<iterator>

using namespace std;

//void test1(){

//定义语句
//int array[5]={1,3,4,6,7};
//vector<int> shuzu=array[5];
/*	vector<int> v;//声明容器
	v.push_back(555);//往里加入数据
	v.push_back(666);
	v.push_back(777);
	v.push_back(888);
	v.push_back(999);
	for(vector<int>::iterator it=v.begin();it!=v.end();++it)//迭代器指向vector，遍历vector
	{
	cout<<*it<<endl;
	}
	}*/
class Person{
	public:
		string _name;
		int _age;
	public:
		Person(const string name,const int age)
			:_name(name)
			 ,_age(age)
	{
		cout<<"string()"<<endl;
	}
		//const operator(const Person &c){}
		~Person(){
		}
		//friend std::ostream & operator<<(std::ostream &os, const Person c);
        friend ostream & operator<<(ostream &os, Person& c) ;

};
ostream & operator<<(ostream &os, Person& c) 
{	os<<c._name<< " " << c._age<<endl;
	return os;
}
void test2(){
	vector<Person> p;
	Person p1("宋蕊小宝宝",5);
	Person p2("赵小云，呃····",10);
	Person p3("余shadiao",2);
	Person p4("李文琪话太多了把",4);
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	for(vector<Person>::iterator it1=p.begin();it1!=p.end();++it1)
	{
		cout<<*it1<<endl;
	}


}

int main(){
	//test1();
	test2();
	return 0;
}
