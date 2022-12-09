#include<iostream>
using namespace std;
#include<string>

//运算符重载
//对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
class Add
{
public:
	Add(int a,int b) {
		this->a = a;
		this->b = b;
	}
	//通过成员函数重载
	Add operator+ (Add& p)
	{
		Add temp(0,0);
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
	}
	int a;
	int b;
};

//通过全局函数重载
Add operator- (Add& p1, Add& p2)
{
	Add temp(0,0);
	temp.a = p1.a - p2.a;
	temp.b = p1.b - p2.b;
	return temp;
}
//运算符重载，也可以发生函数重载
//内置的数据类型的表达式的运算符是不可能修改的
//不要滥用运算重载符


//左移运算符重载
class Left
{
public:
	//不会利用成员函数来重载左移运算符，因为无法实现cout在左侧

	int m_A;
	int m_B;
};

//只能利用全局函数来重载左移运算符
//ostream & operator<<(ostream& cout, Left& p)
//{
//	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
//	return cout;
//}

//void test01()
//{
//	Left p;
//	p.m_A = 10;
//	p.m_B = 10;
//	cout << p << endl;
//}




//递增运算符重载
//通过重载递增运算符，实现自己的整形数据
class Integer
{
	friend ostream& operator<<(ostream& out, Integer myint);
public:
	Integer()
	{
		m_Num = 0;
	}

	//重载前置递增++a
	Integer& operator++()//返回引用是为了让对一个数据一直操作
	{
		m_Num++;
		return *this;//返回自身
	}
	//重载后置递增a++
	Integer operator++(int)//int占位参数，用于函数重载
	{
		Integer temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, Integer myint)
{
	cout << myint.m_Num;
	return cout;
}


void test02()
{
	Integer myint;
	cout << ++myint << endl;
	cout << myint << endl;
}

void test03()
{
	Integer myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
//前置递增返回引用，后置递增返回值



//赋值运算符重载
/*c++编译器至少给一个类添加4个函数
* 1.默认构造函数
* 2.默认析构函数
* 3.默认拷贝构造函数
* 4.赋值运算符operator=，对属性值进行拷贝
* 如果类中有属性指向堆区，做赋值操作是也会出现深浅拷贝问题
*/
int main()
{

	Add p1(3, 6);
	Add p2(5, 8);

	//加法重载
	Add p3 = p1 + p2;
	cout << "p3.a = " << p3.a << endl;
	cout << "p3.b = " << p3.b << endl;

	//减法重载
	Add p4 = p1 - p2;
	cout << "p4.a = " << p4.a << endl;
	cout << "p4.b = " << p4.b << endl;


	system("pause");
	return 0;
}