#include<iostream>
using namespace std;
#include<string>

//拷贝构造函数的调用时机--分三种情况
class Test
{
public:
	Test()
	{
		cout << "Test的默认构造函数调用" << endl;
	}
	Test(int value)
	{
		cout << "Test拷贝构造函数调用" << endl;
		m_value = value;
	}
	Test(const Test& t)
	{
		cout << "Test拷贝构造函数调用" << endl;
		m_value = t.m_value;
	}
	~Test()
	{
		cout << "Test的析构函数调用" << endl;
	}
	int m_value;
};

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Test t1(20);
	Test t2(t1);
	cout << t2.m_value << endl;
}
//2.值传递的方式给函数参数传值
void set(Test t)
{
	t.m_value = 22;//拷贝构造函数调用
}
void test02()
{
	Test t;
	set(t);
}

//3.以值方式返回局部对象
Test set1()
{
	Test t;
	return t;
}
void test03()
{
	Test t = set1();
}


int main()
{
	test01();
	test02();
	test03();



	system("pause");
	return 0;
}