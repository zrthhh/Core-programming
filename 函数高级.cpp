#include<iostream>
using namespace std;

//函数默认参数
//函数的形参列表中的参数是可以有默认值的
//语法：返回值类型 函数名 (参数 = 默认值){}
int func(int a, int b = 10, int c = 10)
{
	return a + b + c;
}
//如果自己传入数据，就用自己的数据，如果没有，就用默认值
//注意事项：如果某个位置已经有了默认参数，那么这个位置以后都必须要有默认值
//如果函数声明有默认参数，函数实现就不能有默认参数
//声明和实现只能有一个有默认参数


//函数占位参数
//形参列表中可以有占位参数，用来做占位，调用函数时，必须填补该位置
//语法：返回值类型 函数名 (数据类型){}
void func1(int a, int)
{
	cout << "占位参数" << endl;
}


//函数重载
/*函数名可以相同，提高复用性
* 函数重载满足条件：同一个作用域下；函数名称相同；
* 函数参数类型不同或者个数不同或者顺序不同
* 注意：函数的返回值不可以作为函数重载的条件
*/
void func2()
{
	cout << "func2 的调用" << endl;
}


void func2(int a)
{
	cout << "func2(int a) 的调用!" << endl;
}

void func2(int a, double b)
{
	cout << "func2(int a,double b) 的调用" << endl;
}


void func2(double a, int b)
{
	cout << "func2(double a,d b) 的调用" << endl;
}
/*函数重载的注意事项
* 1.引用作为重载的条件
*/
void func3(int& a)
{
	cout << "func3(int &a)调用" << endl;
}

void func3(const int& a)
{
	cout << "func3(const int &a) 调用" << endl;
}



int main()
{
	cout << func(10) << endl;
	cout << func(10, 30) << endl;
	 
	func1(1, 2);

	func2();
	func2(1);






	system("pause");
	return 0;
}