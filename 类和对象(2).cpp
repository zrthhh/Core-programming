#include<iostream>
using namespace std;
#include<string>


class Person
{
public:
	/*构造函数语法：类名() {}
    * 没有返回值也不写void
    * 函数名称与类名相同
    * 构造函数可以有参数，因此可以发生重载
    * 程序再调用对象时会自动调用构造，无须手动调用，且只会调用一次
    */
	Person() {
		cout << "Person 构造函数的调用" << endl;
	}

	/*析构函数语法：~类名(){}
    * 没有返回值也不写void
    * 函数名称与类名相同，在名称前加上符号
    * 析构函数不可以有参数，因此不可以发生重载
    * 程序在对象销毁前会自动调用析构，无需手动调用，且只会调用一次
    */
	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
};

void test01()
{
	Person P;//在栈上的数据，test01执行完毕后，释放这个对象
}


//构造函数的分类及调用
/*两种分类方式：
* 按参数分为：有参构造和无参构造
* 按类型分为：普通构造和拷贝构造
*/
class Student
{
public:
	Student()
	{
		cout << "Student的构造函数调用" << endl;
	}
	Student(int a)
	{
		id = a;
		cout << "Student的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	Student(const Student &s)
	{
		id = s.id;
	}

	~Student()
	{
		cout << "Student的析构函数调用" << endl;
	}

	int id;
};

//调用
void test02()
{
	//括号法
	Student s1;  //默认构造函数调用
	Student s2(10);  //有参构造函数调用
	Student s3(s2);  //拷贝构造函数调用

	//显示法
	Student a1;
	Student a2 = Student(11); //有参构造
	Student a3 = Student(a2); //拷贝构造

	//隐式转换法
	Student b1 = 10;  //等价于 Student b1 = Student(10);有参构造
	Student b2 = b1;  //拷贝构造
}

int main()
{
	//对象的初始化和清理
	/*c++利用构造函数和析构函数来解决该问题
	*两个函数被编译器自动调用，完成对象初始化和清理工作
	* 如果不提供构造和析构，编译器会提供构造函数和析构函数的空实现
	*/

	//构造函数：作用在于创建对象时为对象的成员属性赋值，
	//构造函数由编译器自动调用，无需手动调用
	test01();//既有构造也有析构
	Person P;//只有构造，没有析构，说明未有发生释放
	//析构函数：作用于对象销毁前系统自动调用，执行一些清理工作


	system("pause");
	return 0;
}