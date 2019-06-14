#include<iostream>
#include<math.h>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<iterator>
#include<string>
#include<map>
using  namespace std;

class Student
{
private:
	string _name;
	size_t _id;
public:
	explicit
	Student(size_t id=0,const string & name=string() )//为什么要是要缺省构造函数额？？？？？？？？？
	:_name(name),_id(id)
	{}

	size_t getid()const
	{
		return _id;
	}
	string getname()const
	{
		return _name;
	}
	//void setid(const)
};
class Controller
{
	friend class View;
private:
	map<size_t,Student>_stu;
public:
    int a;
    void fun() { cout << "123" <<endl; }
	Controller(){}
	~Controller(){}
	void attach(const Student & student)
	{
		_stu.insert(make_pair(student.getid(),student));//s.insert(make_pair(8,9));s.insert(pair<int ,int>(8,9));
	}
	void detach(size_t id)//关键字
	{
		_stu.erase(id);
	}
};
class View
{
public:
	View(Controller controller):_controller(controller){}
	virtual
	~View(){}//有为虚函数的成员函数~,析构函数都要设为虚函数！
	
	/*void reset(Student * student)
	{
		_student(stuednt);//?????????????????????????????
	}
	*/
	virtual
	void show()//控制器的map容器应该怎么传到view这里啊？？？？？？？？？？？？？？？？？//
				//为什么要用reset？？？？？？？？？？？？
	{	
		for(auto it=_controller._stu.begin();it!=_controller._stu.end();++it)
		{
			
			cout<<"id:"<<it->first << endl
			<<"name:"<< (it->second).getname()<<endl;
		}
	}
private:
    Controller _controller;
};


int main()
{	
	Controller controller;
	controller.attach(Student(1,"大熊"));
	controller.attach(Student(2,"二熊"));  
	controller.attach(Student(3,"胖虎"));  
	controller.attach(Student(4,"静香"));

	//unique_ptr<View>view1(new View());

	View view1(controller);
    view1.show();
	return 0;

	//???这个智能指针一直不知道咋用呀？？？？？？？？？？？？？？？？
}
