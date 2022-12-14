#include<iostream>
using namespace std;
#include<string>

//普通实现页面

////Java页面
//class Java
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "java info" << endl;
//	}
//};
//
////python 页面
//class Python
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "python info" << endl;
//	}
//};
//
////c++页面
//class Cpp
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "cpp info" << endl;
//	}
//};

//继承实现
//实现公共页面
class BasePage
{
public:
	void header()
	{
		cout << "head info" << endl;
	}
	void footer()
	{
		cout << "foot info" << endl;
	}
	void left()
	{
		cout << "left info" << endl;
	}
};

//java
class Java :public BasePage
{
public:
	void content()
	{
		cout << "java info" << endl;
	}
};

//python
class Python :public BasePage
{
public:
	void content()
	{
		cout << "python info" << endl;
	}
};

//cpp
class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "cpp info" << endl;
	}
};
//继承--减少重复代码
//语法：class 子类(派生类)：继承方式 父类(基类)


//继承方式--公共继承，保护继承，私有继承
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//公共继承
class son1 :public Base
{
public:
	void func()
	{
		m_A = 10;
		m_B = 10;  //父类中的保护权限成员，类内可以访问，类外不可以访问
		//m_C = 10; 私有权限无法访问
	}
};

//保护继承
class son2 :protected Base
{
public:
	void func()
	{
		m_A = 100;  //父类中的公共成员到之类变为保护权限
		m_B = 100;
		//m_C = 100; 父类中的私有成员无法访问
	}
};

//私有继承
class son3 :private Base
{
public:
	void func()
	{
		m_A = 100;  //父类中公共成员，到子类变为私有成员
		m_B = 100;  //父类中保护成员，到子类变为私有成员
		//m_C = 100;  //父类中私有成员无法访问
	}
};

//继承中的构造和析构顺序如下
//先构造父类，再构造子类，析构的顺序与构造的顺序相反


//继承中同名成员处理
//访问子类同名成员 直接访问即可
//访问父类同名成员 需要加作用域

//如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
//如果想访问到父类中被隐藏的同名成员函数，需要加作用域



//继承同名静态成员处理方式
/*静态成员和非静态成员出现同名，处理方式一致
* 访问子类同名成员，直接访问即可
* 访问父类同名成员，需要加作用域
*/
class base
{
public:
	static void func()
	{
		cout << "base - static void func()" << endl;
	}
	static int m_A;
};
int base::m_A = 100;

class sons :public base
{
public:
	static void func()
	{
		cout << "sons - static void func()" << endl;
	}
	static int m_A;
};
int sons::m_A = 200;

//同名静态成员属性
void test01()
{
	sons s;
	cout << "sons 下 m_A" << s.m_A << endl;
	cout << "base 下 m_A" << s.base::m_A << endl;
}

//同名静态函数访问
void test02()
{
	sons s;
	s.func();
	s.base::func();
}
//子类出现同名静态成员或函数，会将父类的同名成员隐藏
//通过对象访问或者通过类名访问



//多继承语法
/*c++允许一类继承多个类
* 语法：class 子类:继承方式 父类1,继承方式 父类2...
* 多继承可能会引发父类中有同名成员出现，需要加作用域区分
* 实际中不建议使用多继承
*/

/*菱形继承
* 两个派生类继承同一个基类
* 又有某个类同时继承两个派生类
*/
//动物类
class Animal
{
public:
	int Age;
};
//羊类
class sheep :public Animal
{

};
//骆驼类
class camal :public Animal
{

};
//羊驼类
class sc :public Animal
{

};
//当菱形继承，两个父类拥有相同数据时，需要通过作用域进行区分
//容易导致资源浪费
//通过使用虚继承解决问题，加上virtual关键字


int main()
{
	

	









	system("pause");
	return 0;
}