#include<iostream>
using namespace std;
#include<string>

//圆类
const double PI = 3.14;

class circle
{
	//访问权限
public:
	//属性
	int m_r;
	//行为
	double calculate()
	{
		return 2 * PI * m_r;
	}
};

//学生类
class student
{
public:
	string s_name;
	string s_id;
	void setinfo(string name, string id)
	{
		s_name = name;
		s_id = id;
	}

	void show()
	{
		cout << "name:" << s_name << endl;
		cout << "s_id" << s_id << endl;
	}
};

//访问权限控制
//公共权限 public    成员 类内可以访问，类外也可以访问
//保护权限 protexted 成员 类内可以访问，类外不可以访问
//私有权限 private   成员 类内可以访问，类外不可以访问
class Person
{
	//public
public:
	string m_name;
	//protected
protected:
	string m_car;
	//private
private:
	int m_password;

public://类内访问
	void func()
	{
		m_name = "aa";
		m_car = "bb";
		m_password = 123;
	}
};


//成员属性设置为私有
class person1
{
public:
	void setname(string name)
	{
		m_name = name;
	}
	string getname()
	{
		return m_name;
	}
	void setage(int age)
	{
		m_age = age;
	}
	int getage()
	{
		return m_age;
	}
private:
	string m_name;
	int m_age;
	string m_lover;
};

//立方体设计类
class cube
{
public:
	void set(int l, int w, int h)
	{
		L = l;
		W = w;
		H = h;
	}
	int calculateS()
	{
		return 2 * (L * W + W * H + L * H);
	}
	int calculateV()
	{
		return L * W * H;
	}
private:
	int L;  //长
	int W;  //宽
	int H;  //高
};
//利用全局函数判断立方体是否相等
bool isequal(cube &a, cube &b)
{
	return (a.calculateS() == b.calculateS()) && (a.calculateV() == b.calculateV());
}


int main()
{
	//C++面向对象三大特性：封装、继承、多态

	/*1.封装
	* (1)将属性和行为作为一个整体，表现生活中的事物
	* (2)将属性和行为加以权限控制
	*/

	//(1)在设计类的时候，属性和行为写在一起，表现事物
	//语法：class 类名{访问权限：属性/行为};
	//案例1--设计圆类，计算圆的周长
	circle c1;
	c1.m_r = 1.0;
	cout << "圆c1的周长为：" << c1.calculate() << endl;

	//案例2-设计学生类，给姓名和学号赋值，并显示
	student s1;
	s1.setinfo("张三", "202211");
	s1.show();
	//类中的属性和行为，统称为成员
	//属性也称成员属性或成员变量
	//行为也称成员函数或成员方法


	//(2)类在设计时，可以把属性和行为分别加以不同的权限
	Person p1;
	p1.m_name = "cc";
	//p1.m_car = "bens";无法访问


	/*struct和class的区别
	* 唯一的区别就是在于默认的访问权限不同
	* struct默认权限为公共
	* class默认权限为私有
	*/

	//成员属性设置为私有
	//将所有成员属性设置为私有，可以自己控制读写权限
	//对于写权限，可以检测数据的有效性
	person1 p;
	p.setname("李四");
	cout << "姓名为：" << p.getname() << endl;
	p.setage(12);
	cout << "年龄为：" << p.getage() << endl;


	//练习案例--设计立方体类-计算面积和体积
	cube c;
	c.set(1, 2, 3);
	cout << "c的面积为：" << c.calculateS() << endl;
	cout << "c的体积为：" << c.calculateV() << endl;

	cube cu;
	cu.set(2, 3, 4);
	bool value = isequal(c, cu);
	if (value == true) {
		cout << "is equal" << endl;
	}
	else {
		cout << "is not equal" << endl;
	}

	system("pause");
	return 0;
}