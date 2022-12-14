#include<iostream>
using namespace std;
#include<string>

/*多态是面向多态三大特性之一
* 多态分为两类
* 静态多态：函数重载和运算符重载属于静态多态，复用函数名
* 动态多态：派生类和虚函数实现运行时多态
* 区别
* 静态多态的函数地址早绑定-编译阶段确定函数地址
* 动态多态的函数地址晚绑定-运行阶段确定函数地址
*/
//动物类
class Animal
{
public:
	//加入虚函数，就可以实现地址后绑定
	/*virtual void speak()
	{
		cout << "speak!" << endl;
	}*/
	void speak()
	{
		cout << "speak!" << endl;
	}
};
//狗类
class dog:public Animal
{
public:
	void speak()
	{
		cout << "dog speak" << endl;
	}
};
//猫类
class cat :public Animal
{
public:
	//重写：函数返回值类型 函数名 参数列表 完全一致称为重写
	void speak()
	{
		cout << "cat speak" << endl;
	}
};

//执行函数
//地址早绑定，编译阶段就确定了地址
//使用虚函数解决该问题
void dospeak(Animal &animal)
{
	animal.speak();
}
/*动态多态满足条件
* 1.有继承关系
* 2.子类重写父类中的虚函数
* 动态多态的使用
* 1.父类的指针或者引用 执行子类对象
*/
void test01()
{
	cat mimi;
	dospeak(mimi);
	dog wangwang;
	dospeak(wangwang);
}

void test02()
{
	//不加virtual，为1
	cout << "sizeof Animal = " << sizeof(Animal) << endl;
	//加virtual，为4
}


//多态案例--计算器类
//分别用普通写法和多态技术，设计实现俩个操作数进行运算的计算器类
/*多态的优点
* 1.代码组织结构清晰
* 2.可读性强
* 3.利于前期和后期的扩展以及维护
*/

//普通实现
class Calculator
{
public:
	int getResult(string str)
	{
		if (str == "+") {
			return num1 + num2;
		}
		else if (str == "-") {
			return num1 - num2;
		}
		else if (str == "*") {
			return num1 * num2;
		}
		//如果想扩展新的功能，则需要修改源码
		//在真实的开发者，提倡开闭原则
		//开闭原则：对扩展进行开发，对修改进行关闭
	}
	int num1;
	int num2;
};

void test_1()
{
	Calculator c;
	c.num1 = 2;
	c.num2 = 1;

}

//利用多态实现

//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int num1;
	int num2;
};

//实现加法计算器类
class add :public AbstractCalculator
{
	int getResult()
	{
		return num1 + num2;
	}
};

//实现减法计算器类
class sub :public AbstractCalculator
{
	int getResult()
	{
		return num1 - num2;
	}
};
//实现乘法计算器类
class mul :public AbstractCalculator
{
	int getResult()
	{
		return num1 * num2;
	}
};

void test_2()
{
	//多态使用条件
	//父类指针或者引用指向子类对象

	//实现加法
	AbstractCalculator* abc = new add;
	abc->num1 = 1;
	abc->num2 = 4;
	cout << "num1 + num2 = " << abc->getResult() << endl;
	//堆区数据，用完记得销毁
	delete abc;

	//实现减法
	sub s;
	*abc = s;
	abc->num1 = 1;
	abc->num2 = 9;
	cout << "num1 - num2 = " << abc->getResult() << endl;
	delete abc;
}


//纯虚函数和抽象类
/*多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
* 因此可以讲虚函数改为纯虚函数
* 语法：virtual 返回值类型 函数名 (参数列表) = 0;
* 当类中有了纯虚函数，这个类也称为抽象类
* 抽象类特点：
* 1.无法实例化对象
* 2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/
class base
{
public:
	//纯虚函数
	//只要有一个纯虚函数，这个类就叫抽象类
	virtual void func() = 0;
};

class son :public base
{
public:
	//子类必须重写父类中的纯虚函数，否者无法实例化对象
	virtual void func()
	{
		cout << "子类的重写" << endl;
	}
};


//多态案例--饮品制作流程
class AbstractDrinking
{
public:
	//煮水
	virtual void biol() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒入杯中
	virtual void pour() = 0;
	//加入辅料
	virtual void putin() = 0;
	//制作
	void makedring()
	{
		biol();
		brew();
		pour();
		putin();
	}
};

//制作咖啡
class coffee :public AbstractDrinking
{
public:
	//煮水
	virtual void biol()
	{
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯中
	virtual void pour()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void putin()
	{
		cout << "加糖和牛奶" << endl;
	}
};

//制作茶叶
class tea :public AbstractDrinking
{
	//煮水
	virtual void biol()
	{
		cout << "烧开水" << endl;
	}
	//冲泡
	virtual void brew()
	{
		cout << "泡茶" << endl;
	}
	//倒入杯中
	virtual void pour()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void putin()
	{
		cout << "加入辅料" << endl;
	}
};

//制作饮品
void dowork(AbstractDrinking* abs)
{
	abs->makedring();
	delete abs;
}

void makecoffee()
{
	dowork(new coffee);
	cout << "-----------" << endl;
	dowork(new tea);
}




int main()
{



	system("pause");
	return 0;
}