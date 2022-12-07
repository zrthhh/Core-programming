#include<iostream>
using namespace std;


//引用作函数参数
//函数传参时，可以利用引用的技术让形参修饰实参
//可以简化指针修改实参

//值传递
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//地址传递
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//引用传递
void swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//引用传递，形参也会修饰实参


//引用做函数返回值
/*引用是可以作为函数返回值存在的
* 注意：不要返回局部变量引用
* 用法：函数调用为左值
*/
int& test1()
{
	static int a = 10;
	return a;
}

//引用的本质在c++内部的实现是一个指针常量
//发现是引用，转换为int* const ref = &a;
void func(int& ref) {
	ref = 100;//ref是引用，转换为*ref = 100
}

int main()
{
	//引用
	//作用：给变量起别名
	//语法：数据类型 &别名 = 原名
	int m = 10;
	int& n = m;
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;
	
	n = 100;
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;

	//引用的注意事项
	//引用必须初始化
	//引用在初始化后，不可以改变

	//通过引用参数产生的效果同按地址传递的效果时一样的，引用的语法更加简单清楚

	//引用可以作左值
	int& ref = test1();
	cout << "ref = 2" << ref << endl;
	test1() = 1000;
	cout << "ref = 2" << ref << endl;

	//引用的本质
	//引用的本质在c++内部的实现是一个指针常量
	int a = 10;
	//自动转换为int* const ref = &a;指针常量是指针指向不可改，也说明为什么引用不可更改
	int& ref1 = a;
	ref1 = 20;//内部发现是ref是引用，自动帮我们转换为：*ref=20；
	cout << "a:" << a << endl;
	cout << "ref1:" << ref1 << endl;

	//常量引用
	//作用：常量引用主要用来修饰形参，防止误操作
	//在函数形参列表中，可以加const修饰形参，防止形参改编实参

	const int& ref2 = 10;//加上const之后，编译器将代码修改
	//int temp = 10;const int &ref = temp;
	




	system("pause");
	return 0;
}