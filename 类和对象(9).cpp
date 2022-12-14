#include<iostream>
using namespace std;
#include<string>

/*虚析构和纯虚析构
* 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
* 解决方式--将父类中的析构函数改为虚析构或者纯虚析构
* 虚析构和纯虚析构共性：
* 1.可以解决父类指针释放子类对象
* 2.都需要具体的函数实现
* 虚析构和纯虚析构的区别：
* 1.如果是纯虚析构，该类属于抽象类，无法实例化对象
* 虚析构语法：virtual ~类名(){};
* 纯虚析构语法：virtual ~类名() = 0; 类名::~类名(){};
*/
class Animal
{
public:
	Animal()
	{
		cout << "Animal构造函数调用" << endl;
	}
	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal析构函数调用" << endl;
	}*/

	//纯虚析构--需要声明也需要实现
	//有了纯虚析构之后，这个类也属于抽象类
	virtual ~Animal() = 0;

	//纯虚函数
	virtual void speak() = 0;
};
Animal::~Animal()
{
	cout << "Animal纯析构函数调用" << endl;
}

class cat :public Animal
{
public:
	cat(string name)
	{
		cout << "cat构造函数调用" << endl;
		m_name = new string(name);
	}

	virtual void speak()
	{
		cout << "cat is speaking" << endl;
	}

	~cat()
	{
		cout << "cat析构函数调用" << endl;
		if (m_name != NULL)
		{
			delete m_name;
		}
	}
	string* m_name;
};

void test01()
{
	Animal* animal = new cat("tom");
	animal->speak();
	//父类指针在析构的时候，不会调用子类中的析构函数，导致子类如果有堆区属性，会出现内存泄露
	delete animal;
}



//多态案例三-电脑组装

//抽象的cpu类
class CPU
{
public:
	//抽象的计算函数
	virtual void caculate() = 0;
};

//抽象的显卡类
class navi
{
public:
	virtual void dispaly() = 0;
};

//抽象内存条类
class Memory
{
public:
	virtual void storage() = 0;
};

//电脑类
class computer
{
public:
	computer(CPU* cpu, navi* na, Memory* men)
	{
		this->cpu = cpu;
		this->mem = mem;
		this->na = na;
	}
	void work()
	{
		cpu->caculate();
		na->dispaly();
		mem->storage();
	}
	~computer()
	{
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (na != NULL)
		{
			delete na;
			na = NULL;
		}
		if (mem != NULL) {
			delete mem;
			mem = NULL;
		}
	}

private:
	CPU* cpu;
	navi* na;
	Memory* mem;
};

//具体厂商
//Intel
class intelCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Intel的CPU开始计算了" << endl;
	}
};

class Intelnavi :public navi
{
public:
	virtual void dispaly()
	{
		cout << "Intel的显卡" << endl;
	}
};

class IntelMem :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的储存" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Lenovo的CPU开始计算了" << endl;
	}
};

class Lenovonavi :public navi
{
public:
	virtual void dispaly()
	{
		cout << "Lenovo的显卡" << endl;
	}
};

class LenovoMem :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的储存" << endl;
	}
};

void test01()
{
	//第一台电脑的零件
	CPU* intelcpu = new intelCPU;
	navi* intelcard = new Intelnavi;
	Memory* intelmem = new IntelMem;

	//创建第一台电脑
	computer* computer1 = new computer(intelcpu,intelcard,intelmem);
	computer1->work();
	delete computer1;
	cout << "--------" << endl;
	//创建第二台电脑
	computer* computer2 = new computer(new LenovoCPU, new Lenovonavi, new LenovoMem);
	computer2->work();
	delete computer2;

}
int main()
{
	test01();



	system("pause");
	return 0;
}