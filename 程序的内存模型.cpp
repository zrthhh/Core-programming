#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量,全局常量
const int c_g_a = 10;
const int c_g_b = 10;

//栈区
int* fun()
{
	int a = 10;//局部变量，存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量的地址
}
//非法操作，不要返回局部变量地址


//在堆区开辟数据
int* fun1()
{
	//利用new关键字 可以讲数据开辟到堆区
	int* p = new int(10);
	return p;
}

//new的基本语法
int* fun2()
{
	//在堆区创建整形数据
	//new 返回的是该数据类型的指针
	int* p = new int(10);
	return p;
}
void test01()
{
	int* p = fun2();
	cout << *p << endl;
	//程序员开辟，程序员释放
	delete p;
}

//在堆区利用new开辟数组
void test02()
{
	//创建10整形数据的数组，在堆区
	int* arr = new int[10];;//10代表数组有10个元素
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int j = 0; j < 10; j++) {
		cout << arr[j] << endl;
	}

	//释放数组的时候，要加[]才可以
	delete[] arr;
}


int main()
{
	//内存分区模型
	/*
	* 1.代码区：存放函数体的二进制代码，由操作系统进行管理
	* 2.全局区：存放全局变量和静态变量以及常量
	* 3.栈区：由编译器自动分配释放，存放函数的参数值，局部变量等
	* 4.堆区：由程序员分配和释放，若程序员不释放，程序结束后操作系统回收
	*/
	//不同区域存放的数据，赋予不同的生命周期

	//程序运行前
	/*在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域
	* 代码区：存放cpu执行的机器指令；
	* 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可；
	* 代码区是只读的，使其只读的原因是防止程序意外的修改了它的指令
	* 
	* 全局区：全局变量和静态变量存放在此
	* 全局区包含了常量区，字符串常量和其他常量也存放于此
	* 该区域数据在程序结束后由操作系统释放
	*/
	int a = 10; //局部变量
	int b = 10;
	cout << "局部变量a的地址为：" << (int)&a << endl;
	cout << "局部变量b的地址为：" << (int)&b << endl;

	cout << "全局变量g_a的地址为：" << (int)&g_a << endl;
	cout << "全局变量g_b的地址为：" << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	cout << "静态变量s_a的地址为：" << (int)&s_a << endl;
	
	//常量
	cout << "字符串常量的地址为：" << (int)&"hello world" << endl;


	cout << "全局常量c_g_a的地址为：" << (int)&c_g_a << endl;
	cout << "全局常量c_g_b的地址为：" << (int)&c_g_b << endl;

	//const修饰局部变量
	const int c_l_a = 10;
	const int c_l_b = 10;
	cout << "局部常量c_l_a的地址为：" << (int)&c_l_a << endl;
	cout << "局部常量c_l_b的地址为：" << (int)&c_l_b << endl;


	/*程序运行后
	* 栈区：由编译器自动分配释放，存放函数的参数值，局部变量等;
	* 注意事项：不返回局部变量的地址，栈区开辟的数据由编译器自动释放
	*/
	int* p = fun();
	cout << *p << endl;//第一次打印正确，是应为编译器做了保留
	cout << *p << endl;//第二次就不再保留

	//堆区
	//在c++中主要利用new在堆区开辟内存
	int* q = fun1();
	cout << *q << endl;

	//new操作符
	/*
	* c++中利用new操作符在堆区开辟数据
	* 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符delete
	* 语法：new 数据类型
	* 利用new创建的数据，会返回该数据对应的类型的指针
	*/
	test01();
	test02();

	system("pause");
	return 0;
}