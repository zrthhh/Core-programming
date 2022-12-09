#include<iostream>
using namespace std;


//构造函数调用规则
/*默认情况下，编译器至少给一个类添加3个函数
* 1.默认构造函数(无参，函数体为空)
* 2.默认析构函数(无参，函数体为空)
* 3.默认拷贝构造函数，对属性值进行拷贝
*/
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_age = age;
	}
	Person(const Person& p) {
		m_age = p.m_age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int m_age;
};
/*构造函数调用规则如下
* 如果用户定义有参构造，c++不在提供默认无参构造，但是会提供默认拷贝构造
* 如果用户定义拷贝构造函数，c++不会再提供其它的构造函数
*/
void test01()
{
	Person p;
	p.m_age = 18;
}


//深拷贝与浅拷贝
//浅拷贝--简单的赋值拷贝操作
//深拷贝--在堆区重新申请空间，进行拷贝操作


//初始化列表
//c++提供了初始化列表语法，用来初始化属性
//语法：构造函数():属性1(值1),属性2(值2)...{}
class T
{
public:
	T(int a, int b, int c) :m1(a), m2(b), m3(c)
	{

	}

	int m1;
	int m2;
	int m3;
};

//类对象作为类成员
//类中的成员可以是另一个类的对象，称该成员为对象成员  
class A{};
class B
{
	A a;
};
//当其它类的对象最为本类成员，构造是先构造其它类对象，再构造自身类的对象
//析构时，现时释放本类对象，再释放其它类的对象


//静态成员
/*静态成员变量
* 所有对象共享同一份数据
* 在编译阶段分配内存
* 类内声明，类外初始化
*/
/*静态成员函数
* 所有对象共享同一个函数
* 静态成员函数只能访问静态成员变量
*/
class Name
{
public:
	static void func()
	{
		cout << "static void func的调用" << endl;
	}
	static int m_A;
};

int Name::m_A = 10;

void test()
{
	Name n;
	//10
	cout << n.m_A << endl;
	Name n1;
	n1.m_A = 20;
	//20
	cout << n.m_A << endl;
}
//静态成员变量，不属于某个对象上，所有对象都共享同一份数据
//因此静态成员变量有两种访问方式,静态成员函数同样
void test01()
{
	//1.通过对象进行访问
	Name n;
	cout << n.m_A << endl;
	n.func();
	//2.通过类名进行访问
	cout << Name::m_A << endl;
	Name::func();
}


//C++对象模型和this指针
//C++中，类内的成员变量和成员函数分开存储，只有非静态成员变量才属于类的对象

/*每一个非静态成员函数只会诞生一份函数实例，多个同类型的对象公用一块代码
* C++通过提供特殊的对象指针-this指针来解决上述的问题
* this指针指向被调用的成员函数所属的对象
* this指针是隐含每一个非静态成员函数内的一种指针
* this指针不需要定义，直接使用即可
* 当形参和成员变量同名是，可以用this指针来区分
* 在类的非静态成员函数中返回对象本身可以使用return *this
*/
class temp
{
public:
	temp(int num)
	{
		//this指向被调用的成员函数所属的对象
		this->num = num;
	}
	temp & add(temp& p)
	{
		this->num += p.num;
		//this指向调用的对象，*this指向这个对象的本体
		return *this;
	}
	int num;
};
//解决名称冲突
void temp1()
{
	temp p1(18);
	cout << "p1 = " << p1.num << endl;
}
//返回对象本身用*this
void temp2()
{
	temp a(10);
	temp b(10);
	b.add(a).add(a).add(a);//链式编程
	cout << "b= " << endl;
}



//空指针访问成员函数-空指针也是可以调用成员函数的，但是也要
//注意有没有用到this指针，如果用到this指针，需要加以判断保证代码
//的健壮性


//const修饰成员函数
/*常函数：
* 成员函数后加const后我们称这个函数为常函数
* 常函数不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依然可以修改
* 常对象：
* 声明对象前加const称该对象为常对象
* 常对象只能强调常函数
*/
class con
{
public:
	//this指针的本质是指针常量，指针的指向是不可以修改的
	void temp() const
	{
		this->m_num = 0;
	}
	mutable int m_num;
	int m;
};

void cons()
{
	const con a;
	a.m_num = 1;
	//a.m = 2;不可修改
}
//常对象只能调用常函数

int main()
{
	T t(1, 2, 3);

	system("pause");
	return 0;
}