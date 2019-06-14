 ///
 /// @file    Singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-15 14:32:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例模式: 
//	要求: 通过某个类只能创建出一个对象
//	1. 该对象不能存放在栈上，全局静态区
//	2. 该对象只能放在堆上


//应用场景:
//	1. 替换原来C中所使用的全局变量  
//		命名空间 + 类名
//	2. 读取配置文件
//	3. 词典文件/网页库
//	4. 日志系统中的日志记录器

class Singleton
{
public:
	static Singleton * getInstance()
	{
		//static Singleton s;
		if(_pInstance == nullptr) {
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance) {
			delete _pInstance;
		}
	}

	void print() const
	{	cout << "Singleton::print()" << endl;	}

private:
	Singleton(){	cout << "Singleton()" << endl;	}
	~Singleton() {	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
	//....
	//....
};

Singleton * Singleton::_pInstance = nullptr;
 
//Singleton s3;
//Singleton s4;

//static Singleton s5;

int main(void)
{
	//Singleton s1;//error 希望该语句在编译时通不过
	//Singleton s2;
	//Singleton * p1 = new Singleton();//在类之外调用构造函数
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl
		 << "p2 = " << p2 << endl;

	Singleton::getInstance()->print();

	//delete p1;//error在形式上有问题

	Singleton::destroy();
	return 0;
}
